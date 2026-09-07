//MC_TTBAR.cc
//MC analysis for ttbar studies

#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/VetoedFinalState.hh"
#include "Rivet/Projections/ChargedLeptons.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/AnalysisLoader.hh"

namespace Rivet {


  class MC_TTBAR : public Analysis {
  public:

    /// Minimal constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(MC_TTBAR);


    /// @name Analysis methods
    /// @{

    /// Set up projections and book histograms
    void init() {

      _mode = 3; string pre = "anylep_"; // default is single-lepton decay mode
      if ( getOption("TTMODE") == "ALLHAD" ) { _mode = 0; pre = "allhad_"; }
      if ( getOption("TTMODE") == "ONELEP" ) { _mode = 1; pre = "onelep_"; }
      if ( getOption("TTMODE") == "TWOLEP" ) { _mode = 2; pre = "twolep_"; }
      if ( getOption("TTMODE") == "ANYLEP" ) { _mode = 3; pre = "anylep_"; }

      // A FinalState is used to select particles within |eta| < 4.2 and with pT
      // > 30 GeV, out of which the ChargedLeptons projection picks only the
      // electrons and muons, to be accessed later as "LFS".
      ChargedLeptons lfs(FinalState(Cuts::abseta < 2.5 && Cuts::pT > 20*GeV));
      declare(lfs, "LFS");

      // A second FinalState is used to select all particles in |eta| < 4.2,
      // with no pT cut. This is used to construct jets and measure missing
      // transverse energy.
      VetoedFinalState fs(FinalState(Cuts::abseta < 2.5));
      fs.addVetoOnThisFinalState(lfs);
      declare(FastJets(fs, JetAlg::ANTIKT, 0.6), "Jets"); //qui ho messo R=0.4 (nell'originale è R=0.6)
      declare(MissingMomentum(fs), "MissingET");

      // Booking of histograms
      book(_h_njets, pre + "jet_mult", 11, -0.5, 10.5);
      //
      book(_h_jet_1_pT, pre + "jet_1_pT", logspace(50, 20.0, 500.0));
      book(_h_jet_2_pT, pre + "jet_2_pT", logspace(50, 20.0, 400.0));
      book(_h_jet_3_pT, pre + "jet_3_pT", logspace(50, 20.0, 300.0));
      book(_h_jet_4_pT, pre + "jet_4_pT", logspace(50, 20.0, 200.0));
      book(_h_jet_HT,   pre + "jet_HT", logspace(50, 100.0, 2000.0));
      //
      book(_h_bjet_1_pT, pre + "jetb_1_pT", logspace(50, 20.0, 400.0));
      book(_h_bjet_2_pT, pre + "jetb_2_pT", logspace(50, 20.0, 300.0));
      //
      book(_h_ljet_1_pT, pre + "jetl_1_pT", logspace(50, 20.0, 400.0));
      book(_h_ljet_2_pT, pre + "jetl_2_pT", logspace(50, 20.0, 300.0));
      //
      //PROVO A SILENZIARE LE CONDIZIONI RICHIESTE PER BOOKARE QUESTI ISTOGRAMMI
      //PER VEDERE SE SI SBLOCCA LA SITUAZIONE (ALLA FINE POSSO LO STESSO 
      //PRENOTARLI E POI LASCIARLI VUOTI SE LA CONDIZIONE, A LIVELLO DI 
      //ANALYZE, NON VIENE SODDISFATTA)
     // if  (_mode != 2)  
	      book(_h_tt_mass, pre + "tt_mass", 200, 300.0, 700.0);
      //
     // if (_mode < 2) { // these rely on a hadronic W being part of the ttbar decay
        book(_h_W_pT, pre + "W_pT", logspace(50, 5.0, 650.0)); //riga aggiunta da me
	book(_h_W_mass, pre + "W_mass", 75, 30, 180);
        book(_h_t_mass, pre + "t_mass", 150, 130, 430);
        book(_h_t_mass_W_cut, pre + "t_mass_W_cut", 150, 130, 430);
        book(_h_t_pT_W_cut, pre + "t_pT_W_cut", logspace(100, 5.0, 1000.));
        book(_h_jetb_1_W_dR,  pre + "jetb_1_W_dR", 20, 0.0, 7.0);
        book(_h_jetb_1_W_deta, pre + "jetb_1_W_deta", 20, 0.0, 7.0);
        book(_h_jetb_1_W_dphi, pre + "jetb_1_W_dphi", 20, 0.0, M_PI);
     // }
      //
      book(_h_jetb_1_jetb_2_dR,   pre + "jetb_1_jetb_2_dR", 20, 0.0, 7.0);
      book(_h_jetb_1_jetb_2_deta, pre + "jetb_1_jetb_2_deta", 20, 0.0, 7.0);
      book(_h_jetb_1_jetb_2_dphi, pre + "jetb_1_jetb_2_dphi", 20, 0.0, M_PI);
      book(_h_jetb_1_jetl_1_dR,   pre + "jetb_1_jetl_1_dR", 20, 0.0, 7.0);
      book(_h_jetb_1_jetl_1_deta, pre + "jetb_1_jetl_1_deta", 20, 0.0, 7.0);
      book(_h_jetb_1_jetl_1_dphi, pre + "jetb_1_jetl_1_dphi", 20, 0.0, M_PI);
     //questi tre istogrammi vengono riempiti solo da eventi singlelep, dato 
     //che per eventi dilep gli unici jet adronici possibili provengono da 
     //radiazione isr o fsr.  
      book(_h_jetl_1_jetl_2_dR,   pre + "jetl_1_jetl_2_dR", 20, 0.0, 7.0);
      book(_h_jetl_1_jetl_2_deta, pre + "jetl_1_jetl_2_deta", 20, 0.0, 7.0);
      book(_h_jetl_1_jetl_2_dphi, pre + "jetl_1_jetl_2_dphi", 20, 0.0, M_PI);
    //  if (_mode > 0) { // these rely on at least one leptonic decay mode
        book(_h_jetb_1_l_dR,   pre + "jetb_1_l_dR", 20, 0.0, 7.0);
        book(_h_jetb_1_l_deta, pre + "jetb_1_l_deta", 20, 0.0, 7.0);
        book(_h_jetb_1_l_dphi, pre + "jetb_1_l_dphi", 20, 0.0, M_PI);
        book(_h_jetb_1_l_mass, pre + "jetb_1_l_mass", 40, 0.0, 500.0);
       // if (_mode > 1) {
          book(_h_jetb_1_l2_dR,   pre + "jetb_1_l2_dR", 20, 0.0, 7.0);
          book(_h_jetb_1_l2_deta, pre + "jetb_1_l2_deta", 20, 0.0, 7.0);
          book(_h_jetb_1_l2_dphi, pre + "jetb_1_l2_dphi", 20, 0.0, M_PI);
          book(_h_jetb_1_l2_mass, pre + "jetb_1_l2_mass", 40, 0.0, 500.0);
      //  } }
      //  istogrammi che aggiungo ora e che davano problemi perché usati ma
      //  non bookati:
      book(_h_t_pT, pre + "t_pT", logspace(100, 5.0, 1000.));
      book(_h_jetb_1_jetl_2_dR, pre + "jetb_1_jetl_2_dR", 20, 0.0, 7.0);
      book(_h_jetb_1_jetl_2_deta, pre + "jetb_1_jetl_2_deta", 20, 0.0, 7.0);
      book(_h_jetb_1_jetl_2_dphi, pre + "jetb_1_jetl_2_dphi", 20, 0.0, M_PI);
      book(_h_W_chi2, "W_chi2", 50, 0., 4.0);
    }

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

    void analyze(const Event& event) {

      // Use the "LFS" projection to require at least one hard charged
      // lepton. This is an experimental signature for the leptonically decaying
      // W. This helps to reduce pure QCD backgrounds.
      const ChargedLeptons& lfs = apply<ChargedLeptons>(event, "LFS");
      MSG_DEBUG("Charged lepton multiplicity = " << lfs.chargedLeptons().size());
      for (const Particle& lepton : lfs.chargedLeptons()) {
        MSG_DEBUG("Lepton pT = " << lepton.pT());
      }

      size_t nLeps = lfs.chargedLeptons().size();
      bool leptonMultiFail = _mode == 3 && nLeps == 0; // non-all-hadronic
      leptonMultiFail |= _mode == 2 && nLeps != 2; // dilepton
      leptonMultiFail |= _mode == 1 && nLeps != 1; // single lepton
      leptonMultiFail |= _mode == 0 && nLeps != 0; // all-hadronic
      if (leptonMultiFail) {
        MSG_DEBUG("Event failed lepton multiplicity cut");
        vetoEvent;
      }

      // Use a missing ET cut to bias toward events with a hard neutrino from
      // the leptonically decaying W. This helps to reduce pure QCD backgrounds.
      // not applied in all-hadronic mode
      const Vector3& met = apply<MissingMomentum>(event, "MissingET").vectorMissingPt();
      MSG_DEBUG("Vector pT = " << met.mod() << " GeV");
      if (_mode > 0 && met.mod() < 30*GeV) {
        MSG_DEBUG("Event failed missing ET cut");
        vetoEvent;
      }

      // Use the "Jets" projection to check how many jets with pT > 30 GeV there are
      // remove jets overlapping with any lepton (dR < 0.3)
      // cut on jet multiplicity depending on ttbar decay mode
      const FastJets& jetpro = apply<FastJets>(event, "Jets");
      const Jets jets = discardIfAnyDeltaRLess(jetpro.jetsByPt(Cuts::pT > 30*GeV), lfs.chargedLeptons(), 0.3);
     
       vector<ConstGenParticlePtr> b_hadrons;
      vector<ConstGenParticlePtr> allParticles = HepMCUtils::particles(event.genEvent());
      for (size_t i = 0; i < allParticles.size(); i++) {
        ConstGenParticlePtr p = allParticles.at(i);
        if (!(PID::isHadron(p->pdg_id()) && PID::hasBottom(p->pdg_id()))) continue;
        if (p->momentum().perp() < 5 * GeV) continue;
        b_hadrons.push_back(p);
      }

      if (     _mode == 0 && jets.size() < 6)  vetoEvent; // all-hadronic
      else if (_mode == 1 && jets.size() < 4)  vetoEvent; // single lepton
      else if (_mode == 2 && jets.size() < 2)  vetoEvent; // dilepton
      else if (_mode == 3 && nLeps == 1 && jets.size() < 4)  vetoEvent; // non-allhadronic
      else if (_mode == 3 && nLeps == 2 && jets.size() < 2)  vetoEvent;
      MSG_DEBUG("Event failed jet multiplicity cut");

      // Fill histograms for inclusive jet kinematics
      _h_njets->fill(jets.size());
      if (jets.size() > 0)  _h_jet_1_pT->fill(jets[0].pT()/GeV);
      if (jets.size() > 1)  _h_jet_2_pT->fill(jets[1].pT()/GeV);
      if (jets.size() > 2)  _h_jet_3_pT->fill(jets[2].pT()/GeV);
      if (jets.size() > 3)  _h_jet_4_pT->fill(jets[3].pT()/GeV);
      double ht = 0.0;
      for (const Jet& j : jets) { ht += j.pT(); }
      _h_jet_HT->fill(ht/GeV);

      // Sort the jets into b-jets and light jets. We expect one hard b-jet from
      // each top decay, so our 4 hardest jets should include two b-jets. The
      // Jet::bTagged() method is equivalent to perfect experimental
      // b-tagging, in a generator-independent way.
      Jets bjets, ljets;
      for (const Jet& jet : jets) {
        if (jet.bTagged())  bjets += jet;
        else                ljets += jet;
      }
      MSG_DEBUG("Number of b-jets = " << bjets.size());
      MSG_DEBUG("Number of l-jets = " << ljets.size());
      if (bjets.size() != 2) {
        MSG_DEBUG("Event failed post-lepton-isolation b-tagging cut");
        vetoEvent;
      }
      if (_mode == 0 && ljets.size() < 4)  vetoEvent;
      else if (_mode == 1 && ljets.size() < 2)  vetoEvent;
      else if (_mode == 3 && nLeps == 1 && ljets.size() < 2)  vetoEvent;

      // Plot the pTs of the identified jets.
      _h_bjet_1_pT->fill(bjets[0].pT()/GeV);
      _h_bjet_2_pT->fill(bjets[1].pT()/GeV);
      // need to check size to cater for dileptonic mode
      if (ljets.size() > 0)  _h_ljet_1_pT->fill(ljets[0].pT()/GeV);
      if (ljets.size() > 1)  _h_ljet_2_pT->fill(ljets[1].pT()/GeV);


      // Try to reconstruct ttbar pair (doesn't really work in the dileptonic mode)
      FourMomentum ttpair = bjets[0].mom() + bjets[1].mom();
      if (_mode == 0) {
        ttpair += ljets[0].mom() + ljets[1].mom() + ljets[2].mom() + ljets[3].mom();
      }
      else if (nLeps < 2) {
        ttpair += ljets[0].mom() + ljets[1].mom();
        const FourMomentum lep = lfs.chargedLeptons()[0].mom();
        double pz = findZcomponent(lep, met);
        FourMomentum neutrino(sqrt(sqr(met.x()) + sqr(met.y()) + sqr(pz)), met.x(), met.y(), pz);
        ttpair += lep + neutrino;
      }
      if (nLeps < 2)  _h_tt_mass->fill(ttpair.mass()/GeV);

      //qui c'era if (_mode<2), che però mi va a silenziare anylep e quindi fa sì che gli istogrammi in questo blocco non vengano riempiti.
      if (ljets.size()>1) {
        // Construct the hadronically decaying W momentum 4-vector from pairs of
        // non-b-tagged jets. The pair which best matches the W mass is used. We start
        // with an always terrible 4-vector estimate which should always be "beaten" by
        // a real jet pair.
       //DA QUI COMMENTO LA VECCHIA IDENTIFICAZIONE DI W
	    //  FourMomentum W(10*(sqrtS()>0.?sqrtS():14000.), 0, 0, 0);
      //  for (size_t i = 0; i < ljets.size()-1; ++i) {
        //  for (size_t j = i + 1; j < ljets.size(); ++j) {
         //   const FourMomentum Wcand = ljets[i].momentum() + ljets[j].momentum();
          //  MSG_TRACE(i << "," << j << ": candidate W mass = " << Wcand.mass()/GeV
           //           << " GeV, vs. incumbent candidate with " << W.mass()/GeV << " GeV");
          //  if (fabs(Wcand.mass() - 80.4*GeV) < fabs(W.mass() - 80.4*GeV)) {
           //   W = Wcand;  }    } }
     //   MSG_DEBUG("Candidate W mass = " << W.mass() << " GeV");
        // There are two b-jets with which this can be combined to make the
        // hadronically decaying top, one of which is correct and the other is
        // not... but we have no way to identify which is which, so we construct
        // both possible top momenta and fill the histograms with both.
      //  const FourMomentum t1 = W + bjets[0].momentum();
     //  const FourMomentum t2 = W + bjets[1].momentum();
     // FINE BLOCCO DELLA VECCHIA IDENTIFICAZIONE DI W E TOP
     //
     // INIZIO IDENTIFICAZIONE DI W E TOP CON IL CHI2 (PRESO DA HFJETS)
     //blocco sistemato nella logica ecc: inizia qui
const double nominalW   = 80.4 * GeV;
const double nominalTop = 172.5 * GeV;
const FourMomentum W_reco;
const FourMomentum t_reco;

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
const Jet* j1 = nullptr;

for (size_t a = 0; a < jets.size(); ++a) {

   // const Jet* j1 = jets[a];
     &j1 = jets[a].mom();
    // Do not use b jets as W candidates
    bool isB1 = false;
    for (ConstGenParticlePtr b : b_hadrons) {

if (deltaRJetGen(*j1, b) < 0.3) {
    isB1 = true;
    break;
       }
    }
    if (isB1) continue;

    for (size_t b = a + 1; b < jets.size(); ++b)
   //scrivere questo ciclo con b = a+1 impedisce che i jet *j1 e j2 coincidano,
   //quindi di fatto va a ottimizzare il codice impedendo che j1=j2 e anche doppi conteggi
    {   const Jet* j2 = jets[b];
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
        for (const Jet& bjet : bjets) {

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
    W_reco = bestJ1->momentum() + bestJ2->momentum();
    t_reco = W_reco + bestB->momentum();    
    _h_W_chi2->fill(bestChi2);
    _h_W_pT->fill(W_reco.pT()/GeV);
        _h_W_mass->fill(W_reco.mass()/GeV);
        _h_t_mass->fill(t_reco.mass()/GeV);
        _h_t_pT->fill(t_reco.pT()/GeV);
}  
     //FINE BLOCCO IDENTIFICAZIONE DI W E TOP ATTRAVERSO IL CHI2
     //

        // Placing a cut on the well-known W mass helps to reduce backgrounds
        // only done for all-hadronic and semileptonic mode (since W is hadronic)
        if (!inRange(W_reco.mass()/GeV, 75.0, 85.0))  vetoEvent;
        MSG_DEBUG("W found with mass " << W_reco.mass()/GeV << " GeV");

        _h_t_mass_W_cut->fill(t_reco.mass()/GeV);
        _h_t_pT_W_cut->fill(t_reco.pT()/GeV);
        _h_jetb_1_W_dR->fill(deltaR(bjets[0].momentum(), W_reco));
        _h_jetb_1_W_deta->fill(fabs(bjets[0].eta()-W_reco.eta()));
        _h_jetb_1_W_dphi->fill(deltaPhi(bjets[0].momentum(),W_reco));
      }

      _h_jetb_1_jetb_2_dR->fill(deltaR(bjets[0].momentum(), bjets[1].momentum()));
      _h_jetb_1_jetb_2_deta->fill(fabs(bjets[0].eta()-bjets[1].eta()));
      _h_jetb_1_jetb_2_dphi->fill(deltaPhi(bjets[0].momentum(),bjets[1].momentum()));

      if (ljets.size() > 0) {
        _h_jetb_1_jetl_1_dR->fill(deltaR(bjets[0].momentum(), ljets[0].momentum()));
        _h_jetb_1_jetl_1_deta->fill(fabs(bjets[0].eta()-ljets[0].eta()));
        _h_jetb_1_jetl_1_dphi->fill(deltaPhi(bjets[0].momentum(),ljets[0].momentum()));
        if (ljets.size() > 1) {
          _h_jetb_1_jetl_2_dR->fill(deltaR(bjets[0].momentum(), ljets[1].momentum()));
          _h_jetb_1_jetl_2_deta->fill(fabs(bjets[0].eta()-ljets[1].eta()));
          _h_jetb_1_jetl_2_dphi->fill(deltaPhi(bjets[0].momentum(),ljets[1].momentum()));
	  _h_jetl_1_jetl_2_dR->fill(deltaR(ljets[0].momentum(), ljets[1].momentum()));
          _h_jetl_1_jetl_2_deta->fill(fabs(ljets[0].eta() - ljets[1].eta()));
          _h_jetl_1_jetl_2_dphi->fill(deltaPhi(ljets[0].momentum(), ljets[1].momentum()));
        }
      }

      // lepton-centric plots
      if (_mode > 0) {
        FourMomentum l=lfs.chargedLeptons()[0].momentum();
        _h_jetb_1_l_dR->fill(deltaR(bjets[0].momentum(), l));
        _h_jetb_1_l_deta->fill(fabs(bjets[0].eta()-l.eta()));
        _h_jetb_1_l_dphi->fill(deltaPhi(bjets[0].momentum(),l));
        _h_jetb_1_l_mass->fill(FourMomentum(bjets[0].momentum()+l).mass());

        if (nLeps > 1) {
          FourMomentum l=lfs.chargedLeptons()[1].momentum();
          _h_jetb_1_l2_dR->fill(deltaR(bjets[0].momentum(), l));
          _h_jetb_1_l2_deta->fill(fabs(bjets[0].eta()-l.eta()));
          _h_jetb_1_l2_dphi->fill(deltaPhi(bjets[0].momentum(),l));
          _h_jetb_1_l2_mass->fill(FourMomentum(bjets[0].momentum()+l).mass());
        }
      }

    }
    
    //non ho capito a che serve tutto sto blocco qua su z component
    double findZcomponent(const FourMomentum& lepton, const Vector3& met) const {
      // estimate z-component of momentum given lepton 4-vector and MET 3-vector
      double pz_estimate;
      double m_W = 80.399*GeV;
      double k = (( sqr( m_W ) - sqr( lepton.mass() ) ) / 2 ) + (lepton.px() * met.x() + lepton.py() * met.y());
      double a = sqr ( lepton.E() )- sqr ( lepton.pz() );
      double b = -2*k*lepton.pz();
      double c = sqr( lepton.E() ) * sqr( met.perp() ) - sqr( k );
      double discriminant = sqr(b) - 4 * a * c;
      if (discriminant < 0) { pz_estimate = - b / (2 * a);} //if the discriminant is negative 
     else {
      const double sqrtDisc = sqrt(discriminant);
      double pz1 = (-b - sqrtDisc)/(2*a);
    double pz2 = (-b + sqrtDisc)/(2*a);

    if (fabs(pz1) < fabs(pz2))
        pz_estimate = pz1;

     // double quad[2] = { (- b - sqrt(discriminant)) / (2 * a), (- b + sqrt(discriminant)) / (2 * a) }; //two possible quadratic solns
      
     // else { //if the discriminant is greater than or equal to zero, take the soln with smallest absolute value
       // double absquad[2];
       // for (int n=0; n<2; ++n)  absquad[n] = fabs(quad[n]);
        //if (absquad[0] < absquad[1])
	 
        else   pz_estimate = pz2;
      }
      return pz_estimate;
    }

    void safeNormalize(Histo1DPtr h) {
    if (h && h->numEntries() > 0) normalize(h);} //controllo di sicurezza, normalizza un 
    //istogramma solo se questo esiste. Svantaggio: accetta un solo argomento 
    //per volta. 

    void finalize() {
	    //normalizzazione della routine originaria:
     // const double sf = crossSection()/picobarn / sumOfWeights();
     // for (auto hist : _h) { scale(hist.second, sf); }
     // normalizzazione a 1 (messa da me)
    normalize({_h_njets, _h_jet_1_pT, _h_jet_2_pT, _h_jet_3_pT,
        _h_jet_4_pT, _h_jet_HT, _h_bjet_1_pT, _h_bjet_2_pT, _h_ljet_1_pT,
        _h_ljet_2_pT, _h_tt_mass, _h_W_pT, _h_t_pT,
       	//_h_W_mass, _h_t_mass,
        //_h_t_mass_W_cut, _h_t_pT_W_cut,
       //	_h_jetb_1_W_dR, _h_jetb_1_W_deta, _h_jetb_1_W_dphi,
       	_h_jetb_1_jetb_2_dR,
        _h_jetb_1_jetb_2_deta, _h_jetb_1_jetb_2_dphi, _h_jetb_1_jetl_1_dR,
        _h_jetb_1_jetl_1_deta, _h_jetb_1_jetl_1_dphi, _h_jetb_1_jetl_2_dR,
        _h_jetb_1_jetl_2_deta, _h_jetb_1_jetl_2_dphi, _h_jetb_1_l_dR,
        _h_jetb_1_l_deta, _h_jetb_1_l_dphi, _h_jetb_1_l_mass,
        _h_jetb_1_l2_dR, _h_jetb_1_l2_deta, _h_jetb_1_l2_dphi,
        _h_jetb_1_l2_mass,  _h_jetl_1_jetl_2_dR, _h_jetl_1_jetl_2_deta,
	_h_jetl_1_jetl_2_dphi, _h_W_chi2});
    safeNormalize(_h_jetb_1_W_dR);
    safeNormalize(_h_jetb_1_W_deta);
    safeNormalize(_h_jetb_1_W_dphi);
    safeNormalize(_h_t_mass);
    safeNormalize(_h_t_mass_W_cut);
    safeNormalize(_h_t_pT_W_cut);
    safeNormalize(_h_W_mass);
    }
   
    /// @}

  protected:

      size_t _mode;


  private:

    /// @name Histogram data members
    /// @{
   // map<string, Histo1DPtr> _h; //commentata da me 
    /// @}
    //aggiunta da me:
    /// @name Histograms
    /// @{
    Histo1DPtr  _h_njets, _h_jet_1_pT, _h_jet_2_pT, _h_jet_3_pT;
    Histo1DPtr  _h_jet_4_pT, _h_jet_HT, _h_bjet_1_pT, _h_bjet_2_pT;
    Histo1DPtr  _h_ljet_1_pT, _h_ljet_2_pT, _h_tt_mass, _h_W_pT, _h_W_mass;
    Histo1DPtr  _h_t_mass,_h_t_mass_W_cut, _h_t_pT, _h_t_pT_W_cut;
    Histo1DPtr  _h_jetb_1_W_dR, _h_jetb_1_W_deta, _h_jetb_1_W_dphi;
    Histo1DPtr  _h_jetb_1_jetb_2_dR, _h_jetb_1_jetb_2_deta;
    Histo1DPtr  _h_jetb_1_jetb_2_dphi, _h_jetb_1_jetl_1_dR;
    Histo1DPtr  _h_jetb_1_jetl_1_deta, _h_jetb_1_jetl_1_dphi;
    Histo1DPtr  _h_jetb_1_jetl_2_dR, _h_jetb_1_jetl_2_deta;
    Histo1DPtr  _h_jetb_1_jetl_2_dphi, _h_jetb_1_l_dR, _h_jetb_1_l_deta;
    Histo1DPtr  _h_jetb_1_l_dphi, _h_jetb_1_l_mass, _h_jetb_1_l2_dR;
    Histo1DPtr  _h_jetb_1_l2_deta, _h_jetb_1_l2_dphi, _h_jetb_1_l2_mass;
    Histo1DPtr _h_jetl_1_jetl_2_dR, _h_jetl_1_jetl_2_deta,_h_jetl_1_jetl_2_dphi;
    Histo1DPtr _h_W_chi2;
  };


  RIVET_DECLARE_PLUGIN(MC_TTBAR);

}
