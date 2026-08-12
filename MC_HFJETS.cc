//MC_HFJETS
//Monte Carlo validation analysis to study heavy flavour production
//Run any events which will produce jets above 20 GeV. Of most interest for processes where c and b hadrons can be produced (either hard or soft) of course!
//Plots to study fragmentation of heavy flavour hadrons in jets.
//a quanto dice Matilde, sia questo che MC_HFDECAYS hanno distribuzioni utili come b fragmentation function e jet shapes

// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/UnstableParticles.hh"
#include "Rivet/Projections/PrimaryHadrons.hh"
#include "Rivet/Projections/HeavyHadrons.hh"
#include <iostream> //questi due mi servono per fare i quadrati
#include <cmath>

namespace Rivet {


  class MC_HFJETS : public Analysis {
  public:

    // Constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(MC_HFJETS);


    /// Book histograms and initialise projections before the run
    void init() {

      // set clustering radius from input option
      const double R = getOption<double>("R", 0.4);

      // set clustering algorithm from input option
      JetAlg clusterAlgo;
      const string algoopt = getOption("ALGO", "ANTIKT");
      if ( algoopt == "KT" ) {
    clusterAlgo = JetAlg::KT;
      } else if ( algoopt == "CA" ) {
    clusterAlgo = JetAlg::CA;
      } else if ( algoopt == "ANTIKT" ) {
    clusterAlgo = JetAlg::ANTIKT;
      } else {
    MSG_WARNING("Unknown jet clustering algorithm option " + algoopt + ". Defaulting to anti-kT");
    clusterAlgo = JetAlg::ANTIKT;
      }
      
      FastJets fj(FinalState(Cuts::abseta < 5), clusterAlgo, R);
      fj.useInvisibles();
      declare(fj, "Jets");
      declare(HeavyHadrons(Cuts::abseta < 5 && Cuts::pT > 500*MeV), "BCHadrons");

      book(_h_ptCJetLead ,"ptCJetLead", linspace(5, 0, 20, false) + logspace(25, 20, 200));
      book(_h_ptCHadrLead ,"ptCHadrLead", linspace(5, 0, 10, false) + logspace(25, 10, 200));
      book(_h_ptFracC ,"ptfracC", 50, 0, 1.5);
      book(_h_eFracC ,"efracC", 50, 0, 1.5);

      book(_h_ptBJetLead ,"ptBJetLead", linspace(5, 0, 20, false) + logspace(25, 20, 200));
      book(_h_ptBHadrLead ,"ptBHadrLead", linspace(5, 0, 10, false) + logspace(25, 10, 200));
      book(_h_ptFracB ,"ptfracB", 50, 0, 1.5);
      book(_h_eFracB ,"efracB", 50, 0, 1.5);
        // BLOCCO AGGIUNTO DA ME 
      for (size_t d = 0; d < 5; ++d) {
        book(_p_b_rho[d], d + 1, 1, 1);
        book(_p_Wjets_rho[d], d + 1, 2, 1);
        book(_p_b_Psi[d], d + 1, 1, 2);
        book(_p_Wjets_Psi[d], d + 1, 2, 2);
    }
    } //ok fin qui dovremmo essere a posto con le parentesi


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // Get jets and heavy hadrons
      const Jets& jets = apply<JetFinder>(event, "Jets").jetsByPt();
      const Particles bhadrons = sortByPt(apply<HeavyHadrons>(event, "BCHadrons").bHadrons());
      const Particles chadrons = sortByPt(apply<HeavyHadrons>(event, "BCHadrons").cHadrons());
      MSG_DEBUG("# b hadrons = " << bhadrons.size() << ", # c hadrons = " << chadrons.size());

      // Loop over jets and use ghost-tag info
      for (const Jet& j : jets) {
        bool gotLeadingB = false, gotLeadingC = false;
        // b-tag testing
        if (!gotLeadingB && j.bTagged(Cuts::pT > 500*MeV)) {
          gotLeadingB = true;
          Particle bhad = sortByPt(j.bTags(Cuts::pT > 500*MeV))[0];
          _h_ptBJetLead->fill(j.pT()/GeV);
          _h_ptBHadrLead->fill(bhad.pT()/GeV);
          _h_ptFracB->fill(bhad.pT() / j.pT());
          _h_eFracB->fill(bhad.E() / j.E());
          continue;
        }
        // c-tag testing
        if (!gotLeadingC && j.cTagged(Cuts::pT > 500*MeV) && !j.bTagged(Cuts::pT > 500*MeV)) {
          gotLeadingC = true;
          Particle chad = sortByPt(j.cTags(Cuts::pT > 500*MeV))[0];
          _h_ptCJetLead->fill(j.pT()/GeV);
          _h_ptCHadrLead->fill(chad.pT()/GeV);
          _h_ptFracC->fill(chad.pT() / j.pT());
          _h_eFracC->fill(chad.E() / j.E());
        }
        // Escape early if we've found both the leading b and c jets
        if (gotLeadingB && gotLeadingC) break;
      }
    
    
    //qui inizia il blocco aggiunto da me
    //io ho bisogno delle liste di jet per calcolare poi il chiquadro ecc, quindi devo dichiarare b_jets, c_jets, light_jets e W_jet.\\
    //anzi, b_jets era già dichiarato nel pezzo di codice che ho copiato quindi me lo tengo. 
    //	QUESTO PEZZO DI ROUTINE è PRESO E RIADATTATO DA ATLAS_2013_I1243871
    
    /// Get the various sets of final state particles
      const Particles& elecFS = apply<IdentifiedFinalState>(event, "ELEC_FS").particlesByPt();
      const Particles& muonFS = apply<IdentifiedFinalState>(event, "MUON_FS").particlesByPt();

      // Get all jets with pT > 7 GeV (ATLAS standard jet collection)
      /// @todo Why rewrite the jets collection as a vector of pointers?
      const Jets& jets = apply<FastJets>(event, "JETS").jetsByPt(Cuts::pT > 7 * GeV);
      vector<const Jet*> allJets;
      for (const Jet& j : jets) allJets.push_back(&j);

      // Keep any jets that pass the pt cut
      vector<const Jet*> pt_jets;
      for (const Jet* j : allJets) {
        /// @todo Use direct kinematics access
        const double pt = j->momentum().pT();
        const double eta = j->momentum().eta();
        if (pt > 25 * GeV && fabs(eta) < 2.5) pt_jets.push_back(j);
      }

      // Remove jets too close to an electron
      vector<const Jet*> good_jets;
      for (const Jet* j : pt_jets) {
        bool isElectron = 0;
        for (const Particle& e : elecFS) {
          const double elec_jet_dR = deltaR(e.momentum(), j->momentum());
          if (elec_jet_dR < 0.2) {
            isElectron = true;
            break;
          }
        }
        if (!isElectron) good_jets.push_back(j);
      }

      // Classify the event type
      const size_t nElec = elecFS.size();
      const size_t nMuon = muonFS.size();
      bool isSemilepton = false, isDilepton = false;
      if (nElec == 1 && nMuon == 0) {
        isSemilepton = true;
      }
      else if (nElec == 0 && nMuon == 1) {
        isSemilepton = true;
      }
      else if (nElec == 2 && nMuon == 0) {
        if (charge(elecFS[0]) != charge(elecFS[1])) isDilepton = true;
      }
      else if (nElec == 1 && nMuon == 1) {
        if (charge(elecFS[0]) != charge(muonFS[0])) isDilepton = true;
      }
      else if (nElec == 0 && nMuon == 2) {
        if (charge(muonFS[0]) != charge(muonFS[1])) isDilepton = true;
      }
      const bool isGoodEvent = (isSemilepton && good_jets.size() >= 4)
          || (isDilepton && good_jets.size() >= 2);
      if (!isGoodEvent) vetoEvent;


      // Select b-hadrons
      /// @todo Use built-in identification on Particle, avoid HepMC
      vector<ConstGenParticlePtr> b_hadrons;
      vector<ConstGenParticlePtr> allParticles = HepMCUtils::particles(event.genEvent());
      for (size_t i = 0; i < allParticles.size(); i++) {
        ConstGenParticlePtr p = allParticles.at(i);
        if (!(PID::isHadron(p->pdg_id()) && PID::hasBottom(p->pdg_id()))) continue;
        if (p->momentum().perp() < 5 * GeV) continue;
        b_hadrons.push_back(p);
      }

      // Select b-jets as those containing a b-hadron
      /// @todo Use built-in dR < 0.3 Jet tagging, avoid HepMC
      vector<const Jet*> b_jets;
      for (const Jet* j : good_jets) {
        bool isbJet = false;
        for (ConstGenParticlePtr b : b_hadrons) {
          /// @todo Use direct momentum accessor / delta functions
          const FourMomentum hadron = b->momentum();
          const double hadron_jet_dR = deltaR(j->momentum(), hadron);
          if (hadron_jet_dR < 0.3) {
            isbJet = true;
            break;
          }
        }
        // Check if it is overlapped to any other jet
        bool isOverlapped = false;
        for (const Jet* k : allJets) {
          if (j == k) continue;
          double dRjj = deltaR(j->momentum(), k->momentum());
          if (dRjj < 0.8) {
            isOverlapped = true;
            break;
          }
        }
        if (isbJet && !isOverlapped) b_jets.push_back(j);
      }
      MSG_DEBUG(b_jets.size() << " b-jets selected");

      //QUI DICHIARO I LIGHT JETS E I C-JETS
      Jets c_jets, l_jets;
for (const Jet& jet : good_jets) {
    if (jet.cTagged())
        c_jets += jet;
    else if (!jet.cTagged() && !jet.bTagged)  //o dovrei costruire c_jets così come viene costruito b_jets cioè con c-hadron eccetera? boh intanto provo così
        l_jets += jet;
}


      // Select light-jets as the pair of non-b-jets with invariant mass closest to the W mass
     //IO INVECE VOGLIO TUTTI I JET PROVENIENTI DAL W. QUINDI RINOMINO W_JETS QUELLO CHE ERA LIGHT_JETS 
      /// @todo Use built-in b-tagging (dR < 0.3 defn), avoid HepMC
      const double nominalW = 80.4 * GeV;
      const double nominalTop = 172.5 * GeV; //aggiunto da me - verificare che il dataset montecralo che sto usando abbia questo come input per la massa nominale del top.
      double deltaM = 500 * GeV; //valore che di volta in volta si aggiorna per trovare la coppia di jet la cui massa invariante è la più vicina a quella del W
      double deltaMass = 500 * GeV; //stessa cosa ma aggiunta da me così il ciclo non rischio che vada in trip
      const Jet* jet1 = NULL;
      const Jet* jet2 = NULL; // NB: const Jets, not const pointers!
      const Jet* jet3 = NULL; //aggiunto da me nel caso in cui ci sia anche un jet da radiazione gluonica del b
      for (const Jet* i : good_jets) {
        bool isbJet1 = false;
        for (ConstGenParticlePtr b : b_hadrons) {
          /// @todo Use direct momentum accessor / delta functions
          const FourMomentum hadron = b->momentum();
          const double hadron_jet_dR = deltaR(i->momentum(), hadron);
          if (hadron_jet_dR < 0.3) {
            isbJet1 = true;
            break;
          }
        }
        if (isbJet1) continue;
        for (const Jet* j : good_jets) {
          bool isbJet2 = false;
          for (ConstGenParticlePtr b : b_hadrons) {
            FourMomentum hadron = b->momentum();
            double hadron_jet_dR = deltaR(j->momentum(), hadron);
            if (hadron_jet_dR < 0.3) {
              isbJet2 = true;
              break;
            }
          }
          if (isbJet2) continue;
          //BLOCCO AGGIUNTO DA ME PER IL TERZO JET
            for (const Jet* z : good_jets) {
          bool isbJet3 = false;
          for (ConstGenParticlePtr b : b_hadrons) {
            FourMomentum hadron = b->momentum();
            double hadron_jet_dR = deltaR(j->momentum(), hadron);
            if (hadron_jet_dR < 0.3) {
              isbJet3 = true;
              break;
            }
          }
          if (isbJet3) continue;
       //fine blocco
           
	  double invMass_Wcand; //= (i->momentum() + j->momentum()).mass();
	  double invMass_Tcand; //inizialilzzo m^2(top_reco)
	  double chi2 = 500; //inizializzo il chi2
	  const double sigmaT = 35 * GeV;
	  const double sigmaW = 25 * GeV;
	  for (const Jet* bjet : b_jets) {  //il fatto che ci siano due bjets per evento e quindi il doppio di tutto mi complica le cose o no?
	  //io ho solo sample dilepton o singlelepton per ora, 
	  //quindi l'unico rilevante per questa analisi è il singlelepton, 
	  //in cui un W su due decade adronicamente. Quindi in effetti è 
	  //solo una (e non due) la possibile coppia di jet con massa invariante 	  //circa pari a quella del W. Se avessi invece un sample allhadronic 
	  //(o proprio all tutto cioè singlelep + dilep + allhad) sarebbe
	  //chiaramente una storia diversa e potrei aver in alcuni casi due
	  // coppie di jet che vengono da un W. 
	  // Mi viene da pensare di dover ciclare anche sui b-jets così da 
	  // poter identificare i jet da radiazione gluonica del b. 
	  // magari sto a fa na cosa inutile, magari no.   
	   // for (const Jet* cjet : c_jets) {
	     
           invMass_Wcand = (i->momentum() + j->momentum()).mass();
	   invMass_Tcand = (bjet->momentum() + z->momentum() + i->momentum() + j->momentum()).mass();   //controllare se è concettualmente corretto 
	   double chi2_cand = std::pow((invMass_Tcand - nominalTop),2)/std::pow(sigmaT,2) + std::pow((invMass_Wcand - nominalW),2)/std::pow(sigmaW,2); 
	   if( chi2_cand < chi2) {
		  chi2 = chi2_cand;
	   // if (fabs(invMass_Wcand - nominalW) < deltaM) {
           // deltaM = fabs(invMass_Wcand - nominalW);
            jet1 = i; //W_jets
            jet2 = j; //W_jets
	    jet3 = z; //light_jet dovuto realisticamente a radiazione gluonica dal bottom
          }
        }
      }
	  }	  //le parentesi chiaramente saranno sbagliate but still 

      // Check that both jets are not overlapped, and populate the W jets list
      vector<const Jet*> W_jets;
      const bool hasGoodWJet = jet1 != NULL && jet2 != NULL && jet1 != jet2;
      if (hasGoodWJet) {
        bool isOverlap1 = false, isOverlap2 = false;
        for (const Jet* j : allJets) {
          if (jet1 == j) continue;
          const double dR1j = deltaR(jet1->momentum(), j->momentum());
          if (dR1j < 0.8) {
            isOverlap1 = true;
            break;
          }
        }
        for (const Jet* j : allJets) {
          if (jet2 == j) continue;
          const double dR2j = deltaR(jet2->momentum(), j->momentum());
          if (dR2j < 0.8) {
            isOverlap2 = true;
            break;
          }
        }
        if (!isOverlap1 && !isOverlap2) {
          W_jets.push_back(jet1);
          W_jets.push_back(jet2);
        }
      }
      MSG_DEBUG(W_jets.size() << " W jets selected");


      // Calculate the jet shapes
      /// @todo Use C++11 vector/array initialization
      const double binWidth = 0.04; // -> 10 bins from 0.0-0.4
      vector<double> ptEdges;
      ptEdges += {{30, 40, 50, 70, 100, 150}};

      // b-jet shapes
      MSG_DEBUG("Filling b-jet shapes");
      for (const Jet* bJet : b_jets) {
        // Work out jet pT bin and skip this jet if out of range
        const double jetPt = bJet->momentum().pT();
        MSG_DEBUG("Jet pT = " << jetPt / GeV << " GeV");
        if (!inRange(jetPt / GeV, 30., 150.)) continue;
        /// @todo Use YODA bin index lookup tools
        size_t ipt;
        for (ipt = 0; ipt < 5; ++ipt)
          if (inRange(jetPt / GeV, ptEdges[ipt], ptEdges[ipt + 1])) break;
        MSG_DEBUG("Jet pT index = " << ipt);

        // Calculate jet shape
        vector<double> rings(10, 0);
        for (const Particle& p : bJet->particles()) {
          const double dR = deltaR(bJet->momentum(), p.momentum());
          const size_t idR = (size_t)floor(dR / binWidth);
          for (size_t i = idR; i < 10; ++i) rings[i] += p.pT();
        }

        // Fill each dR bin of the histos for this jet pT
        for (int iBin = 0; iBin < 10; ++iBin) {
          const double rcenter = 0.02 + iBin * binWidth;
          const double rhoval = (iBin != 0 ? (rings[iBin] - rings[iBin - 1]) : rings[iBin]) / binWidth
              / rings[9];
          const double psival = rings[iBin] / rings[9];
          MSG_DEBUG(rcenter << ", " << rhoval << ", " << psival);
          _p_b_rho[ipt]->fill(rcenter, rhoval);
          _p_b_Psi[ipt]->fill(rcenter, psival);
        }
      }

      // W jet shapes
      MSG_DEBUG("Filling W jet shapes");
      for (const Jet* WJet : W_jets) {
        // Work out jet pT bin and skip this jet if out of range
        const double jetPt = WJet->momentum().pT();
        MSG_DEBUG("Jet pT = " << jetPt / GeV << " GeV");
        if (!inRange(jetPt / GeV, 30., 150.)) continue;
        /// @todo Use YODA bin index lookup tools
        size_t ipt;
        for (ipt = 0; ipt < 5; ++ipt)
          if (inRange(jetPt / GeV, ptEdges[ipt], ptEdges[ipt + 1])) break;
        MSG_DEBUG("Jet pT index = " << ipt);

        // Calculate jet shape
        vector<double> rings(10, 0);
        for (const Particle& p : WJet->particles()) {
          const double dR = deltaR(WJet->momentum(), p.momentum());
          const size_t idR = (size_t)floor(dR / binWidth);
          for (size_t i = idR; i < 10; ++i) rings[i] += p.pT();
        }

        // Fill each dR bin of the histos for this jet pT
        for (int iBin = 0; iBin < 10; ++iBin) {
          const double rcenter = 0.02 + iBin * binWidth;
          const double rhoval = (iBin != 0 ? (rings[iBin] - rings[iBin - 1]) : rings[iBin]) / binWidth
              / rings[9];
          const double psival = rings[iBin] / rings[9];
          _p_Wjets_rho[ipt]->fill(rcenter, rhoval);
          _p_Wjets_Psi[ipt]->fill(rcenter, psival);
        }
      
	//FINE DEL BLOCCO AGGIUNTO DA ME 
      }
    /// Normalise histograms etc., after the run
    void finalize() {
      normalize({_h_ptCJetLead, _h_ptCHadrLead, _h_ptBJetLead, _h_ptBHadrLead,
            _h_ptFracC, _h_eFracC, _h_ptFracB, _h_eFracB, _h_p_Wjets_rho, _h_p_Wjets_Psi, _h_p_b_rho, _h_p_b_Psi});
    }


    /// @name Histograms
    /// @{
    Histo1DPtr _h_ptCJetLead, _h_ptCHadrLead, _h_ptFracC, _h_eFracC;
    Histo1DPtr _h_ptBJetLead, _h_ptBHadrLead, _h_ptFracB, _h_eFracB;
    Profile1DPtr _p_b_rho[5];//inizio aggiunta mia
    Profile1DPtr _p_Wjets_rho[5];
    Profile1DPtr _p_b_Psi[5];
    Profile1DPtr _p_Wjets_Psi[5];//fine aggiunta mia  
    /// @}


  };

	    

  RIVET_DECLARE_PLUGIN(MC_HFJETS);

}
