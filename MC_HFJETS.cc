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
#include "Rivet/Projections/IdentifiedFinalState.hh" //questo serve per elettroni e muoni
#include <iostream> //questi due mi servono per fare i quadrati
#include <cmath>
#include <limits> //serve per inizializzare il chi2 a infinito
#include <sstream> //serve per il ciclo in cui do un titolo agli istogrammi di rho e psi

namespace Rivet {


  class MC_HFJETS_MOD : public Analysis {
  public:

    // Constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(MC_HFJETS_MOD);


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
      
      FastJets fj(FinalState(Cuts::abseta < 2.5), clusterAlgo, R);
      fj.useInvisibles();
      declare(fj, "Jets");
      declare(HeavyHadrons(Cuts::abseta < 2.5 && Cuts::pT > 500*MeV), "BCHadrons");
      
      //blocco aggiunto:
       /// Get electrons from truth record
      IdentifiedFinalState elec_fs(Cuts::abseta < 2.5 && Cuts::pT > 25 * GeV);
      elec_fs.acceptIdPair(PID::ELECTRON);
      declare(elec_fs, "ELEC_FS");

      /// Get muons which pass the initial kinematic cuts:
      IdentifiedFinalState muon_fs(Cuts::abseta < 2.5 && Cuts::pT > 20 * GeV);
      muon_fs.acceptIdPair(PID::MUON);
      declare(muon_fs, "MUON_FS");
      //fine blocco aggiunto
      
      book(_h_pT_muon, "pT_muon", linspace(5, 0, 20, false) + logspace(25, 20, 200));
     // _h_pT_muon->setTitle("pT distribution of muons");
     // _h_pT_muon->setAnnotation("XLabel", "pT_{#mu} [GeV]");
     // _h_pT_muon->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");
      
      book(_h_pT_electron, "pT_electron", linspace(5, 0, 20, false) + logspace(25, 20, 200));
     // _h_pT_electron->setTitle("pT distribution of electrons");
     // _h_pT_electron->setAnnotation("XLabel", "pT_{e} [GeV]");
     // _h_pT_electron->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");

      book(_h_pT_lepton, "pT_lepton", linspace(5, 0, 20, false) + logspace(25, 20, 200)); 
     // _h_pT_lepton->setTitle("pT distribution of leptons");
     // _h_pT_lepton->setAnnotation("XLabel", "pT_{l} [GeV]");
     // _h_pT_lepton->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");
     
      book(_h_ptCJetLead ,"ptCJetLead", linspace(5, 0, 20, false) + logspace(25, 20, 200));
     // _h_ptCJetLead->setTitle("pT distribution of the leading c-jet");
     // _h_ptCJetLead->setAnnotation("XLabel", "pT of the lead. c-jet [GeV]");
     // _h_ptCJetLead->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");

      book(_h_ptCHadrLead ,"ptCHadrLead", linspace(5, 0, 10, false) + logspace(25, 10, 200));
     // _h_ptCHadrLead->setTitle("pT distribution of the leading c-hadron");
     // _h_ptCHadrLead->setAnnotation("XLabel", "pT of the lead. c-hadron [GeV]");
     // _h_ptCHadrLead->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");

      book(_h_ptFracC ,"ptfracC", 50, 0, 1.5);
     // _h_ptFracC->setTitle("pT_{c-hadron}/pT_{c-jet} distribution");
     // _h_ptFracC->setAnnotation("XLabel", "pT_{c-had}/pT_{c-jet}");
      //_h_ptFracC->setAnnotation("YLabel", "1/N{ev}");
      
      book(_h_eFracC ,"efracC", 50, 0, 1.5);
     // _h_eFracC->setTitle("E_{c-hadron}/E_{c-jet} distribution");
     // _h_eFracC->setAnnotation("XLabel", "E_{c-had}/E_{c-jet}");
      //_h_eFracC->setAnnotation("YLabel", "1/N{ev}");

      book(_h_ptBJetLead ,"ptBJetLead", linspace(5, 0, 20, false) + logspace(25, 20, 200));
     // _h_ptBJetLead->setTitle("pT distribution of the leading b-jet");
     // _h_ptBJetLead->setAnnotation("XLabel", "pT of the lead. b-jet [GeV]");
     // _h_ptBJetLead->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");

      book(_h_ptBHadrLead ,"ptBHadrLead", linspace(5, 0, 10, false) + logspace(25, 10, 200));
     // _h_ptBHadrLead->setTitle("pT distribution of the leading b-hadron");
     // _h_ptBHadrLead->setAnnotation("XLabel", "pT of the lead. b-hadron [GeV]");
     // _h_ptBHadrLead->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");

      book(_h_ptFracB ,"ptfracB", 50, 0, 1.5);
     // _h_ptFracB->setTitle("pT_{b-hadron}/pT_{b-jet} distribution");
     // _h_ptFracB->setAnnotation("XLabel", "pT_{b-had}/pT_{b-jet}");
      //_h_ptFracB->setAnnotation("YLabel", "1/N{ev}");

      book(_h_eFracB ,"efracB", 50, 0, 1.5);
     // _h_eFracB->setTitle("E_{b-hadron}/E_{b-jet} distribution");
     // _h_eFracB->setAnnotation("XLabel", "E_{b-had}/E_{b-jet}");
      //_h_eFracB->setAnnotation("YLabel", "1/N{ev}");
      
      vector<double> ptEdges;
      ptEdges += {{30, 40, 50, 70, 100, 150}};
      
       for (size_t d = 0; d < 5; ++d) {
          book(_p_b_rho[d], "b_rho_" + to_string(d), 10, 0., 0.4);
          book(_p_Wjets_rho[d], "Wjets_rho_" + to_string(d), 10, 0., 0.4);
          book(_p_b_Psi[d], "b_Psi_" + to_string(d), 10, 0., 0.4);
          book(_p_Wjets_Psi[d], "Wjets_Psi_" + to_string(d), 10, 0., 0.4);
	  
       //   std::ostringstream title1;
       //   title1 << "Differential jet shape of b-jets with " 
       //   << ptEdges[d] << " < p_{T}^{b-jet} < "
       //   << ptEdges[d+1] << " GeV";
       //   _p_b_rho[d]->setTitle(title1.str());
       //	  _p_b_rho[d]->setAnnotation("XLabel", "#rho_{b-jet}");
	  //_p_b_rho[d]->setAnnotation("YLabel", "1/N_{ev}");
	  
	//  std::ostringstream title2;
	//  title2 << "Differential jet shape of W-jets with "
        //  << ptEdges[d] << " < p_{T}^{W-jet} < "
	//  << ptEdges[d+1] << " GeV";
	//  _p_Wjets_rho[d]->setTitle(title2.str());
	//  _p_Wjets_rho[d]->setAnnotation("XLabel", "#rho_{W-jet}");
	 // _p_Wjets_rho[d]->setAnnotation("YLabel", "1/N_{ev}");
	 
        //  std::ostringstream title3;
        //  title3 << "Integrated jet shape of b-jets with "
        //  << ptEdges[d] << " < p_{T}^{b-jet} < "
        //  << ptEdges[d+1] << " GeV";
        //  _p_b_Psi[d]->setTitle(title3.str());
        //  _p_b_Psi[d]->setAnnotation("XLabel", "#Psi_{b-jet}");
          //_p_b_Psi[d]->setAnnotation("YLabel", "1/N_{ev}");

        //  std::ostringstream title4;
        //  title4 << "Integrated jet shape of W-jets with "
        //  << ptEdges[d] << " < p_{T}^{W-jet} < "
        //  << ptEdges[d+1] << " GeV";
        //  _p_Wjets_Psi[d]->setTitle(title4.str());
        //  _p_Wjets_Psi[d]->setAnnotation("XLabel", "#Psi_{W-jet}");
         // _p_Wjets_Psi[d]->setAnnotation("YLabel", "1/N_{ev}");

    }

      book(_h_bar_Wjets_width, "width_Wjets", 7, 0., 0.3);
   //   _h_bar_Wjets_width->setTitle("Width of the jets coming from W decay");
    //  _h_bar_Wjets_width->setAnnotation("XLabel", "width");
      //_h_bar_Wjets_width->setAnnotation("YLabel", "1/N_{ev}");
      
      book(_h_Wjets_ch_mult, "charged_mult_Wjets", 40, 0.5, 40.5);
    //  _h_Wjets_ch_mult->setTitle("Charged multiplicity of jets coming from W boson decay");
    //  _h_Wjets_ch_mult->setAnnotation("XLabel", "N. of charged particles");
      //_h_Wjets_ch_mult->setAnnotation("YLabel", "1/N_{ev}");
      
      book(_h_Wjets_pT, "pT_Wjets", 25, 7., 700.);
    //  _h_Wjets_pT->setTitle("pT distribution of the jets coming from W decay");
    //  _h_Wjets_pT->setAnnotation("XLabel", "pT_{Wjet}");
     // _h_Wjets_pT->setAnnotation("YLabel", "d#sigma/dpT [pb GeV^{-1}]");

      book(_h_W_chi2, "W_chi2", 50, 0., 4.0); //aggiunto il 31 agosto
    //  _h_W_chi2->setTitle("Hadronic W candidate #chi^{2}");
    //  _h_W_chi2->setAnnotation("XLabel", "#chi^{2}_{W}");
     // _h_W_chi2->setAnnotation("YLabel", "1/N_{ev} dN/d#chi^{2}_{W}");
      
      book(_h_W_Wjets_dR, "W_Wjets_dR", 20, 0.0, 7.0);
    //  _h_W_Wjets_dR->setTitle("dR between W and a jet originated by W decay");
    //  _h_W_Wjets_dR->setAnnotation("XLabel", "dR between W and W-originated jet");
     // _h_W_Wjets_dR->setannotation("YLabel", "1/N_{ev}");
      
      book(_h_W_Wjets_deta, "W_Wjets_deta", 20, 0.0, 7.0);
    //  _h_W_Wjets_deta->setTitle("d#eta between W and a jet originated by W decay");
    //  _h_W_Wjets_deta->setAnnotation("XLabel", "d#eta between W and W-originated jet");
     // _h_W_Wjets_deta->setannotation("YLabel", "1/N_{ev}");

      book(_h_W_Wjets_dphi, "W_Wjets_dphi", 20, 0.0, M_PI);
    //  _h_W_Wjets_dphi->setTitle("d#phi between W and a jet originated by W decay");
    //  _h_W_Wjets_dphi->setAnnotation("XLabel", "d#phi between W and W-originated jet");
     // _h_W_Wjets_dphi->setannotation("YLabel", "1/N_{ev}");

      book(_h_bjet_mass, "bjet_mass", 50, 1.5, 8.5);
    //  _h_bjet_mass->setTitle("Invariant mass of a b-jet");
    //  _h_bjet_mass->setAnnotation("XLabel", "bjet mass [GeV]");
      //_h_bjet_mass->setAnnotation("YLabel", "1/N_{ev}");

      book(_h_lcjet_mass, "lcjet_mass", 50, 0.1, 3.5); //boh non so
    //  _h_lcjet_mass->setTitle("Invariant mass of a light or c-jet");
    //  _h_lcjet_mass->setAnnotation("XLabel", "light/c-jet mass [GeV]"); 
      //_h_lcjet_mass->setAnnotation("YLabel", "1/N_{ev}");

      book(_h_W_pT, "W_pT", logspace(50, 5.0, 650.0)); //questo e 
      //sqguente istogramma sono già presenti in TTBAR, ma voglio vedere se 
      //identificanod il W in questo modo (con questi tagli ecc) cambia qualcosa
    //  _h_W_pT->setTitle("pT distribution for the W boson");
    //  _h_W_pT->setAnnotation("XLabel", "pT_{W} [GeV]");
     // _h_W_pT->setAnnotation("YLabel", "d#sigma/dpT_{W} [pb GeV^{-1}]");

      book(_h_W_mass, "W_mass", 75, 30, 180);
  //    _h_W_mass->setTitle("Mass distribution of the W boson");
   //   _h_W_mass->setAnnotation("XLabel", "m_{W} [GeV]");
   //   _h_W_mass->setAnnotation("YLabel", "d#sigma/dm_{W} [pb GeV^{-1}]");
      //fine blocco aggiunto il 31 agosto

    } //ok fin qui dovremmo essere a posto con le parentesi


    //blocco necessario perché deltaR() così com'è richiede due rivet::fourmomentum
// mentre constgenparticleptr è un hepmc3 qualcosa quindi deltaR non
// capisce. Questo blocco serve per convertire hepmc3 e creare direttamente
// un deltaR che funzioni a dovere.
// Devo metterlo qui tra init() e analize() perché è la definzione di una funzione, e c++ non mi consente di definire una funzione dentro analize() (che a sua volta è un void {} quindi una funzione esso stesso mi sa)
double deltaRJetGen(const Jet& jet,
                   ConstGenParticlePtr p) const {

    const FourMomentum pmom(
        p->momentum().px(),
        p->momentum().py(),
        p->momentum().pz(),
        p->momentum().e()
    );

    return deltaR(jet.momentum(), pmom);
}

    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // Get jets and heavy hadrons
    //  const Jets& jets = apply<JetFinder>(event, "Jets").jetsByPt();
     const Jets& jets = apply<FastJets>(event, "Jets").jetsByPt(Cuts::pT > 7 * GeV);  //aggiunto il requisito sul pt minimo.
	    const Particles bhadrons = sortByPt(apply<HeavyHadrons>(event, "BCHadrons").bHadrons());
      const Particles chadrons = sortByPt(apply<HeavyHadrons>(event, "BCHadrons").cHadrons());
      MSG_DEBUG("# b hadrons = " << bhadrons.size() << ", # c hadrons = " << chadrons.size());
      //
        /// Get the various sets of final state particles
      const Particles& elecFS = apply<IdentifiedFinalState>(event, "ELEC_FS").particlesByPt();
      const Particles& muonFS = apply<IdentifiedFinalState>(event, "MUON_FS").particlesByPt();
      const size_t nElec = elecFS.size();
      const size_t nMuon = muonFS.size();
      //aggiungo qui il riempimento degli istogrammi relativi al pt dei leptoni:
      for (size_t i = 0; i < nMuon; i++) {
      _h_pT_muon->fill(muonFS[i].pT()/GeV);
      _h_pT_lepton->fill(muonFS[i].pT()/GeV);}
      for (size_t i = 0; i < nElec; i++) {
      _h_pT_lepton->fill(elecFS[i].pT()/GeV);
      _h_pT_electron->fill(elecFS[i].pT()/GeV);}
      //fine riempimento istogrammi pt leptoni
      //
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
    //io ho bisogno delle liste di jet per calcolare poi il chiquadro ecc,
    //quindi devo dichiarare b_jets, c_jets, light_jets e W_jet.\\
    //anzi, b_jets era già dichiarato nel pezzo di codice che ho copiato 
    //quindi me lo tengo. 
    //	QUESTO PEZZO DI ROUTINE è PRESO E RIADATTATO DA ATLAS_2013_I1243871
    
      // Get all jets with pT > 7 GeV (ATLAS standard jet collection)
      /// @todo Why rewrite the jets collection as a vector of pointers?
       //const Jets& fastjets = apply<FastJets>(event, "JETS").jetsByPt(Cuts::pT > 7 * GeV); 
       // //questo lo silenzio perché jets era già stato dichiarato a riga 75 ma senza il requisito sul pt minimo. Metto quindi a riga 75 il requisito del pt minimo e mi tengo jets come nome. 
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

      // Select c-hadrons
      /// @todo Use built-in identification on Particle, avoid HepMC
      vector<ConstGenParticlePtr> c_hadrons;
  //silenzio perché gia dichiarato a riga 210  //  vector<ConstGenParticlePtr> allParticles = HepMCUtils::particles(event.genEvent());
      for (size_t i = 0; i < allParticles.size(); i++) {
        ConstGenParticlePtr p = allParticles.at(i);
        if (!(PID::isHadron(p->pdg_id()) && PID::hasCharm(p->pdg_id()))) continue;
        if (p->momentum().perp() < 5 * GeV) continue;
        c_hadrons.push_back(p);
      }


      // Select b-jets as those containing a b-hadron
      /// @todo Use built-in dR < 0.3 Jet tagging, avoid HepMC
      vector<const Jet*> b_jets;
      vector<const Jet*> c_jets;
      vector<const Jet*> light_jets;
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
      //ora riempio c_jets e light_jets:
      for (const Jet* j : good_jets) {
	      bool isBJet = false;
              bool isCJet = false;

for (ConstGenParticlePtr b : b_hadrons) {
    if (deltaRJetGen(*j, b) < 0.3) {
        isBJet = true;
        break;
    }
}

if (!isBJet) {
    for (ConstGenParticlePtr c : c_hadrons) {
        if (deltaRJetGen(*j, c) < 0.3) {
            isCJet = true;
            break;
        }
    }
}

//if (isBJet)  //lo silenzio e faccio diventare if quello 
//che era else if (isCJet) perchè altrimenti riempirei due volte 
//il vettore b_jets (già fatto sopra)
  //  b_jets.push_back(j); //push_back vuole il puntatore al jet cioè j, non &j che sarebbe il puntatore di un puntatore
if (isCJet)
    c_jets.push_back(j);
else if(!isBJet && !isCJet)
    light_jets.push_back(j);
    }

for (const Jet* jet : b_jets) {
       _h_bjet_mass->fill(jet->mass()/GeV);}
for (const Jet* jet : light_jets) {
       _h_lcjet_mass->fill(jet->mass()/GeV);}
for (const Jet* jet : c_jets) {
       _h_lcjet_mass->fill(jet->mass()/GeV);}	

//fin qui con le parentesi dovrebbe essere a posto
      // Select light-jets as the pair of non-b-jets with invariant mass closest to the W mass
     //IO INVECE VOGLIO TUTTI I JET PROVENIENTI DAL W. QUINDI RINOMINO W_JETS QUELLO CHE ERA LIGHT_JETS 
//blocco sistemato nella logica ecc: inizia qui
const double nominalW   = 80.4 * GeV;
const double nominalTop = 172.5 * GeV;

const double sigmaW = 25. * GeV; //decay width and approximate experimental resolution 
const double sigmaT = 35. * GeV;

double bestChi2 = numeric_limits<double>::infinity();

const Jet* bestJ1 = nullptr;
const Jet* bestJ2 = nullptr;
const Jet* bestB  = nullptr; //anche se questo in realtà non serve, ho già 
//b_jets e non mi serve granché sapere qual è il b jet associato al W adronico 
//in principio, non so a quale dei due b-jets è associato il W che
// decade adronicamente (che è uno e non entrambi, dato che ho solo
//  sample nonallhad/singlelep/dilep, quindi in effetti per questa
//   routine mi è inutile produrre anche l'output di dilep) quindi debbo 
//   ciclare anche su b_jets

for (size_t a = 0; a < good_jets.size(); ++a) {

    const Jet* j1 = good_jets[a];

    // Do not use b jets as W candidates
    bool isB1 = false;
    for (ConstGenParticlePtr b : b_hadrons) {
      //blocco che serve per uniformare i tipi di j1->momentum e quello 
      //che sarebbe b->momentum(): il primo è un Rivet::FourMomentum, il 
      //secondo è un HepMC3FourVector e questa cosa manda in pappa rivet.
     // const FourMomentum bhad_mom(
   // b->momentum().px(),
   // b->momentum().py(),
   // b->momentum().pz(),
  //  b->momentum().e() );

if (deltaRJetGen(*j1, b) < 0.3) {
    isB1 = true;
    break;
       }

    }
    if (isB1) continue;


    for (size_t b = a + 1; b < good_jets.size(); ++b)
   //scrivere questo ciclo con b = a+1 impedisce che i jet *j1 e j2 coincidano,
   //quindi di fatto va a ottimizzare il codice impedendo che j1=j2 e anche doppi conteggi
    {   const Jet* j2 = good_jets[b];

        // Do not use b jets as W candidates
        bool isB2 = false;
        for (ConstGenParticlePtr bhad : b_hadrons) {
            if (deltaRJetGen(*j2, bhad) < 0.3) {
                isB2 = true;
                break;
            }
        }
        if (isB2) continue;
        // Reconstructed W
        const double mW =
            (j1->momentum() + j2->momentum()).mass();
        // Try both b jets
        for (const Jet* bjet : b_jets) {

            // Reconstructed hadronic top
            const double mTop =
                (bjet->momentum()
                + j1->momentum()
                + j2->momentum()).mass();
                //non ha senso fisico qui mettere anche z->momentum() per un 
		//eventuale jet da isr/fsr/gluon radiation from b perché il 
		//decadimento del top è w+b, non w+b+z, e all'interno del 
		//momento di b potrebbe esserci già quella parte di momento 
		//che poi andrà in z (se fosse fsr o gluon radiation) quindi 
		//conterei due volte la stessa cosa. è quindi meglio rimandare 
		//(in che modo però) la trattazione di questo eventaule jet z. 

            const double chi2 =
                pow((mW   - nominalW) / sigmaW, 2)
              + pow((mTop - nominalTop) / sigmaT, 2);


            if (chi2 < bestChi2) {
      		    bestChi2 = chi2;
                bestJ1 = j1;
                bestJ2 = j2;
                bestB  = bjet;
            }
        }
    }
}

// UNA SOLA entry per evento
if (isfinite(bestChi2)) {
    _h_W_chi2->fill(bestChi2);
}      
      // Check that both jets are not overlapped, and populate the W jets list
      vector<const Jet*> W_jets;
      const bool hasGoodWJet = bestJ1 != NULL && bestJ2 != NULL && bestJ1 != bestJ2;
      if (hasGoodWJet) {
  //qui in precedenza c'era tutto un blocco che richiedeva che i due bestJ fossero separati da DeltaR maggiore o uguale a 0.8 da un qualunque altro jet di alljet. Ma dato che nella selezione di alljet ci sono tutti i jet con pT superiore a 7 GeV, questa cosa è pericolosa perché rischia di ammazzarmi un sacco di Wjets. Meglio quindi togliere quella selezione e tenere solo la richiesta che i due Wjets non coincidano. 
          W_jets.push_back(bestJ1);
          W_jets.push_back(bestJ2);
          const FourMomentum W = W_jets[0]->momentum() + W_jets[1]->momentum();
	  _h_W_pT->fill(W.pT()/GeV);
	  _h_W_mass->fill(W.mass()/GeV); 
      }

      MSG_DEBUG(W_jets.size() << " W jets selected");
  //anche qui le parentesi potrebbero essere giuste

      //agiunto il 31 agosto:
       if (W_jets.size() > 1) {
        const FourMomentum W = W_jets[0]->momentum() + W_jets[1]->momentum();
       //amen la ridichiaro tanto è una variabile interna al loop
       //ordunque non dovrebbe dare problemi 
       	_h_W_Wjets_dR->fill(deltaR(W, W_jets[0]->momentum()));
        _h_W_Wjets_dR->fill(deltaR(W, W_jets[1]->momentum()));
         _h_W_Wjets_deta->fill(fabs(W.eta()-W_jets[0]->eta()));
        _h_W_Wjets_dphi->fill(deltaPhi(W, W_jets[0]->momentum()));
	_h_W_Wjets_deta->fill(fabs(W.eta()-W_jets[1]->eta()));
        _h_W_Wjets_dphi->fill(deltaPhi(W,W_jets[1]->momentum())); } //fine blocco aggiunto il 31 agosto

      // Calculate the jet shapes
      /// @todo Use C++11 vector/array initialization
      const double binWidth = 0.04; // -> 10 bins from 0.0-0.4
     vector<double> _ptEdges;  //dichiarato già in init()
     _ptEdges += {{30, 40, 50, 70, 100, 150}};

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
          if (inRange(jetPt / GeV, _ptEdges[ipt], _ptEdges[ipt + 1])) break;
        MSG_DEBUG("Jet pT index = " << ipt);

        // Calculate jet shape
        vector<double> rings(10, 0);
        for (const Particle& p : bJet->particles()) {
          const double dR = deltaR(bJet->momentum(), p.momentum());
          const size_t idR = (size_t)floor(dR / binWidth); 
	  if (idR >= 10) continue;
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
      if (W_jets.size())
      for (const Jet* WJet : W_jets) {
        // Work out jet pT bin and skip this jet if out of range
        const double jetPt = WJet->momentum().pT();
        MSG_DEBUG("Jet pT = " << jetPt / GeV << " GeV");
        if (!inRange(jetPt / GeV, 30., 150.)) continue;
        /// @todo Use YODA bin index lookup tools
        size_t ipt;
        for (ipt = 0; ipt < 5; ++ipt)
          if (inRange(jetPt / GeV, _ptEdges[ipt], _ptEdges[ipt + 1])) break;
        MSG_DEBUG("Jet pT index = " << ipt);

        // Calculate jet shape
        vector<double> rings(10, 0);
        for (const Particle& p : WJet->particles()) {
          const double dR = deltaR(WJet->momentum(), p.momentum());
          const size_t idR = (size_t)floor(dR / binWidth); //serve 
	  //semplicemente a trasformare la distanza continua ΔR 
	  //della particella dall'asse del jet nell'indice intero del bin 
	  //radiale in cui cade la particella
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
      }
      	if (W_jets.size()) 
	for (const Jet* wjet : W_jets) {
                 double W_num = 0., W_den = 0.;
            long N_charged = 0;
            for (const Particle& pp : wjet->particles()) {
              if(pp.isStable()) {
                W_num += pp.pT()*deltaR(wjet->momentum(),pp.momentum());
                W_den += pp.pT();
                if(pp.isCharged()) ++N_charged; } }
	      //if pp.isLepton non lo faccio perché nei light jets è parecchio improbabile che ci sia un leptone
	     if (W_den)  _h_bar_Wjets_width->fill(W_num/W_den);
            _h_Wjets_pT->fill(wjet->pT()/GeV);
            if (N_charged) {
              _h_Wjets_ch_mult->fill(N_charged); }
	//FINE DEL BLOCCO AGGIUNTO DA ME 
      }
}
    /// Normalise histograms etc., after the run
    void finalize() {
      normalize({_h_ptCJetLead, _h_ptCHadrLead, _h_ptBJetLead, _h_ptBHadrLead,
            _h_ptFracC, _h_eFracC, _h_ptFracB, _h_eFracB, _h_bar_Wjets_width,
	    _h_Wjets_pT, _h_Wjets_ch_mult, _h_pT_muon, _h_pT_electron,
	    _h_pT_lepton, _h_W_chi2, _h_W_Wjets_dR, _h_W_Wjets_deta,
	    _h_W_Wjets_dphi, _h_bjet_mass, _h_lcjet_mass, _h_W_pT, _h_W_mass});
      //, _p_Wjets_rho, _p_Wjets_Psi, _p_b_rho, _p_b_Psi}); //questi sono Profile1D, non vanno normalizzati a mano
   }


    /// @name Histograms
    /// @{
    Histo1DPtr _h_ptCJetLead, _h_ptCHadrLead, _h_ptFracC, _h_eFracC;
    Histo1DPtr _h_ptBJetLead, _h_ptBHadrLead, _h_ptFracB, _h_eFracB;
    Histo1DPtr   _h_bar_Wjets_width,_h_Wjets_pT, _h_Wjets_ch_mult;
    Histo1DPtr _h_pT_muon, _h_pT_electron, _h_pT_lepton, _h_W_chi2;
    Histo1DPtr _h_W_Wjets_dR, _h_W_Wjets_deta, _h_W_Wjets_dphi;
    Histo1DPtr _h_bjet_mass, _h_lcjet_mass, _h_W_pT, _h_W_mass;
    Profile1DPtr _p_b_rho[5];//inizio aggiunta mia
    Profile1DPtr _p_Wjets_rho[5];
    Profile1DPtr _p_b_Psi[5];
    Profile1DPtr _p_Wjets_Psi[5];//fine aggiunta mia  
    /// @}


  };

	    

  RIVET_DECLARE_PLUGIN(MC_HFJETS_MOD);

}
