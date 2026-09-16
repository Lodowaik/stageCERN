#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/VetoedFinalState.hh"
#include "Rivet/Projections/FastJets.hh"
// #include "Rivet/Projections/DressedLeptons.hh"
#include "Rivet/Projections/LeptonFinder.hh" // rivet 4
#include "Rivet/Projections/PromptFinalState.hh"
#include "Rivet/Projections/ChargedFinalState.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/InvisibleFinalState.hh"
#include "Rivet/Projections/PartonicTops.hh"
#include "Rivet/Tools/ParticleName.hh"

namespace Rivet {

  using namespace Cuts;

  class ATLAS_tt_tW_ent : public Analysis {
  public:

    /// @name Constructors etc.
    //@{

    /// Constructor
    ATLAS_tt_tW_ent()
      : Analysis("ATLAS_tt_tW_ent"),
	_ETmiss(20.), _ETmissMW(60.),_MT(172.5), _MW(80.4), 
	_reco_sig_MTlep(11.08), _reco_sig_MW(10.57)
    {
      
      //      setNeedsCrossSection(false);
      
      _pt_el  = 15.0; // 30 before
      _eta_el =  2.5;
      _pt_mu  = 15.0; // 30 before
      _eta_mu =  2.5;
      
      // _ETmiss = 20.0;
      // _ETmiss = 0.0;
      
      // Channels.push_back("ejets");
      // Channels.push_back("mujets");
      // Channels.push_back("ee");
      // Channels.push_back("mumu");
      // Channels.push_back("emu");
      Channels.push_back("dilepton");
      // Channels.push_back("allhad");
      // Channels.push_back("all");
      
    }
    
    //@}
    
    
  public:
    
    /// @name Analysis methods
    //@{
    
    /// Book histograms and initialise projections before the run
    void init() {

      PartonicTops partonTops;
      declare(partonTops, "partonicTops");
      
      // Photons
      PromptFinalState photons(Cuts::abspid == PID::PHOTON);
      
      // Muons
      Cut lepton_cuts = Cuts::abseta < 2.5 && Cuts::pT > 15*GeV;
      // PromptFinalState bare_mu(Cuts::abspid == PID::MUON, true);
      // DressedLeptons all_dressed_mu(photons, bare_mu, 0.1, lepton_cuts, true);
      PromptFinalState bare_mu(Cuts::abspid == PID::MUON);
      LeptonFinder all_dressed_mu(bare_mu, photons, 0.1, lepton_cuts);
      declare(all_dressed_mu, "muons");
      
      // Electrons
      // PromptFinalState bare_el(Cuts::abspid == PID::ELECTRON, true);
      // DressedLeptons all_dressed_el(photons, bare_el, 0.1, lepton_cuts, true);
      PromptFinalState bare_el(Cuts::abspid == PID::ELECTRON);
      LeptonFinder all_dressed_el(bare_el, photons, 0.1, lepton_cuts);
      declare(all_dressed_el, "electrons");

      // Neutrinos
      IdentifiedFinalState nu_id;
      nu_id.acceptNeutrinos();
      PromptFinalState Neutrinos(nu_id);
      Neutrinos.acceptTauDecays(true); 
      declare(Neutrinos, "Neutrinos");
      
      //Jet forming
      // const InvisibleFinalState neutrinos(true, true);
      const InvisibleFinalState neutrinos;


      VetoedFinalState vfs(FinalState(Cuts::abseta < 5.0));
      vfs.addVetoOnThisFinalState(all_dressed_el);
      vfs.addVetoOnThisFinalState(all_dressed_mu);
      vfs.addVetoOnThisFinalState(neutrinos);
      // FastJets jetfs(vfs, FastJets::ANTIKT, 0.4, JetAlg::Muons::ALL, JetAlg::Invisibles::ALL);
      FastJets jetfs(vfs, JetAlg::ANTIKT, 0.4, JetMuons::ALL, JetInvisibles::ALL);
      declare(jetfs, "jets");
     
      declare(MissingMomentum(), "MissingMomentum");
      
      // book histograms
      
      // define asymmetric bins for pt and mass distributions until 1000.0
      std::vector< double > binedges;
      binedges.push_back(0.0);     binedges.push_back(50.0);  binedges.push_back(100.0);  binedges.push_back(150.0); 
      binedges.push_back(200.0);   binedges.push_back(250.0); binedges.push_back(350.0);  binedges.push_back(800.0);
      binedges.push_back(1500.0);
      
      std::vector< double > binedges_lepton;
      binedges_lepton.push_back(8.0);   binedges_lepton.push_back(18.0); binedges_lepton.push_back(28.0);
      binedges_lepton.push_back(38.0);  binedges_lepton.push_back(48.0); binedges_lepton.push_back(58.0);  binedges_lepton.push_back(68.0);
      binedges_lepton.push_back(88.0);  binedges_lepton.push_back(108.0);  binedges_lepton.push_back(148.0);  binedges_lepton.push_back(200.0);
      binedges_lepton.push_back(250.0); binedges_lepton.push_back(350.0);  binedges_lepton.push_back(800.0);  binedges_lepton.push_back(1500.0);

      std::vector< double > binedges2;
      binedges2.push_back(-4.50); binedges2.push_back(-3.50); binedges2.push_back(-2.50); binedges2.push_back(-1.75);
      binedges2.push_back(-1.25); binedges2.push_back(-0.75); binedges2.push_back(-0.25); binedges2.push_back(0.25);
      binedges2.push_back(0.75);  binedges2.push_back(1.25);  binedges2.push_back(1.75);  binedges2.push_back(2.50);
      binedges2.push_back(3.50);  binedges2.push_back(4.50);

      std::vector< double > binedges3;
      binedges3.push_back(0.0);   binedges3.push_back(50.0);  binedges3.push_back(100.0);  binedges3.push_back(150.0);
      binedges3.push_back(200.0); binedges3.push_back(250.0); binedges3.push_back(350.0);  binedges3.push_back(400.0);
      binedges3.push_back(500.0); binedges3.push_back(700.0);
      
      std::vector< double > binedges_top;
      binedges_top.push_back(0.0);  binedges_top.push_back(20.0); binedges_top.push_back(40.0); binedges_top.push_back(60.0);
      binedges_top.push_back(80.0); binedges_top.push_back(100.0);
      binedges_top.push_back(120.0);  binedges_top.push_back(140.0); binedges_top.push_back(160.0); 
      binedges_top.push_back(200.0); binedges_top.push_back(240.0);
      binedges_top.push_back(280.0);  binedges_top.push_back(320.0); binedges_top.push_back(400.0); 
      binedges_top.push_back(500.0); binedges_top.push_back(700.0);
      binedges_top.push_back(900.0); binedges_top.push_back(1300.0);
      binedges_top.push_back(2000.0); binedges_top.push_back(3000.0);
      
      std::vector< double > binedges_W;
      binedges_W.push_back(33.0);     binedges_W.push_back(53.0);     binedges_W.push_back(63.0);     binedges_W.push_back(68.0);
      binedges_W.push_back(73.0);     binedges_W.push_back(78.0);     binedges_W.push_back(83.0);     binedges_W.push_back(88.0);
      binedges_W.push_back(93.0);     binedges_W.push_back(98.0);     binedges_W.push_back(108.0);    binedges_W.push_back(128.0);
      
      std::vector< double > binedges_ttbar;
      binedges_ttbar.push_back(125.0);
      binedges_ttbar.push_back(150.0); binedges_ttbar.push_back(175.0); binedges_ttbar.push_back(200.0); binedges_ttbar.push_back(225.0);
      binedges_ttbar.push_back(250.0); binedges_ttbar.push_back(275.0); binedges_ttbar.push_back(300.0); binedges_ttbar.push_back(325.0);
      binedges_ttbar.push_back(350.0); binedges_ttbar.push_back(380.0); binedges_ttbar.push_back(410.0); binedges_ttbar.push_back(450.0); binedges_ttbar.push_back(500.0);
      binedges_ttbar.push_back(575.0); binedges_ttbar.push_back(650.0); binedges_ttbar.push_back(725.0); binedges_ttbar.push_back(900.0);
      binedges_ttbar.push_back(1300.0); binedges_ttbar.push_back(2000.0); binedges_ttbar.push_back(3000.0);

      std::vector< double > binedges_H_T;
      binedges_H_T.push_back(40.0); binedges_H_T.push_back(60.0);binedges_H_T.push_back(80.0);
      binedges_H_T.push_back(100.0); binedges_H_T.push_back(120.0); binedges_H_T.push_back(140.0); binedges_H_T.push_back(160.0); binedges_H_T.push_back(180.0); 
      binedges_H_T.push_back(200.0); binedges_H_T.push_back(220.0); binedges_H_T.push_back(240.0); binedges_H_T.push_back(260.0); binedges_H_T.push_back(280.0); 
      binedges_H_T.push_back(300.0); binedges_H_T.push_back(320.0); binedges_H_T.push_back(340.0); binedges_H_T.push_back(360.0); binedges_H_T.push_back(380.0); 
      binedges_H_T.push_back(400.0); binedges_H_T.push_back(425.0); binedges_H_T.push_back(450.0); binedges_H_T.push_back(475.0); 
      binedges_H_T.push_back(500.0); binedges_H_T.push_back(525.0); binedges_H_T.push_back(550.0); binedges_H_T.push_back(575.0); 
      binedges_H_T.push_back(600.0); binedges_H_T.push_back(625.0); binedges_H_T.push_back(650.0); binedges_H_T.push_back(675.0); 
      binedges_H_T.push_back(700.0); binedges_H_T.push_back(725.0); binedges_H_T.push_back(750.0); binedges_H_T.push_back(775.0); 
      binedges_H_T.push_back(800.0); binedges_H_T.push_back(850.0); binedges_H_T.push_back(900.0); binedges_H_T.push_back(950.0);
      binedges_H_T.push_back(1000.0); binedges_H_T.push_back(1050.0); 
      binedges_H_T.push_back(1100.0); binedges_H_T.push_back(1200.0); binedges_H_T.push_back(1300.0); binedges_H_T.push_back(1400.0);
      binedges_H_T.push_back(1500.0); binedges_H_T.push_back(1600.0); binedges_H_T.push_back(1700.0); binedges_H_T.push_back(1800.0);
      binedges_H_T.push_back(1900.0); binedges_H_T.push_back(2000.0); binedges_H_T.push_back(2500.0); binedges_H_T.push_back(4000.0);
      
      std::vector< double > binedges_mlb;
      binedges_mlb.push_back(0.0); binedges_mlb.push_back(20.0); binedges_mlb.push_back(40.0); binedges_mlb.push_back(45.0); binedges_mlb.push_back(50.0);
      binedges_mlb.push_back(55.0); binedges_mlb.push_back(60.0); binedges_mlb.push_back(65.0); binedges_mlb.push_back(70.0); binedges_mlb.push_back(75.0);
      binedges_mlb.push_back(80.0); binedges_mlb.push_back(85.0); binedges_mlb.push_back(90.0); binedges_mlb.push_back(95.0);
      binedges_mlb.push_back(100.0); binedges_mlb.push_back(105.0); binedges_mlb.push_back(110.0); binedges_mlb.push_back(115.0); 
      binedges_mlb.push_back(120.0); binedges_mlb.push_back(125.0); binedges_mlb.push_back(130.0); binedges_mlb.push_back(135.0); 
      binedges_mlb.push_back(140.0); binedges_mlb.push_back(145.0); binedges_mlb.push_back(150.0); binedges_mlb.push_back(155.0); 
      binedges_mlb.push_back(160.0); binedges_mlb.push_back(180.0); binedges_mlb.push_back(200.0); binedges_mlb.push_back(220.0); 
      

      std::vector< double > binedges_bjet;
      binedges_bjet.push_back(5.0); binedges_bjet.push_back(15.0); binedges_bjet.push_back(25.0); 
      binedges_bjet.push_back(35.0); binedges_bjet.push_back(45.0); binedges_bjet.push_back(55.0); 
      binedges_bjet.push_back(65.0); binedges_bjet.push_back(75.0); binedges_bjet.push_back(85.0);
      binedges_bjet.push_back(95.0); binedges_bjet.push_back(105.0); binedges_bjet.push_back(115.0); binedges_bjet.push_back(125.0); 
      binedges_bjet.push_back(135.0); binedges_bjet.push_back(145.0); binedges_bjet.push_back(155.0); 
      binedges_bjet.push_back(170.0); binedges_bjet.push_back(185.0); binedges_bjet.push_back(200.0); 
      binedges_bjet.push_back(250.0);  
      binedges_bjet.push_back(350.0); binedges_bjet.push_back(800.0);
      binedges_bjet.push_back(1500.0);

      
      
      book(_histos["weights"],        "weights", 11,  -.75, 4.75);
      book(_histos["channel"],        "channel",  9,  -0.5, 8.5);

      //book(_histos["M_Partop_High"],  "M_Partop_High", 120,0,300);
      //book(_histos["M_Partop_Low"],   "M_Partop_Low",  120,0,300); 
      
      //book(_histos["M_Partop"],       "M_Partop",      120,0,300);
      //book(_histos["M_Paratop"],      "M_Paratop",     120,0,300);
      
      //book(_histos["M_Par2_top"],     "M_Par2_top",    120,0,300);
      //book(_histos["M_Par2_atop"],    "M_Par2_atop",   120,0,300);
      
      // Dimbi
      book(_histos["inv_mass_mumu_ee"],               "inv_mass_mumu_ee",               80, 0, 400);
      book(_histos["inv_mass_mumu_ee_afterMetCut"],   "inv_mass_mumu_ee_afterMetCut",   80, 0, 400);
      book(_histos["pass_mumu_ee"],                   "pass_mumu_ee",                   5, 0.5, 5.5);
      book(_histos["met_mumu_ee"],                    "met_mumu_ee",                    80, 0, 400);
     
      book(_histos["leptons_deltaR"],                    "leptons_deltaR",                100, 0, 10);
      book(_histos["leptons_deltaPhi"],                  "leptons_deltaPhi",              40, 0, 3.142);
      book(_histos["leptons_deltaPhi_ee"],               "leptons_deltaPhi_ee",           40, 0, 3.142);
      book(_histos["leptons_deltaPhi_emu"],              "leptons_deltaPhi_emu",          40, 0, 3.142);
      book(_histos["leptons_deltaPhi_mumu"],             "leptons_deltaPhi_mumu",         40, 0, 3.142);
      book(_histos["leptons_deltaEta"],                  "leptons_deltaEta",              52, 0, 5.2);

      book(_histos["met_allChannels"],           "met_allChannels",               80, 0, 400);

      book(_histos["neutrino_multiplicity"],     "neutrino_multiplicity",         10, -0.5, 10.5);

      book(_histos["neutrino_pT"],                    "neutrino_pT",                    binedges);
      book(_histos["neutrino_eta"],                   "neutrino_eta",                   binedges2);
      book(_histos["neutrino_phi"],                   "neutrino_phi",                   50, -6.3, 6.3);
      
      book(_histos["neutrino_1_pT"],                    "neutrino_1_pT",                    binedges);
      book(_histos["neutrino_1_eta"],                   "neutrino_1_eta",                   binedges2);
      book(_histos["neutrino_1_phi"],                   "neutrino_1_phi",                   50, -6.3, 6.3);

      book(_histos["neutrino_2_pT"],                    "neutrino_2_pT",                    binedges);
      book(_histos["neutrino_2_eta"],                   "neutrino_2_eta",                   binedges2);
      book(_histos["neutrino_2_phi"],                   "neutrino_2_phi",                   50, -6.3, 6.3);
     
      book(_histos["H_T_usingMet"],                    "H_T_usingMet",                    binedges_H_T);
      book(_histos["H_T_usingNeutrinos"],              "H_T_usingNeutrinos",              binedges_H_T);

      book(_histos["Wdecay_channels"],                "Wdecay_channels",                 6, -0.5, 5.5);

      book(_histos["M_ttbar"],    "M_ttbar",      binedges_ttbar);
      book(_histos["pT_ttbar"],   "pT_ttbar",     binedges_top);
      book(_histos["eta_ttbar"],  "eta_ttbar",    binedges2);
      book(_histos["phi_ttbar"],  "phi_ttbar",    100, -6.3, 6.3);

      book(_histos["M_top"],    "M_top",      50, 168, 178);
      book(_histos["pT_top"],   "pT_top",     binedges_top);
      book(_histos["eta_top"],  "eta_top",    binedges2);
      book(_histos["phi_top"],  "phi_top",    100, -6.3, 6.3);

      book(_histos["M_antitop"],    "M_antitop",      50, 168, 178);
      book(_histos["pT_antitop"],   "pT_antitop",     binedges_top);
      book(_histos["eta_antitop"],  "eta_antitop",    binedges2);
      book(_histos["phi_antitop"],  "phi_antitop",    100, -6.3, 6.3);

      book(_histos["M_top_tot"],    "M_top_tot",      50, 168, 178);

      book(_histos["cos_k_p"],  "cos_k_p", 20, -1.0, 1.0);
      book(_histos["cos_n_p"],  "cos_n_p", 20, -1.0, 1.0);
      book(_histos["cos_r_p"],  "cos_r_p", 20, -1.0, 1.0);

      book(_histos["cos_k_m"],  "cos_k_m", 20, -1.0, 1.0);
      book(_histos["cos_n_m"],  "cos_n_m", 20, -1.0, 1.0);
      book(_histos["cos_r_m"],  "cos_r_m", 20, -1.0, 1.0);

      book(_histos["cos_k_k"],  "cos_k_k", 20, -1.0, 1.0);
      book(_histos["cos_n_n"],  "cos_n_n", 20, -1.0, 1.0);
      book(_histos["cos_r_r"],  "cos_r_r", 20, -1.0, 1.0);

      book(_histos["c_n_k_plus_c_k_n"],  "c_n_k_plus_c_k_n",  20, -1.0, 1.0);
      book(_histos["c_n_r_plus_c_r_n"],  "c_n_r_plus_c_r_n",  20, -1.0, 1.0);
      book(_histos["c_r_k_plus_c_k_r"],  "c_r_k_plus_c_k_r",  20, -1.0, 1.0);
      book(_histos["c_n_k_minus_c_k_n"], "c_n_k_minus_c_k_n", 20, -1.0, 1.0);
      book(_histos["c_n_r_minus_c_r_n"], "c_n_r_minus_c_r_n", 20, -1.0, 1.0);
      book(_histos["c_r_k_minus_c_k_r"], "c_r_k_minus_c_k_r", 20, -1.0, 1.0);
      
      book(_histos["cos_phi"],           "cos_phi",           16, -1.0, 1.0);
      book(_histos["cos_phi_ee"],        "cos_phi_ee",        16, -1.0, 1.0);
      book(_histos["cos_phi_emu"],       "cos_phi_emu",       16, -1.0, 1.0);
      book(_histos["cos_phi_mumu"],      "cos_phi_mumu",      16, -1.0, 1.0);
      book(_histos["cos_phi_s380"],      "cos_phi_s380",      16, -1.0, 1.0);
      book(_histos["cos_phi_s390"],      "cos_phi_s390",      16, -1.0, 1.0);
      book(_histos["cos_phi_s400"],      "cos_phi_s400",      16, -1.0, 1.0);
      book(_histos["cos_phi_s410"],      "cos_phi_s410",      16, -1.0, 1.0);
      book(_histos["cos_phi_s380_ee"],   "cos_phi_s380_ee",   16, -1.0, 1.0);
      book(_histos["cos_phi_s380_emu"],  "cos_phi_s380_emu",  16, -1.0, 1.0);
      book(_histos["cos_phi_s380_mumu"], "cos_phi_s380_mumu", 16, -1.0, 1.0);

      book(_histos["cos_phi_l380"],      "cos_phi_l380",      16, -1.0, 1.0);
      book(_histos["cos_phi_l380_ee"],   "cos_phi_l380_ee",   16, -1.0, 1.0);
      book(_histos["cos_phi_l380_emu"],  "cos_phi_l380_emu",  16, -1.0, 1.0);
      book(_histos["cos_phi_l380_mumu"], "cos_phi_l380_mumu", 16, -1.0, 1.0);

      book(_histos["cos_phi_parton"],          "cos_phi_parton",          16, -1.0, 1.0);
      book(_histos["cos_phi_ee_parton"],      "cos_phi_ee_parton",      16, -1.0, 1.0);
      book(_histos["cos_phi_emu_parton"],      "cos_phi_emu_parton",      16, -1.0, 1.0);
      book(_histos["cos_phi_mumu_parton"],      "cos_phi_mumu_parton",      16, -1.0, 1.0);

      book(_histos["cos_phi_s380_parton"],     "cos_phi_s380_parton",     16, -1.0, 1.0);
      book(_histos["cos_phi_s390_parton"],     "cos_phi_s390_parton",     16, -1.0, 1.0);
      book(_histos["cos_phi_s400_parton"],     "cos_phi_s400_parton",     16, -1.0, 1.0);
      book(_histos["cos_phi_s410_parton"],     "cos_phi_s410_parton",     16, -1.0, 1.0);
      book(_histos["cos_phi_s380_ee_parton"],   "cos_phi_s380_ee_parton",   16, -1.0, 1.0);
      book(_histos["cos_phi_s380_emu_parton"],  "cos_phi_s380_emu_parton",  16, -1.0, 1.0);
      book(_histos["cos_phi_s380_mumu_parton"], "cos_phi_s380_mumu_parton", 16, -1.0, 1.0);

      book(_histos["cos_phi_l380_parton"],      "cos_phi_l380_parton",      16, -1.0, 1.0);
      book(_histos["cos_phi_l380_ee_parton"],   "cos_phi_l380_ee_parton",   16, -1.0, 1.0);
      book(_histos["cos_phi_l380_emu_parton"],  "cos_phi_l380_emu_parton",  16, -1.0, 1.0);
      book(_histos["cos_phi_l380_mumu_parton"], "cos_phi_l380_mumu_parton", 16, -1.0, 1.0);

      book(_histos["leptons_deltaR_parton"],   "leptons_deltaR_parton",    100, 0, 10);
      

      book(_histos["leptons_deltaPhi_parton"], "leptons_deltaPhi_parton",   40, 0, 3.142);
      book(_histos["leptons_deltaPhi_parton_ee"], "leptons_deltaPhi_parton_ee",   40, 0, 3.142);
      book(_histos["leptons_deltaPhi_parton_emu"], "leptons_deltaPhi_parton_emu",   40, 0, 3.142);
      book(_histos["leptons_deltaPhi_parton_mumu"], "leptons_deltaPhi_parton_mumu",   40, 0, 3.142);


      book(_histos["leptons_deltaEta_parton"], "leptons_deltaEta_parton",   52, 0, 5.2);

      book(_histos["M_ttbar_parton"],    "M_ttbar_parton",      binedges_ttbar);

      for(unsigned int i = 0; i < Channels.size(); ++i){
	
      	std::string chan = Channels[i];
      	
      	book(_histos["cutflow_"+chan],    "cutflow_"+chan,  15,  0.5, 15.5);
      	
      	book(_histos["jet_pT_"+chan],     "jet_pT_"+chan,     binedges);
      	book(_histos["jet_eta_"+chan],    "jet_eta_"+chan,    binedges2);
      	book(_histos["jet_phi_"+chan],    "jet_phi_"+chan,    50, -6.3, 6.3);
      	
      	book(_histos["bjet_pT_"+chan],    "bjet_pT_"+chan,    binedges);
      	book(_histos["bjet_eta_"+chan],   "bjet_eta_"+chan,   binedges2);
      	book(_histos["bjet_phi_"+chan],   "bjet_phi_"+chan,   50, -6.3, 6.3);
      	
      	book(_histos["cjet_pT_"+chan],    "cjet_pT_"+chan,    binedges);
      	book(_histos["cjet_eta_"+chan],   "cjet_eta_"+chan,   binedges2);
      	book(_histos["cjet_phi_"+chan],   "cjet_phi_"+chan,   50, -6.3, 6.3);

      	book(_histos["ljet_pT_"+chan],    "ljet_pT_"+chan,    binedges);
      	book(_histos["ljet_eta_"+chan],   "ljet_eta_"+chan,   binedges2);
      	book(_histos["ljet_phi_"+chan],   "ljet_phi_"+chan,   50, -6.3, 6.3);

      	book(_histos["jet_1_pT_"+chan],   "jet_1_pT_"+chan,   binedges);
      	book(_histos["jet_1_eta_"+chan],  "jet_1_eta_"+chan,  binedges2);
      	book(_histos["jet_2_pT_"+chan],   "jet_2_pT_"+chan,   binedges);
      	book(_histos["jet_2_eta_"+chan],  "jet_2_eta_"+chan,  binedges2);
      	book(_histos["jet_3_pT_"+chan],   "jet_3_pT_"+chan,   binedges);
      	book(_histos["jet_3_eta_"+chan],  "jet_3_eta_"+chan,  binedges2);
      	book(_histos["jet_4_pT_"+chan],   "jet_4_pT_"+chan,   binedges);
      	book(_histos["jet_4_eta_"+chan],  "jet_4_eta_"+chan,  binedges2);

      	book(_histos["bjet_1_pT_"+chan],  "bjet_1_pT_"+chan,  binedges_bjet);
      	book(_histos["bjet_1_eta_"+chan], "bjet_1_eta_"+chan, binedges2);
      	book(_histos["bjet_2_pT_"+chan],  "bjet_2_pT_"+chan,  binedges_bjet);
      	book(_histos["bjet_2_eta_"+chan], "bjet_2_eta_"+chan, binedges2);
      	book(_histos["bjet_3_pT_"+chan],  "bjet_3_pT_"+chan,  binedges_bjet);
      	book(_histos["bjet_3_eta_"+chan], "bjet_3_eta_"+chan, binedges2);
      	book(_histos["bjet_4_pT_"+chan],  "bjet_4_pT_"+chan,  binedges_bjet);
      	book(_histos["bjet_4_eta_"+chan], "bjet_4_eta_"+chan, binedges2);

      	book(_histos["cjet_1_pT_"+chan],  "cjet_1_pT_"+chan,  binedges);
      	book(_histos["cjet_1_eta_"+chan], "cjet_1_eta_"+chan, binedges2);
      	book(_histos["cjet_2_pT_"+chan],  "cjet_2_pT_"+chan,  binedges);
      	book(_histos["cjet_2_eta_"+chan], "cjet_2_eta_"+chan, binedges2);

      	book(_histos["ljet_1_pT_"+chan],  "ljet_1_pT_"+chan,  binedges);
      	book(_histos["ljet_1_eta_"+chan], "ljet_1_eta_"+chan, binedges2);
      	book(_histos["ljet_2_pT_"+chan],  "ljet_2_pT_"+chan,  binedges);
      	book(_histos["ljet_2_eta_"+chan], "ljet_2_eta_"+chan, binedges2);

      	book(_histos["njet_10_"+chan],    "njet_10_"+chan,    31, -0.5, 30.5);
      	book(_histos["njet_25_"+chan],    "njet_25_"+chan,    21, -0.5, 20.5);
      	book(_histos["nbjet_25_"+chan],   "nbjet_25_"+chan,   21, -0.5, 20.5);
      	book(_histos["ncjet_25_"+chan],   "ncjet_25_"+chan,   21, -0.5, 20.5);
      	book(_histos["nljet_25_"+chan],   "nljet_25_"+chan,   21, -0.5, 20.5);

        book(_histos["elec_pT_"+chan],    "elec_pT_"+chan,   binedges_lepton);
        book(_histos["elec_eta_"+chan],   "elec_eta_"+chan,  binedges2);
        book(_histos["elec_phi_"+chan],   "elec_phi_"+chan,  100, -6.3,  6.3);
        book(_histos["elec_N_"+chan],     "elec_N_"+chan,     11, -0.5, 10.5);

        book(_histos["mu_pT_"+chan],      "mu_pT_"+chan,     binedges_lepton);
        book(_histos["mu_eta_"+chan],     "mu_eta_"+chan,    binedges2);
        book(_histos["mu_phi_"+chan],     "mu_phi_"+chan,    100, -6.3,  6.3);
        book(_histos["mu_N_"+chan],       "mu_N_"+chan,       11, -0.5, 10.5);
	
        book(_histos["lep1_pT_"+chan],    "lep1_pT_"+chan,  80,0,200);
        book(_histos["lep1_eta_"+chan],   "lep1_eta_"+chan, binedges2);
        book(_histos["lep1_phi_"+chan],   "lep1_phi_"+chan, 100, -6.3, 6.3);

      	book(_histos["lep2_pT_"+chan],    "lep2_pT_"+chan,  80,0,200);
      	book(_histos["lep2_eta_"+chan],   "lep2_eta_"+chan, binedges2);
      	book(_histos["lep2_phi_"+chan],   "lep2_phi_"+chan, 100, -6.3, 6.3);
      	
	      book(_histos["lep_pT_"+chan],    "lep_pT_"+chan,  binedges_lepton);
	      book(_histos["lep_eta_"+chan],   "lep_eta_"+chan, binedges2);
        book(_histos["lep_phi_"+chan],   "lep_phi_"+chan, 100, -6.3, 6.3);


      	//book(_histos["MET_"+chan],        "MET_"+chan,        binedges);
      	//book(_histos["MTW_"+chan],        "MTW_"+chan,        150,    0,  150);
      	//book(_histos["M_lepW_"+chan],     "M_lepW_"+chan,      binedges_W);
      	//book(_histos["M_lepT_"+chan],     "M_lepT_"+chan,      binedges_top);                                                                                     

      	//Mlb variations and corresponding pt's in the algorithm//
      	//Mlb reco produced from Andrea's top algorithm//
      	book(_histos["M_lbavg_"+chan],          "M_lbavg_"+chan,    80,0,200);
      	book(_histos["M_lb0_"+chan],            "M_lb0_"+chan,      80,0,200);
      	book(_histos["M_lb1_"+chan],            "M_lb1_"+chan,      80,0,200);
      	book(_histos["M_lb2_"+chan],            "M_lb2_"+chan,      80,0,200);

      	//Mlb perfect reco -matched with bhadrons and leptons according to their charge//
      	book(_histos["M_MlbtHigh_"+chan],       "M_MlbtHigh_"+chan,   80,0,200);
      	book(_histos["M_MlbtLow_"+chan],        "M_MlbtLow_"+chan,    80,0,200);
      	book(_histos["M_Mlbtop_"+chan],         "M_Mlbtop_"+chan,     80,0,200);
      	book(_histos["M_Mlbatop_"+chan],        "M_Mlbatop_"+chan,    80,0,200);


      	book(_histos["Pt2_Lep_Highptb_"+chan],   "Pt2_Lep_Highptb_"+chan, 80,0,500);
      	book(_histos["Pt2_Highptb_"+chan],       "Pt2_Highptb_"+chan, 80,0,500);
      	book(_histos["Pt2_Lowptb_"+chan],        "Pt2_Lowptb_"+chan, 80,0,500);
      	book(_histos["Pt2_Lep_Lowptb_"+chan],    "Pt2_Lep_Lowptb_"+chan, 80,0,500);

      	//Mlb reco -minAvg//
      	book(_histos["M_Mlbminavg0_"+chan],     "M_Mlbminavg0_"+chan, binedges_mlb);

      	book(_histos["M_Mlbminavg1_"+chan],     "M_Mlbminavg1_"+chan, binedges_mlb);
      	book(_histos["M_Mlbminavg2_"+chan],     "M_Mlbminavg2_"+chan, binedges_mlb);
      	book(_histos["M_Mlbminavg_"+chan],     "M_Mlbminavg_"+chan, binedges_mlb);

      	book(_histos["M_MLBminavg1_"+chan],     "M_MLBminavg1_"+chan, binedges_mlb);
      	book(_histos["M_MLBminavg2_"+chan],     "M_MLBminavg2_"+chan, binedges_mlb);


      	book(_histos["M_MLBcutminavg1_"+chan],     "M_MLBcutminavg1_"+chan, 80,0,200);
      	book(_histos["M_MLBcutminavg2_"+chan],     "M_MLBcutminavg2_"+chan, 80,0,200);

      	book(_histos["Pt_Lep_Highptb_"+chan],   "Pt_Lep_Highptb_"+chan, 80,0,500);
      	book(_histos["Pt_Highptb_"+chan],       "Pt_Highptb_"+chan, 80,0,500);
      	book(_histos["Pt_Lowptb_"+chan],        "Pt_Lowptb_"+chan, 80,0,500);
      	book(_histos["Pt_Lep_Lowptb_"+chan],    "Pt_Lep_Lowptb_"+chan, 80,0,500);
                                                                                                    
      	//End of Mlb 
      	//
      	//book(_histos["pT_lepT_"+chan],    "pT_lepT_"+chan,     binedges);
      	//book(_histos["pT_lepW_"+chan],    "pT_lepW_"+chan,     binedges);
      	//book(_histos["eta_lepT_"+chan],   "eta_lepT_"+chan,    binedges2);
      	//book(_histos["eta_lepW_"+chan],   "eta_lepW_"+chan,    binedges2);
      	//book(_histos["eta_T1_"+chan],     "eta_T1_"+chan,      binedges2);
      	//book(_histos["pT_T1_"+chan],      "pT_T1_"+chan,       binedges3);
      	//book(_histos["eta_T2_"+chan],     "eta_T2_"+chan,      binedges2);
      	//book(_histos["pT_T2_"+chan],      "pT_T2_"+chan,       binedges3);
	
       	book(_histos["dR1_"+chan],  "dR1_"+chan,   20, 0, 2.0);
       	book(_histos["dR2_"+chan],  "dR2_"+chan,   20, 0, 2.0);
	
       	book(_histos["cos_theta1_"+chan],  "cos_theta1_"+chan,   50, -5.0, 5.0);
       	book(_histos["cos_theta2_"+chan],  "cos_theta2_"+chan,   50, -5.0, 5.0);
	
		book(_histos["cos2_theta1_"+chan],  "cos2_theta1_"+chan,   20, -1.0, 1.0);
       	book(_histos["cos2_theta2_"+chan],  "cos2_theta2_"+chan,   20, -1.0, 1.0);
	

		book(_sumOfWeightsAboveEventweight1000, "SumOfWeightsAboveEventweight1000");


        // Dimbi 
        //book(_histos["inv_mass_mumu_ee_"+chan], "inv_mass_mumu_ee_"+chan, 80, 0, 400);
	
      }

      emuN=0;  
      evCount=0;
      countA=0;
      countB=0;
      countC=0;
      countD=0;
      countAl=0;
      countBl=0;
      countCl=0;
      countDl=0;
      lepVetoCount0=0;
      lepVetoCount1=0;
      njetVetoCount=0;
      bjetVetoCount=0;
      passnjetCount=0;
      passbjetCount=0;
      passlepCount0=0;
      passlepCount1=0;
      OSCount=0;
      mllCount=0;
    }
    
    /// Perform the per-event analysis
    void analyze(const Event& event) {

      //      int eNum = (event.genEvent()->event_number());
      
      _MerLB1minAv.clear();
      _MerLB2minAv.clear();
      
      _Mert1minAv.clear(); 
      _Mert2minAv.clear();
      _Mert1lep.clear();
      _Mert2lep.clear();
      _Mertlep.clear();
      _tlep.clear();
      _thad.clear();
      _ttbar.clear();

      int nTau = 0;
      int nEle = 0;
      int nMu  = 0;

      if ( getOption("SAMPLE") == "PWHG_ttbar_NLO_dec_421419" && event.genEvent()->weights().front() > 1000 ) { _sumOfWeightsAboveEventweight1000->fill(); vetoEvent; }


      //find W boson and count leptons stemming from W boson decay in event
      
      for(ConstGenParticlePtr p: HepMCUtils::particles(event.genEvent())) {

		  int absid = fabs(p->pdg_id());

		  /*
		  if(absid == 24){

		    // std::cout << "==========================================================================================" << std::endl;
		    // std::cout << "before" << std::endl;

		    ConstGenVertexPtr dv = p->end_vertex();

		    if (dv) {

		      //	      for(ConstGenParticlePtr pp: HepMCUtils::particles(dv, Relatives::CHILDREN)){


			std::cout << "before   " << p->status() << "\t" << p->pdg_id() << "\t" << (HepMCUtils::particles(dv, Relatives::CHILDREN)).size() << std::endl;

			for(ConstGenParticlePtr pp: HepMCUtils::particles(dv, Relatives::CHILDREN)){

			  std::cout << pp -> pdg_id()  << std::endl;
			  

			}



			//		      }
			
		    }

		    }*/

		  
		  if(absid != 24)
		    continue;
		  
		  ConstGenVertexPtr dv = p->end_vertex();
		  
		  if (dv) {
			  
			  for(ConstGenParticlePtr pp: HepMCUtils::particles(dv, Relatives::CHILDREN)){
				  
				  if(fabs(pp -> pdg_id()) == 11)
					  nEle += 1;
				  if(fabs(pp -> pdg_id()) == 13)
					  nMu += 1;
				  if(fabs(pp -> pdg_id()) == 15)
					  nTau += 1;
			  }
		  }
      }
      /**
	   //find W boson coming from top decay and count leptons stemming from W boson decay in event
	   for(ConstGenParticlePtr p: HepMCUtils::particles(event.genEvent())) {
	   
	   int absid = fabs(p->pdg_id());
	   
	   if(absid != 6) {continue; }
	   ConstGenVertexPtr topV = p->end_vertex();
	   if(topV)
	   {
            bool decayedTop=false;
            while(!decayedTop)
            {
                  decayedTop=true;
                  for(ConstGenParticlePtr pp: HepMCUtils::particles(topV, Relatives::CHILDREN)){
                        if(fabs(pp-> pdg_id()) == 6 ) {decayedTop = false; topV = pp->end_vertex(); break; }
                        if(fabs(pp-> pdg_id()) == 24) 
                        {
                              //this is the looked for W boson, also here look for last W boson before decay
                              ConstGenVertexPtr wV = pp->end_vertex();
                              if(!wV) break; 
                              bool decayedW = false;
                              while(!decayedW)
                              {
                                    for(ConstGenParticlePtr ppp: HepMCUtils::particles(wV, Relatives::CHILDREN)){
                                          if(fabs(ppp-> pdg_id()) == 24 ) {decayedW = false; wV = ppp->end_vertex(); break; }
                                          if(fabs(ppp -> pdg_id()) == 11) nEle += 1;
                                          if(fabs(ppp -> pdg_id()) == 13) nMu += 1;
                                          if(fabs(ppp -> pdg_id()) == 15) nTau += 1;
                                    }
                                    if(!wV) {break; }
                              }
                        }
                  }
                  if(!topV) {break; }
            }

        }

      }**/
      
      if(nEle == 2)
        _histos["Wdecay_channels"] -> fill(0);
      if(nMu == 2)
        _histos["Wdecay_channels"] -> fill(1);
      if(nTau == 2)
        _histos["Wdecay_channels"] -> fill(2);
      if(nEle == 1 && nMu == 1)
        _histos["Wdecay_channels"] -> fill(3);
      if(nEle == 1 && nTau == 1)
		  _histos["Wdecay_channels"] -> fill(4);
      if(nMu == 1 && nTau == 1)
		  _histos["Wdecay_channels"] -> fill(5);
	  
      // DIMBI: apply here the cut you want to use 
      //commented K Voss 30.11.22
      //if(nEle == 2 || nMu == 2 || nTau == 2)
	  //vetoEvent;
      //K Voss look at dilepton events
      // or don't apply any cut?
      //if( nEle + nMu + nTau != 2) vetoEvent; 
      //-> don't do this since this includes also leptons from HF decay (if only for W is checked, check also for top -> W )
	  
      // get now parton level information
      const Particles partonicTops = apply<PartonicTops>( event, "partonicTops").particlesByPt();
      
      //      std::cout << "====================================================================================" << std::endl;
      
      Particle top, tbar;
      bool foundT = false, foundTBar = false;

      for (const Particle& ptop : partonicTops) {

		  const int pid = ptop.pid();

		  //	  std::cout << ptop.genParticle()->status() << "\t" << pid << "\t" << (top.children()).size() << std::endl;

		  if(ptop.genParticle()->status() == 20)
			  continue;
		  
		  if (pid == PID::TQUARK) {
			  top = ptop;
			  // std::cout << "found top" << "\t" << ptop.genParticle()->status() << "\t" << pid << std::endl;
			  foundT = true;
		  } else if (pid == -PID::TQUARK) {
			  tbar = ptop;
			  // std::cout << "found antitop" << "\t" << ptop.genParticle()->status()  << "\t" << pid << std::endl;
			  foundTBar = true;
		  }
      }
	  
      Particle lep_plus;
      Particle lep_neg;

      bool have_lep_plus = false;
      bool have_lep_neg  = false;

      bool is_parton_tau = false;
      
      if(nTau > 0)
	is_parton_tau = true;
      
      for (const Particle& son : top.children()) {
	
	if (son.abspid() == 24) {
	  
	  // now get the W after FSR:
	  Particle son_afterFSR = findAfterFSR(son);
	  
	  if(son_afterFSR.abspid() == 24){
	    for (const Particle& sonW : son_afterFSR.children()) {
	      

	      //	      std::cout << sonW.pid() << std::endl;

	      if (sonW.abspid() == 11 || sonW.abspid() == 13 || sonW.abspid() == 15) {
		have_lep_plus = true;
		lep_plus = sonW;  // findAfterFSR(sonW);
	      }
	    } 
	  }
	}
      }
	  
      for (const Particle& son : tbar.children()) {
	
	if (son.abspid() == 24) {
	  
	  // now get the W after FSR:                                                                                                                                                                    
	  Particle son_afterFSR = findAfterFSR(son);
	  
	  if(son_afterFSR.abspid() == 24){
	    for (const Particle& sonW : son_afterFSR.children()) {
	      
	      if (sonW.abspid() == 11 || sonW.abspid() == 13 || sonW.abspid() == 15) {
		have_lep_neg = true;
		lep_neg = sonW; // findAfterFSR(sonW);
	      }
	    } 
	  } 
	}	  
      }
      
      
      FourMomentum Top_parton      = top.momentum();
      FourMomentum Antitop_parton  = tbar.momentum();
      FourMomentum lep_plus_parton = lep_plus.momentum();
      FourMomentum lep_neg_parton  = lep_neg.momentum();
      
      FourMomentum TTbar_parton    = Top_parton+Antitop_parton;

      float cosphi_parton = cos_phi(lep_plus_parton, lep_neg_parton, Top_parton, Antitop_parton);

      // std::cout << cosphi_parton << std::endl;
      //std::cout << Top_parton.mass() << "\t" << Antitop_parton.mass() << std::endl;
      //std::cout << have_lep_plus << "\t" << have_lep_neg << std::endl;
      //std::cout << lep_plus_parton.mass() << "\t" << lep_neg_parton.mass() << std::endl;
      //std::cout << "is parton tau " << is_parton_tau << std::endl; 

      if(!is_parton_tau){
	
	_histos["cos_phi_parton"] -> fill(cosphi_parton);
	if(TTbar_parton.mass()/GeV < 380.0)
	  _histos["cos_phi_s380_parton"] -> fill(cosphi_parton);
	else
	  _histos["cos_phi_l380_parton"]-> fill(cosphi_parton);
	
	if(TTbar_parton.mass()/GeV < 390.0)
	  _histos["cos_phi_s390_parton"] -> fill(cosphi_parton);
	if(TTbar_parton.mass()/GeV < 400.0)
	  _histos["cos_phi_s400_parton"] -> fill(cosphi_parton);
	if(TTbar_parton.mass()/GeV < 410.0)
	  _histos["cos_phi_s410_parton"] -> fill(cosphi_parton);
	
	if(nEle == 1 && nMu == 1){
	  
	  _histos["cos_phi_emu_parton"] -> fill(cosphi_parton);
	  
	  if(TTbar_parton.mass()/GeV < 380.0)
	    _histos["cos_phi_s380_emu_parton"]-> fill(cosphi_parton);
	  else
	    _histos["cos_phi_l380_emu_parton"]-> fill(cosphi_parton);
	  
	}
	
	if(nEle == 2 && nMu == 0){
	  
	  _histos["cos_phi_ee_parton"] -> fill(cosphi_parton);
	  
	  if(TTbar_parton.mass()/GeV < 380.0){
	    _histos["cos_phi_s380_ee_parton"]-> fill(cosphi_parton);
	  }
	  else{
	    _histos["cos_phi_l380_ee_parton"]-> fill(cosphi_parton);
	  }
	  
	}
	
	if(nEle == 0 && nMu == 2){
	  
	  _histos["cos_phi_mumu_parton"] -> fill(cosphi_parton);
	  
	  if(TTbar_parton.mass()/GeV < 380.0)
	    _histos["cos_phi_s380_mumu_parton"]-> fill(cosphi_parton);
	  else
	    _histos["cos_phi_l380_mumu_parton"]-> fill(cosphi_parton);
	  
	}
	
	_histos["leptons_deltaR_parton"]      -> fill(deltaR(lep_plus_parton,   lep_neg_parton));
	
	if(nEle == 2 && nMu == 0)
	  _histos["leptons_deltaPhi_parton_ee"]   -> fill(deltaPhi(lep_plus_parton,   lep_neg_parton));
	if(nEle == 1 && nMu == 1)
	  _histos["leptons_deltaPhi_parton_emu"]  -> fill(deltaPhi(lep_plus_parton,   lep_neg_parton));
	if(nEle == 0 && nMu == 2)
	  _histos["leptons_deltaPhi_parton_mumu"] -> fill(deltaPhi(lep_plus_parton,   lep_neg_parton));
	
	_histos["leptons_deltaPhi_parton"] -> fill(deltaPhi(lep_plus_parton, lep_neg_parton));
	_histos["leptons_deltaEta_parton"] -> fill(deltaEta(lep_plus_parton, lep_neg_parton));
	_histos["M_ttbar_parton"]   -> fill(TTbar_parton.mass()/GeV);
	
      }
      

      // Retrieve dressed leptons, sorted by pT
      // vector<DressedLepton> electrons = apply<DressedLeptons>(event, "electrons").dressedLeptons();
      // vector<DressedLepton> muons = apply<DressedLeptons>(event, "muons").dressedLeptons();
      DressedLeptons electrons = apply<LeptonFinder>(event, "electrons").dressedLeptons(); 
      DressedLeptons muons = apply<LeptonFinder>(event, "muons").dressedLeptons();
      // Retrieve clustered jets, sorted by pT, with a minimum pT cut
      Jets jets = apply<FastJets>(event, "jets").jetsByPt(Cuts::pT > 25*GeV && Cuts::abseta < 2.5);
      FourMomentum met = apply<MissingMomentum>(event, "MissingMomentum").missingMomentum();

      // Retrieve prompt neutrinos 
      Particles listNeutrinos = apply<PromptFinalState>(event, "Neutrinos").particlesByPt();
    
      // OVERLAP REMOVAL
      idiscardIfAnyDeltaRLess(muons, jets, 0.4);
      idiscardIfAnyDeltaRLess(electrons, jets, 0.4);
      
      // Select jets ghost-associated to B-hadrons with a certain fiducial selection 
      // filter_select -> select (rivet 4)
      Jets bjets = select(jets, [](const Jet& jet) {
			  return  jet.bTagged(Cuts::pT > 5*GeV);
		  });
      
      vector<DressedLepton> leptons;
      for (auto &lep : muons) { leptons.push_back(lep); }
      for (auto &lep : electrons) { leptons.push_back(lep); }
      
      //FourMomentum met;
      //for (const auto& p : neutrinos)  met += p.momentum();
	  
      
      /*bool pass_emu =
        // 2 leptons > 28 GeV
        (leptons.size() == 2) &&
        (leptons[0].pT() > 28*GeV && leptons[1].pT() > 28*GeV) &&
        // emu events
        ((leptons[0].abspid() == 11 && leptons[1].abspid() == 13) ||
         (leptons[0].abspid() == 13 && leptons[1].abspid() == 11)) &&
        // opposite charge
        (leptons[0].charge() != leptons[1].charge()); */
      
      
      // vector<DressedLepton> good_electrons;                                                                                                                                                                 
      //vector<DressedLepton> good_muons;
      
      //for(auto &lep : leptons){
      //if(lep.abspid() == 11)
      //  good_electrons.push_back(lep);
	
      //if(lep.abspid() == 13)
      //  good_muons.push_back(lep);
      //}
      
      //vector<DressedLepton> good_leptons;
      //good_leptons = good_electrons+good_muons;
      
      int nGoodEle = electrons.size();
      int nGoodMu  = muons.size();

      //here only electron and muon selection -> change to also include tau?
      if(nGoodEle+nGoodMu != 2)
		  vetoEvent;
      
      /*if(!(good_electrons.size()==1)) 
	{lepVetoCount0++;   
	  vetoEvent;  }
      else{
	passlepCount0++;
      }
      
      if(!(good_muons.size()==1)) {
	lepVetoCount1++;  
	vetoEvent;  }
      else
	passlepCount1++;
      
      */


      if(jets.size() < 2)
		  vetoEvent;
      else
		  passnjetCount++;
      //OSCount=0;
      //mllCount=0;
      
      
      if((bjets.size()<1)) {
		  bjetVetoCount++; 
		  vetoEvent; }
      else
		  passbjetCount++;
      
      if(leptons[0].charge() == leptons[1].charge())
		  vetoEvent;
      else
		  OSCount++;
	  
      // ANDREA: only for now, as a cross-check
      //commented out by K Voss to also allow same flavour ee mumu pairs
      //if(nGoodEle == 2 || nGoodMu == 2)
	//vetoEvent;
      
      //if((electrons[0].momentum()+muons[0].momentum()).mass() < 15.0/GeV)
      //vetoEvent;
      //else
      //mllCount++;
      
      // emu : veto events from tautau
      //if (nGoodEle == 1 || nGoodMu == 1) {
        //std::cout << "emu" << std::endl;
      //  int countLeptonsFromTau(0);
      //  for (auto & lep : leptons) {
      //    if (lep.hasParent(15) || lep.hasParent(-15) ) {
      //      countLeptonsFromTau += 1; 
      //    }
      //  }
        //std::cout << "countLeptonsFromTau = " << countLeptonsFromTau << std::endl;
      //  if (countLeptonsFromTau == 2) vetoEvent; 
      //}


      // ANDREA: cut away Z+jets and gamma+jets events (should not make a difference here, but hey, why not)
      if(nGoodEle == 2 || nGoodMu == 2){
             
        // Veto same flavour channel where each lepton is from a W boson decay
        //int countPromptElec(0), countPromptMu(0);
        //if (nGoodEle == 2) {
        //  for (auto & elec : electrons) {
        //    for (auto & p : elec.parents() ) {
              //std::cout << "parent pid = " << p.pid() << std::endl;
        //      if (p.abspid() == 24) countPromptElec += 1;
        //    }
        //  } 
        //}
  
        //if (nGoodMu == 2) {
        //  for (auto & mu : muons) {
        //    for (auto & p : mu.parents() ) {
        //      std::cout << "parent pid = " << p.pid() << std::endl;
        //      if (p.abspid() == 24) countPromptMu += 1;
        //    }
        //  }
        //}

        //std::cout << "countPromptElec = " << countPromptElec << ", countPromptMu = " << countPromptMu << std::endl;
        //if (countPromptElec == 2 || countPromptMu == 2) vetoEvent;

		  float inv_mass = (leptons[0].momentum()+leptons[1].momentum()).mass();
		  
		  _histos["pass_mumu_ee"] -> fill(1);
		  
		  //if(inv_mass < 15.0/GeV)
		  //	  vetoEvent;
		  
		  _histos["pass_mumu_ee"] -> fill(2);
		  
		  if(inv_mass > 81.0/GeV && inv_mass < 101.0/GeV)
			  vetoEvent;
		  
		  _histos["pass_mumu_ee"] -> fill(3);
		  _histos["inv_mass_mumu_ee"] -> fill(inv_mass); 
		  
		  //if(met.Et()/GeV < 60.0/GeV)
		  //	  vetoEvent;
		  
		  _histos["pass_mumu_ee"] -> fill(4);
		  _histos["inv_mass_mumu_ee_afterMetCut"] -> fill(inv_mass);
		  _histos["met_mumu_ee"] -> fill(met.Et());
		  
      }
	  

      // ANDREA: reconstruct ttbar system
      if(listNeutrinos.size() >= 2)
		  ReconstructDileptonW(leptons, listNeutrinos, bjets, jets, nGoodEle, nGoodMu);

      //reco MinAvg Mlb 
      ReconstructDileptonMlb(leptons, bjets, jets);
	  

      int n25 = jets.size();
      
      int nGoodJets = jets.size();
      int nBJets    = bjets.size();
      
      std::string chan_help = "dilepton";
      
      for(unsigned int iLep = 0; iLep < electrons.size(); ++iLep){
		  _histos["elec_pT_"+chan_help]    -> fill(electrons[iLep].momentum().pT()/GeV);
		  _histos["elec_eta_"+chan_help]   -> fill(electrons[iLep].momentum().eta());
		  _histos["elec_phi_"+chan_help]   -> fill(electrons[iLep].momentum().phi());
      }
      _histos["elec_N_"+chan_help]       -> fill(electrons.size());
      
      for(unsigned int iLep = 0; iLep < muons.size(); ++iLep){
		  
		  _histos["mu_pT_"+chan_help]    -> fill(muons[iLep].momentum().pT()/GeV);
		  _histos["mu_eta_"+chan_help]   -> fill(muons[iLep].momentum().eta());
		  _histos["mu_phi_"+chan_help]   -> fill(muons[iLep].momentum().phi());
      }
      _histos["mu_N_"+chan_help]       -> fill(muons.size());
	  
      for(unsigned int iLep = 0; iLep < leptons.size(); ++iLep){
		  _histos["lep_pT_"+chan_help]    -> fill(leptons[iLep].momentum().pT()/GeV);
		  _histos["lep_eta_"+chan_help]   -> fill(leptons[iLep].momentum().eta());
		  _histos["lep_phi_"+chan_help]   -> fill(leptons[iLep].momentum().phi());
      }
	  
      /**
		 _histos["lep_pT_"+chan_help]    -> fill(electrons[0].momentum().pT()/GeV);
		 _histos["lep_eta_"+chan_help]   -> fill(electrons[0].momentum().eta());
		 _histos["lep_phi_"+chan_help]   -> fill(electrons[0].momentum().phi());
		 _histos["lep_pT_"+chan_help]    -> fill(muons[0].momentum().pT()/GeV);
		 _histos["lep_eta_"+chan_help]   -> fill(muons[0].momentum().eta());
		 _histos["lep_phi_"+chan_help]   -> fill(muons[0].momentum().phi());**/

      if(leptons[0].momentum().pT() > leptons[1].momentum().pT()){
		  
		  _histos["lep1_pT_"+chan_help]    -> fill(leptons[0].momentum().pT()/GeV);
		  _histos["lep1_eta_"+chan_help]   -> fill(leptons[0].momentum().eta());
		  _histos["lep1_phi_"+chan_help]   -> fill(leptons[0].momentum().phi());
		  
		  _histos["lep2_pT_"+chan_help]    -> fill(leptons[1].momentum().pT()/GeV);
		  _histos["lep2_eta_"+chan_help]   -> fill(leptons[1].momentum().eta());
		  _histos["lep2_phi_"+chan_help]   -> fill(leptons[1].momentum().phi());
		  
      }
      else{
		  
		  _histos["lep1_pT_"+chan_help]    -> fill(leptons[1].momentum().pT()/GeV);
		  _histos["lep1_eta_"+chan_help]   -> fill(leptons[1].momentum().eta());
		  _histos["lep1_phi_"+chan_help]   -> fill(leptons[1].momentum().phi());
		  
		  _histos["lep2_pT_"+chan_help]    -> fill(leptons[0].momentum().pT()/GeV);
		  _histos["lep2_eta_"+chan_help]   -> fill(leptons[0].momentum().eta());
		  _histos["lep2_phi_"+chan_help]   -> fill(leptons[0].momentum().phi());
		  
      }
	  

      // fill jet histos
      _histos["njet_25_"+chan_help] -> fill(n25);
      
      _histos["nbjet_25_"+chan_help]   -> fill(nBJets);
      
      if(jets.size() > 0){
	_histos["jet_1_pT_"+chan_help]  -> fill(jets[0].momentum().pT()/GeV);
	_histos["jet_1_eta_"+chan_help] -> fill(jets[0].momentum().eta());
      }
      if(jets.size() > 1){
	_histos["jet_2_pT_"+chan_help]  -> fill(jets[1].momentum().pT()/GeV);
	_histos["jet_2_eta_"+chan_help] -> fill(jets[1].momentum().eta());
      }
      if(jets.size() > 2){
	_histos["jet_3_pT_"+chan_help]  -> fill(jets[2].momentum().pT()/GeV);
	_histos["jet_3_eta_"+chan_help] -> fill(jets[2].momentum().eta());
      }
      if(jets.size() > 3){
	_histos["jet_4_pT_"+chan_help]  -> fill(jets[3].momentum().pT()/GeV);
	_histos["jet_4_eta_"+chan_help] -> fill(jets[3].momentum().eta());
      }
      if(bjets.size() > 0){
	_histos["bjet_1_pT_"+chan_help]  -> fill(bjets[0].momentum().pT()/GeV);
	_histos["bjet_1_eta_"+chan_help] -> fill(bjets[0].momentum().eta());
      }
      if(bjets.size() > 1){
	_histos["bjet_2_pT_"+chan_help]  -> fill(bjets[1].momentum().pT()/GeV);
	_histos["bjet_2_eta_"+chan_help] -> fill(bjets[1].momentum().eta());
      }
      if(bjets.size() > 2){
	_histos["bjet_3_pT_"+chan_help]  -> fill(bjets[2].momentum().pT()/GeV);
	_histos["bjet_3_eta_"+chan_help] -> fill(bjets[2].momentum().eta());
      }
      if(bjets.size() > 3){
	_histos["bjet_4_pT_"+chan_help]  -> fill(bjets[3].momentum().pT()/GeV);
	_histos["bjet_4_eta_"+chan_help] -> fill(bjets[3].momentum().eta());
      }
      if(good_cjets.size() > 0){
	_histos["cjet_1_pT_"+chan_help]  -> fill(good_cjets[0].momentum().pT()/GeV);
	_histos["cjet_1_eta_"+chan_help] -> fill(good_cjets[0].momentum().eta());
      }
      if(good_cjets.size() > 1){
	_histos["cjet_2_pT_"+chan_help]  -> fill(good_cjets[1].momentum().pT()/GeV);
	_histos["cjet_2_eta_"+chan_help] -> fill(good_cjets[1].momentum().eta());
      }
      if(good_ljets.size() > 0){
	_histos["ljet_1_pT_"+chan_help]  -> fill(good_ljets[0].momentum().pT()/GeV);
	_histos["ljet_1_eta_"+chan_help] -> fill(good_ljets[0].momentum().eta());
      }
      if(good_ljets.size() > 1){
	_histos["ljet_2_pT_"+chan_help]  -> fill(good_ljets[1].momentum().pT()/GeV);
	_histos["ljet_2_eta_"+chan_help] -> fill(good_ljets[1].momentum().eta());
      }
      
      for(int iJet = 0; iJet < nGoodJets; ++iJet){
	
	_histos["jet_pT_"+chan_help]  -> fill(jets[iJet].momentum().pT()/GeV);
	_histos["jet_eta_"+chan_help] -> fill(jets[iJet].momentum().eta());
	_histos["jet_phi_"+chan_help] -> fill(jets[iJet].momentum().phi());
	
      }
      
      for(int iJet = 0;iJet < nBJets; ++iJet){
	
	_histos["bjet_pT_"+chan_help]  -> fill(bjets[iJet].momentum().pT()/GeV);
	_histos["bjet_eta_"+chan_help] -> fill(bjets[iJet].momentum().eta());
	_histos["bjet_phi_"+chan_help] -> fill(bjets[iJet].momentum().phi());
	
      }
      // fill neutrino histo
      _histos["neutrino_multiplicity"] -> fill(listNeutrinos.size());

      for(unsigned int iNeutrino = 0; iNeutrino < listNeutrinos.size(); iNeutrino++) {
        _histos["neutrino_pT"] -> fill(listNeutrinos[iNeutrino].momentum().pT()/GeV);
        _histos["neutrino_eta"] -> fill(listNeutrinos[iNeutrino].momentum().eta());
        _histos["neutrino_phi"] -> fill(listNeutrinos[iNeutrino].momentum().phi());
      }
      
      if (listNeutrinos.size() > 0) {
        _histos["neutrino_1_pT"] -> fill(listNeutrinos[0].momentum().pT()/GeV);
        _histos["neutrino_1_eta"] -> fill(listNeutrinos[0].momentum().eta());
        _histos["neutrino_1_phi"] -> fill(listNeutrinos[0].momentum().phi());
      }

      if (listNeutrinos.size() > 1) { 
        _histos["neutrino_2_pT"] -> fill(listNeutrinos[1].momentum().pT()/GeV);
        _histos["neutrino_2_eta"] -> fill(listNeutrinos[1].momentum().eta());
        _histos["neutrino_2_phi"] -> fill(listNeutrinos[1].momentum().phi());                                                                                         
      }

      float sumNeutrinosPt = 0;
      for(unsigned int iNeutrino = 0; iNeutrino < listNeutrinos.size(); iNeutrino++) {
        sumNeutrinosPt += listNeutrinos[iNeutrino].momentum().pT()/GeV;
      }

      //std::cout << sumNeutrinosPt << " == " << met.Et() << std::endl;

      // fill MET: all channels 
      _histos["met_allChannels"] -> fill(met.Et());

      // fill H_T 
      float H_T = 0;
      for(int iJet = 0; iJet < nGoodJets; ++iJet){
        H_T += jets[iJet].momentum().pT()/GeV;
      }
      for(unsigned int iLep = 0; iLep < electrons.size(); ++iLep){
        H_T += electrons[iLep].momentum().pT()/GeV; 
      }
      
      float H_T_usingMet = H_T + met.Et();
      _histos["H_T_usingMet"] -> fill(H_T_usingMet);
      
      float H_T_usingNeutrinos = H_T; 
      for(unsigned int iNeutrino = 0; iNeutrino < listNeutrinos.size(); iNeutrino++) {
        H_T_usingNeutrinos += listNeutrinos[iNeutrino].momentum().pT()/GeV;
      }
      _histos["H_T_usingNeutrinos"] -> fill(H_T_usingNeutrinos);

      //      _histos["Pt2_Highptb_"+chan_help]        -> fill(_pt2b1); 
      //      _histos["Pt2_Lep_Highptb_"+chan_help]    -> fill(_pt2lep1);     
      _histos["M_Mlbminavg_"+chan_help]     -> fill(_Mert0minAv); 
      
      _histos["M_Mlbminavg1_"+chan_help]    -> fill(_Mert1minAv[0].mass()); 
      _histos["M_Mlbminavg2_"+chan_help]    -> fill(_Mert2minAv[0].mass()); 
      
      _histos["M_MLBminavg1_"+chan_help]    -> fill(_MerLB1minAv[0].mass()); 
      _histos["M_MLBminavg2_"+chan_help]    -> fill(_MerLB2minAv[0].mass()); 
      
      _histos["Pt_Highptb_"+chan_help]      -> fill(_ptb1); 
      _histos["Pt_Lep_Highptb_"+chan_help]  -> fill(_ptlep1); 
      
      if(ptlbL > 180) _histos["M_MLBcutminavg2_"+chan_help]    -> fill(_MerLB2minAv[0].mass()); 
      if(ptlbH > 180) _histos["M_MLBcutminavg1_"+chan_help]    -> fill(_MerLB1minAv[0].mass()); 
      
      //the same as _histos["M_Mlbminavg_"+chan_help]     -> fill(_Mert0minAv); 
      _histos["M_Mlbminavg0_"+chan_help]    -> fill((_Mert1minAv[0].mass()+_Mert2minAv[0].mass())/2); 
      //      _histos["Pt2_Lowptb_"+chan_help]         -> fill(_pt2b2); 
      //      _histos["Pt2_Lep_Lowptb_"+chan_help]     -> fill(_pt2lep2); 
      
      _histos["Pt_Lowptb_"+chan_help]         -> fill(_ptb2); 
      _histos["Pt_Lep_Lowptb_"+chan_help]     -> fill(_ptlep2); 
      
      _histos["cos_theta1_"+chan_help]->fill(costheta1); 
      _histos["cos_theta2_"+chan_help]->fill(costheta2); 
      
      
      _histos["cos2_theta1_"+chan_help]->fill(cost1); 
      _histos["cos2_theta2_"+chan_help]->fill(cost2); 
      
      
     _histos["dR2_"+chan_help]->fill(dR1); 
     _histos["dR1_"+chan_help]->fill(dR2); 
     
     
     //      std::cout << "ptb1: "<<_ptb1  << std::endl;
     //      std::cout << "ptb2: "<<_ptb2  << std::endl;
     //      std::cout << "pt2b1: "<<_pt2b1  << std::endl;
     //      std::cout << "_Mert2minAv[0].mass(): "<<_Mert2minAv[0].mass()  << std::endl;
     //      std::cout << "_Mert1minAv[0].mass(): "<<_Mert1minAv[0].mass()  << std::endl;
     //      }
     //      cout << "mll8 -- " << eNum << "\t" << std::endl;
     
    }
    
    /// Normalise histograms etc., after the run
    void finalize() {
      
      std::cout << "n(elec) == 1 -- " << passlepCount0 << std::endl;
      std::cout << "n(muon) == 1 -- " << passlepCount1 << std::endl;
      std::cout << "n(jet)  >= 2 -- " << passnjetCount << std::endl;
      std::cout << "n(bjet) == 2 -- " << passbjetCount << std::endl;
      std::cout << "OS              " << OSCount  << std::endl;
      std::cout << "mll > 15        " << mllCount << std::endl;
 
      
      std::cout << "crossSection: " << crossSection() << " sumofWeights: "<< sumOfWeights() << std::endl;
      double scalefactor(crossSection()/sumOfWeights());
      if(getOption("SAMPLE") == "PWHG_ttbar_NLO_dec_421419") 
      {
        scalefactor = crossSection() / (sumOfWeights() -  _sumOfWeightsAboveEventweight1000->sumW() );
        std::cout << "sumOfWeightsAboveEventweight1000: " << _sumOfWeightsAboveEventweight1000->sumW() << std::endl;
      }
      std::cout << "scalefactor: " << scalefactor << std::endl;
      
      
      for (std::map<std::string, Histo1DPtr >::iterator hit=_histos.begin(); hit!=_histos.end();hit++){
	
	if(hit->second->integral() > 0)
	  scale(hit->second,scalefactor);
	
      }
      
    }
    
    //@}
    
  private:
    
    std::string Channel;
    
    Jets bjets, good_ljets, jets, good_cjets;
    
    /// @name Objects that are used by the event selection decisions
    //@{
    vector<DressedLepton> _dressedelectrons;
    vector<DressedLepton> _vetodressedelectrons;
    vector<DressedLepton> _dressedmuons;
    vector<DressedLepton> _vetodressedmuons;
    Particles neutrinos;
    //    Particles charged25;
    //    Particles charged50;
    //  Jets _jets;
    unsigned int _jet_ntag;
    /// @todo Why not store the whole MET FourMomentum?
    double _met_et, _met_phi;

    double _pt_el, _eta_el, _pt_mu, _eta_mu, _eta_C, _pt_lep, _eta_lep;
    double _pt_isoT_mu, _R_isoT_mu, _pt_isoT_el, _R_isoT_el;
    double _pt_isoC_mu, _R_isoC_mu, _pt_isoC_el, _R_isoC_el;
    double _ETmiss, _ETmissMW;
    int    _Njets,_Ntags,_Nlept;
    double _pt_j, _eta_j, _R_j, _R_j_mu;
    double _MT, _MW, _dR_e_j, _dR_l_j;
    double _reco_sig_MTlep, _reco_sig_MW;
    double dRL1, dRL2, dRaL1, dRaL2;
    double dRBb1, dRBb2, dRaBb1, dRaBb2;
    double mindRBb1, mindRBb2, mindRaBb1, mindRaBb2;
    double mindRL1, mindRL2, mindRaL1, mindRaL2;
    unsigned int countA, countB, countC, countD, evCount,emuN;
    unsigned int lepVetoCount0,lepVetoCount1, bjetVetoCount,passlepCount0, passlepCount1, passnjetCount,passbjetCount; 
    unsigned int countAl, countBl, countCl, countDl; 
    unsigned int njetVetoCount, OSCount, mllCount;
 
    size_t       _b_thad, _b_tlep, _l_W1, _l_W2, _take;
    FourMomentum _plep, _pmiss, _Wlep[2], _Wlep_fin[2], _Wlepwin, _Whad, _Whad1,_Whad2;
    //  FourMomentum _pneus[2];
    //  ParticleVector _neu_all;

    FourMomentum Mlbtop, Mlbatop, MlbtHigh, MlbtLow;
    double _ptb1, _ptb2;
    double _ptlep1, _ptlep2;

    double _pt2b1, _pt2b2;
    double _pt2lep1, _pt2lep2;

    double ptlbL, ptlbH;

    double _Mert0minAv;

    double costheta1, costheta2, cost1, cost2, dR1,dR2; 
    std::vector<FourMomentum> _Mertlepavg,  _Mert1minAv,_Mert2minAv,  _Mertlep,_Mert1lep, _Mert2lep, _tlep, _thad, _ttbar, _MerLB1minAv, _MerLB2minAv;

    std::map<std::string, Histo1DPtr > _histos;

    std::vector<std::string> Channels;

    //use counter to sum up eventweights larger then 1000 for ttbar NLO dec sample
    CounterPtr _sumOfWeightsAboveEventweight1000;

    double _transMass(double ptLep, double phiLep, double met, double phiMet) {
      return sqrt(2.0*ptLep*met*(1 - cos(phiLep-phiMet)));
    }


    bool passMETcut(float met_val, float cut){

      if(met_val < cut)
	return false;

      return true;

    }

    // from ttbb code of ttH group, written by Durham

    bool GetWlep(FourMomentum lepton, FourMomentum p_miss, float ) {
  
      // from pseudo top: Define the leptonic W by combining the lepton with the ETmiss and solving for pz assuming the W mass (highest pz from two-fold ambiguity) 

      double pz1  = 0.0;
      double pz2  = 0.0;
      double px_c = lepton.px(); double py_c = lepton.py(); double pz_c = lepton.pz(); double Ec   = lepton.E();

      double mLep = 0.0;
      
      double px_nu = p_miss.px();
      double py_nu = p_miss.py();
      double alpha = _MW*_MW - mLep*mLep + 2*(px_c*px_nu + py_c*py_nu);
      
      double a = pz_c*pz_c - Ec*Ec;
      double b = alpha* pz_c;
      double c = - Ec*Ec* (px_nu*px_nu + py_nu*py_nu) + alpha*alpha/4.;
      
      double discriminant = b*b - 4*a*c;
      if (discriminant < 0.)
	return false;
      
      double pz_offset = - b / (2*a);
      
      double squareRoot = sqrt(discriminant);
      if(squareRoot < 1.e-6)
	pz1 = pz_offset;
      else{

	pz1 = pz_offset + squareRoot / (2*a);
	pz2 = pz_offset - squareRoot / (2*a);

      }
      
      double Energy1 = sqrt(px_nu*px_nu+py_nu*py_nu+pz1*pz1);
      double Energy2 = sqrt(px_nu*px_nu+py_nu*py_nu+pz2*pz2);

      FourMomentum nu1;  nu1.setPx(px_nu);  nu1.setPy(py_nu);  nu1.setPz(pz1);  nu1.setE(Energy1);
      FourMomentum nu2;  nu2.setPx(px_nu);  nu2.setPy(py_nu);  nu2.setPz(pz2);  nu2.setE(Energy2);

      _Wlep_fin[0] = lepton+nu1;

      if(squareRoot > 1.e-6){

	_Wlep_fin[1] = lepton;

      }

      return true;

    }

	  void ReconstructDileptonW(vector<DressedLepton> lep, Particles neu, Jets bjets, Jets jets, int n_el, int n_mu){

      FourMomentum neu1;
      FourMomentum neu2;
      FourMomentum Wpos;
      FourMomentum Wneg;

      FourMomentum lep_pos;
      FourMomentum lep_neg;

      if(lep[0].charge() > 0){
	lep_pos = lep[0].momentum();
	lep_neg = lep[1].momentum();
      }
      else{
	lep_pos = lep[1].momentum();
	lep_neg = lep[0].momentum();
      }

      int counter = 0;
      for(const Particle& p : neu){

	//	std::cout << p.momentum().pT() << std::endl;

	if(counter == 0)
	  neu1 = p.momentum();
	if(counter == 1)
          neu2 = p.momentum();
	counter += 1;
      }

      //std::cout << "bla 3" << std::endl;

      //std::cout << neu1.pT() << "\t" << neu2.pT() << std::endl;

      // now look at each possible variation and find solution which is closest the W mass!!!
      float delta1 = fabs((lep_pos+neu1).mass() - 80.4*GeV) + fabs((lep_neg+neu2).mass() - 80.4*GeV);
      float delta2 = fabs((lep_pos+neu2).mass() - 80.4*GeV) + fabs((lep_neg+neu1).mass() - 80.4*GeV);

      //std::cout << (lep_pos+neu1).mass() << "\t" << (lep_neg+neu2).mass() << "\t" << (lep_pos+neu2).mass() << "\t" << (lep_neg+neu1).mass() << std::endl;

      if(delta1 < delta2){
	Wpos = lep_pos+neu1;
	Wneg = lep_neg+neu2;
      }
      else{
	Wpos = lep_pos+neu2;
	Wneg = lep_neg+neu1;
      }

      //std::cout << "bla 4" << std::endl;

      _Wlep[0] = Wpos;
      _Wlep[1] = Wneg;

      _histos["leptons_deltaR"]   -> fill(deltaR(lep_pos,   lep_neg));
      _histos["leptons_deltaPhi"] -> fill(deltaPhi(lep_pos, lep_neg));
      _histos["leptons_deltaEta"] -> fill(deltaEta(lep_pos, lep_neg));

      if(n_el == 2 && n_mu == 0)
	_histos["leptons_deltaPhi_ee"] -> fill(deltaPhi(lep_pos, lep_neg));
      if(n_el == 0 && n_mu == 2)
	_histos["leptons_deltaPhi_mumu"] -> fill(deltaPhi(lep_pos, lep_neg));
      if(n_el == 1 && n_mu == 1)
	_histos["leptons_deltaPhi_emu"] -> fill(deltaPhi(lep_pos, lep_neg));



      //std::cout << "bla 5" << std::endl;

      ReconstructDileptonTop(lep_pos, lep_neg, bjets, jets, n_el, n_mu);
      
      //std::cout << "bla 6" << std::endl;

    }

	  void ReconstructDileptonMlb(vector<DressedLepton> lep, Jets bjets, Jets jets){  //minAvg algo


      FourMomentum lep1 = lep[0].momentum();
      FourMomentum lep2 = lep[1].momentum();

      FourMomentum b1 = bjets[0].momentum();
      FourMomentum b2; //  = bjets[1].momentum();

	  for (auto &jet : jets){

          if(bjets[0].momentum().pT() == jet.momentum().pT())
              continue;

          if(jet.momentum().pT() > b2.pT())
              b2 = jet.momentum();

      }
	  

      FourMomentum b1lep, b2lep;

      // if (lep1.pT()>lep2.pT())       cout<<"lep1:"<<lep1.pT() << " lep2: "<<lep2.pT() <<endl;
      // if (lep1.pT()<lep2.pT())       cout<<"lep1:"<<lep2.pT() << " lep2: "<<lep1.pT() <<endl;
      // if (b1.pT()>b2.pT())           cout<<"b1:"<<b1.pT() << " b2: "<<b2.pT() <<endl;
      // if (b2.pT()>b1.pT())           cout<<"b1:"<<b2.pT() << " b2: "<<b1.pT() <<endl;
      // high pt b jet is assigned to b1
	  // if (b1.pT()>b2.pT()){b1=bjets[0].momentum(); b2=bjets[1].momentum();}
      //else{b1=bjets[1].momentum(); b2=bjets[0].momentum();} 


      FourMomentum PairA1,PairA2,PairB1,PairB2;
      FourMomentum Mlb1minavg, Mlb2minavg;
      FourMomentum Mlbhighminavg, Mlblowminavg;
      FourMomentum MlbhighLBminavg, MlblowLBminavg;

      PairA1 = b1+ lep1;
      PairA2 = b2+ lep2;
      PairB1 = b1+ lep2;
      PairB2 = b2+ lep1;

      double PairA_AvgMass = (PairA1.mass()+PairA2.mass())/2;
      double PairB_AvgMass = (PairB1.mass()+PairB2.mass())/2;

      if (PairA_AvgMass < PairB_AvgMass){Mlb1minavg=PairA1;Mlb2minavg=PairA2; b1lep=lep1; b2lep=lep2;} 
      else                              {Mlb1minavg=PairB1;Mlb2minavg=PairB2;b1lep=lep2; b2lep=lep1;} 


      if (b1.pT() >b2.pT()) {Mlbhighminavg=Mlb1minavg; Mlblowminavg=Mlb2minavg;           }
      else                  {Mlbhighminavg=Mlb2minavg; Mlblowminavg=Mlb1minavg;           }

      if((b1+b1lep).pT()> (b2+b2lep).pT()) {MlbhighLBminavg=Mlb1minavg; MlblowLBminavg=Mlb2minavg;ptlbH= (b1+b1lep).pT();ptlbL=(b2+b2lep).pT();}
      else                                 {MlbhighLBminavg=Mlb2minavg; MlblowLBminavg=Mlb1minavg;ptlbL= (b1+b1lep).pT();ptlbH=(b2+b2lep).pT();} 

      //      costheta1=1-(Mlb1minavg.mass())/(2*(b1.E())*(b1lep.E()));
      //      costheta2=1-(Mlb2minavg.mass())/(2*(b2.E())*(b2lep.E()));
      
      //      costheta1=(b1.dot(b1lep))/(sqrt(b1.dot(b1))*sqrt(b1lep.dot(b1lep)));
      //      costheta2=(b2.dot(b2lep))/(sqrt(b2.dot(b2))*sqrt(b2lep.dot(b2lep)));
      
      //      cost1=cos(b1.theta()-b1lep.theta());
      //      cost2=cos(b2.theta()-b2lep.theta());
      
      
      
      LorentzTransform HRF_boost1;
      LorentzTransform HRF_boost2;
      //HRF_boost.mkFrameTransformFromBeta(Higgs.betaVec());
      HRF_boost1.setBetaVec(- Mlb1minavg.betaVec());
      HRF_boost2.setBetaVec(- Mlb2minavg.betaVec());
      FourMomentum b1_in_HRF = HRF_boost1.transform( b1 );
      FourMomentum b2_in_HRF = HRF_boost2.transform( b2 );
      //      double mlb1_costheta = fabs(cos( b1.theta())); 
      //      double mlb2_costheta = fabs(cos( b2.theta())); 
      
      
      cost1 = fabs(cos( b1.theta())); 
      cost2 = fabs(cos( b2.theta())); 
      
      
      //      cout<< "mlb1 costheta1: "<<mlb1_costheta<< "mlb2" <<mlb2_costheta <<endl;
      //
      //     cout<<"bdotlep boy"<<b1.dot(b1lep)<< " "<<b1.E()*b1lep.E()-b1.px()*b1lep.px()-b1.py()*b1lep.py()-b1.pz()*b1lep.pz() <<endl;
      //     cout<<"b boy"<<b1.dot(b1)<<" 4vector" <<b1.pT() <<"," << b1.eta()<< "," <<b1.phi() << ","<< b1.mass() <<endl;
      //     cout<<"lep boy"<<b1lep.dot(b1lep)<< " 4vector" <<b1lep.pT() <<"," << b1lep.eta()<< "," <<b1lep.phi() << ","<< b1lep.mass() <<endl;
      //     cout<<"costheta1:"<< costheta1 << " costheta2 "<< costheta2<<endl;
      //
      
      dR1=deltaR(b1,b1lep);//DeltaRInRange(b1lep);
      dR2=deltaR(b2,b2lep);//b2.DeltaRInRange(b2lep);         
      
      //       cout<<"b1 jet lep theta"  <<b1.theta() << b1lep.theta() <<endl; 
      //       cout<<"b2 jet lep theta"  <<b2.theta() << b2lep.theta() <<endl; 
      //       cout<<"dR1:"<< dR1 << " dR2 "<< dR2<<endl;
      //
      //       cout<<"costheta1:"<< costheta1 << " costheta2 "<< costheta2<<endl;
      //       cout<<"cost1:"<< cost1 << " cost2 "<< cost2<<endl;
      //
      //       cout<<"cos check cos90:"<< cos(90) << " cos0 "<< cos(0)<< "cos radyan pi"<< cos(3.14)<<endl;
      
      _ptlep1=b1lep.pT(); 
      _ptlep2=b2lep.pT(); 
      _ptb1=b1.pT(); 
      _ptb2=b2.pT(); 
      _Mert0minAv=(MlbhighLBminavg.mass()+MlblowLBminavg.mass())/2;
      _Mert1minAv.push_back(Mlbhighminavg);
      _Mert2minAv.push_back(Mlblowminavg);
      _MerLB1minAv.push_back(MlbhighLBminavg);
      _MerLB2minAv.push_back(MlblowLBminavg);
      //       cout<<"Mlbhighminavg:"<< Mlbhighminavg.mass() << " Mlblowminavg: "<< Mlblowminavg.mass() <<endl;
      //       cout<<"MlbhighLBminavg:"<< MlbhighLBminavg.mass() << " MlblowLBminavg: "<< MlblowLBminavg.mass() << "avg:"<<  _Mert0minAv<<endl;
      //       cout<<"ptb1:"<< b1.pT() << " ptb2 "<< _ptb2<<endl;
      
    }
    
	  void ReconstructDileptonTop(FourMomentum lep_pos, FourMomentum lep_neg, Jets bjets, Jets jets, int n_el, int n_mu){

      FourMomentum TTbar;
      FourMomentum Top; // pos
      FourMomentum Antitop; // neg
      FourMomentum b1 = bjets[0].momentum();
	  // FourMomentum b2 = bjets[1].momentum();      
	  // when only one b is present, use the next jet with highest pt

	  FourMomentum b2;

	  for (auto &jet : jets){
	  
		  if(bjets[0].momentum().pT() == jet.momentum().pT())
			  continue;

		  if(jet.momentum().pT() > b2.pT())
			  b2 = jet.momentum();

	  }

      FourMomentum Wpos = _Wlep[0];
      FourMomentum Wneg = _Wlep[1];

      float delta1 = fabs((Wpos+b1).mass() - 172.5*GeV) + fabs((Wneg+b2).mass() - 172.5*GeV);
      float delta2 = fabs((Wpos+b2).mass() - 172.5*GeV) + fabs((Wneg+b1).mass() - 172.5*GeV);
      
      if(delta1 < delta2){
		  Top     = Wpos+b1;
		  Antitop = Wneg+b2;
      }
      else{
		  Top     = Wpos+b2;
		  Antitop = Wneg+b1;	
      }
	  
      _tlep.push_back(Top);
      _tlep.push_back(Antitop);
      _ttbar.push_back(Top + Antitop);
      
      TTbar = Top + Antitop;

      float cos_k_p = cos_theta_helicity(Top, Top,     TTbar, lep_pos, +1);
      float cos_k_m = cos_theta_helicity(Top, Antitop, TTbar, lep_neg, -1);
      float cos_n_p = cos_theta_transverse(Top, Top,     TTbar, lep_pos, +1);
      float cos_n_m = cos_theta_transverse(Top, Antitop, TTbar, lep_neg, -1);
      float cos_r_p = cos_theta_raxis(Top, Top,     TTbar, lep_pos, +1);
      float cos_r_m = cos_theta_raxis(Top, Antitop, TTbar, lep_neg, -1);
	  
      // spin correlations
      float cos_k_k = cos_k_p*cos_k_m;
      float cos_n_n = cos_n_p*cos_n_m;
      float cos_r_r = cos_r_p*cos_r_m;
	  
      float c_n_k_plus_c_k_n  = cos_n_p*cos_k_m + cos_k_p*cos_n_m;
      float c_n_k_minus_c_k_n = cos_n_p*cos_k_m - cos_k_p*cos_n_m;
      float c_n_r_plus_c_r_n  = cos_n_p*cos_r_m + cos_r_p*cos_n_m;
      float c_n_r_minus_c_r_n = cos_n_p*cos_r_m - cos_r_p*cos_n_m;
      float c_r_k_plus_c_k_r  = cos_r_p*cos_k_m + cos_k_p*cos_r_m;
      float c_r_k_minus_c_k_r = cos_r_p*cos_k_m - cos_k_p*cos_r_m;

      float cosphi = cos_phi(lep_pos, lep_neg, Top, Antitop);
	  
      _histos["cos_phi"] -> fill(cosphi);
      if(TTbar.mass()/GeV < 380.0){
		  _histos["cos_phi_s380"] -> fill(cosphi);
		  
		  if(n_el == 1 && n_mu == 1)
			  _histos["cos_phi_s380_emu"] -> fill(cosphi);
		  if(n_el == 2 && n_mu == 0)
			  _histos["cos_phi_s380_ee"] -> fill(cosphi);
		  if(n_el == 0 && n_mu == 2)
			  _histos["cos_phi_s380_mumu"] -> fill(cosphi);
		  
		  
      }
      else{
		  _histos["cos_phi_l380"]-> fill(cosphi);
		  
		  if(n_el == 1 && n_mu == 1)
			  _histos["cos_phi_l380_emu"] -> fill(cosphi);
		  if(n_el == 2 && n_mu == 0)
			  _histos["cos_phi_l380_ee"] -> fill(cosphi);
		  if(n_el == 0 && n_mu == 2)
			  _histos["cos_phi_l380_mumu"] -> fill(cosphi);
		  
		  
      }
	  
      if(TTbar.mass()/GeV < 390.0)
		  _histos["cos_phi_s390"] -> fill(cosphi);
      if(TTbar.mass()/GeV < 400.0)
		  _histos["cos_phi_s400"] -> fill(cosphi);
      if(TTbar.mass()/GeV < 410.0)
		  _histos["cos_phi_s410"] -> fill(cosphi);
	  
	  
      if(n_el == 1 && n_mu == 1){
		  _histos["cos_phi_emu"] -> fill(cosphi);
      }
	  
      if(n_el == 2 && n_mu == 0){
		  _histos["cos_phi_ee"] -> fill(cosphi);
      }
      if(n_el == 0 && n_mu == 2){
		  _histos["cos_phi_mumu"] -> fill(cosphi);
      }
	  
	  
      _histos["M_ttbar"]   -> fill(TTbar.mass()/GeV);
      _histos["pT_ttbar"]  -> fill(TTbar.pT()/GeV);
      _histos["eta_ttbar"] -> fill(TTbar.eta());
      _histos["phi_ttbar"] -> fill(TTbar.phi());

      _histos["M_top"]     -> fill(Top.mass()/GeV);
      _histos["M_top_tot"] -> fill(Top.mass()/GeV);
      _histos["pT_top"]    -> fill(Top.pT()/GeV);
      _histos["eta_top"]   -> fill(Top.eta());
      _histos["phi_top"]   -> fill(Top.phi());
      
      _histos["M_antitop"]   -> fill(Antitop.mass()/GeV);
      _histos["M_top_tot"] -> fill(Antitop.mass()/GeV);
      _histos["pT_antitop"]  -> fill(Antitop.pT()/GeV);
      _histos["eta_antitop"] -> fill(Antitop.eta());
      _histos["phi_antitop"] -> fill(Antitop.phi());

      _histos["cos_k_p"] -> fill(cos_k_p);
      _histos["cos_n_p"] -> fill(cos_n_p);
      _histos["cos_r_p"] -> fill(cos_r_p);
      
      _histos["cos_k_m"] -> fill(cos_k_m);
      _histos["cos_n_m"] -> fill(cos_n_m);
      _histos["cos_r_m"] -> fill(cos_r_m);

      _histos["cos_k_k"] -> fill(cos_k_k);
      _histos["cos_n_n"] -> fill(cos_n_n);
      _histos["cos_r_r"] -> fill(cos_r_r);

      _histos["c_n_k_plus_c_k_n"]  -> fill(c_n_k_plus_c_k_n);
      _histos["c_n_r_plus_c_r_n"]  -> fill(c_n_r_plus_c_r_n);
      _histos["c_r_k_plus_c_k_r"]  -> fill(c_r_k_plus_c_k_r);
      _histos["c_n_k_minus_c_k_n"] -> fill(c_n_k_minus_c_k_n);
      _histos["c_n_r_minus_c_r_n"] -> fill(c_n_r_minus_c_r_n);
      _histos["c_r_k_minus_c_k_r"] -> fill(c_r_k_minus_c_k_r);




      /*
      std::cout << "========================================================================================" << std::endl;
      std::cout << "Spin Variables: ========================================================================" << std::endl;
      
      std::cout << cos_k_p << "\t" << cos_k_m << "\t" << cos_n_p << "\t" << cos_n_m << "\t" << cos_r_p << "\t" << cos_r_m << std::endl;
      std::cout << cos_k_k << "\t" << cos_n_n << "\t" << cos_r_r << std::endl;
      std::cout << c_n_k_plus_c_k_n << "\t" << c_n_k_minus_c_k_n << "\t" << c_n_r_plus_c_r_n << "\t" << c_n_r_minus_c_r_n << "\t" << c_r_k_plus_c_k_r << "\t" << c_r_k_minus_c_k_r << std::endl;
      */

    }
    
    // from Jay
    float cos_theta_helicity(const FourMomentum top, const FourMomentum parent_t, const FourMomentum ttbar, const FourMomentum lep, float sign){

      const FourMomentum parent_t_in_ttbar_rf = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(parent_t);
      const FourMomentum top_in_ttbar_rf      = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(top);
      const FourMomentum lep_in_ttbar_rf      = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(lep);

      const FourMomentum lep_in_parent_t_rf   = LorentzTransform::mkFrameTransformFromBeta(parent_t_in_ttbar_rf.betaVec()).transform(lep_in_ttbar_rf);

      Vector3 k_vector = top_in_ttbar_rf.vector3().unit();
      k_vector *= sign;
      float theta = lep_in_parent_t_rf.vector3().unit().dot(k_vector);

      //-- If we have a nan move to this to the overflow bins --//                                                                                                                                       
      if (isnan(theta)){
	return -55.;
      } else {
	return theta;
      }
    }

    // from Jay
    float cos_theta_raxis(const FourMomentum top, const FourMomentum parent_t, const FourMomentum ttbar, const FourMomentum lep, float sign){

      const FourMomentum parent_t_in_ttbar_rf = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(parent_t);
      const FourMomentum top_in_ttbar_rf      = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(top);
      const FourMomentum lep_in_ttbar_rf      = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(lep);

      const FourMomentum lep_in_parent_t_rf   = LorentzTransform::mkFrameTransformFromBeta(parent_t_in_ttbar_rf.betaVec()).transform(lep_in_ttbar_rf);

      Vector3 k_vector = top_in_ttbar_rf.vector3().unit();
      k_vector *= sign;
      Vector3 p_vector(0,0,1);

      float y = p_vector.dot(k_vector);
      float r = pow((1. - y*y),0.5);

      Vector3 r_vector = (1./r)*(p_vector - y*k_vector);

      /*if (sign == 1){                                                                                                                                                                                                    ///-- We're in the a axis --///                                                                                                                                                                            if(y > 0) r_vector *= 1.;                                                                                                                                                                                  if(y < 0) r_vector *= -1.;                                                                                                                                                                               } else if (sign == -1){                                                                                                                                                                                      ///-- We're in the b axis --///                                                                                                                                                                            if(y > 0) r_vector *= -1.;                                                                                                                                                                                 if(y < 0) r_vector *= 1.;                                                                                                                                                                        	  }*/
      float theta = lep_in_parent_t_rf.vector3().unit().dot(r_vector);

      //-- If we have a nan move to this to the overflow bins --//                                                                                                                                        
      if (isnan(theta)){
	return -55.;
      } else {
	return theta;
      }
    }

    // from Jay
    float cos_theta_transverse(const FourMomentum top, const FourMomentum parent_t, const FourMomentum ttbar, const FourMomentum lep, float sign){

      const FourMomentum parent_t_in_ttbar_rf = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(parent_t);
      const FourMomentum top_in_ttbar_rf      = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(top);
      const FourMomentum lep_in_ttbar_rf      = LorentzTransform::mkFrameTransformFromBeta(ttbar.betaVec()).transform(lep);

      const FourMomentum lep_in_parent_t_rf   = LorentzTransform::mkFrameTransformFromBeta(parent_t_in_ttbar_rf.betaVec()).transform(lep_in_ttbar_rf);

      Vector3 k_vector = top_in_ttbar_rf.vector3().unit();
      k_vector *= sign;
      Vector3 p_vector(0,0,1);

      float y = p_vector.dot(k_vector);
      float r = pow((1. - y*y),0.5);

      Vector3 n_vector = (1./r)*(p_vector.cross(k_vector)); ///-- Should this be Unit Vector? --///                                                                                                       
      if (sign == 1){
	///-- We're in the a axis --///                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	if(y > 0) n_vector *= 1.;
	if(y < 0) n_vector *= -1.;
      } else if (sign == -1){
	///-- We're in the b axis --///                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	if(y > 0) n_vector *= -1.;
	if(y < 0) n_vector *= 1.;
      }
      float theta = lep_in_parent_t_rf.vector3().unit().dot(n_vector);

      //-- If we have a nan move to this to the overflow bins --//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
      if (isnan(theta)){
	return -55.;
      } else {
	return theta;
      }
    }


    float cos_phi(const FourMomentum pos, const FourMomentum neg, const FourMomentum top, const FourMomentum tbar){

      const FourMomentum lep_pos = LorentzTransform::mkFrameTransformFromBeta(top.betaVec()).transform(pos);
      const FourMomentum lep_neg = LorentzTransform::mkFrameTransformFromBeta(tbar.betaVec()).transform(neg);

      //Take cosine of deltaphi
      float D = lep_pos.vector3().unit().dot(lep_neg.vector3().unit());

      return D;
    }


    Particle findAfterFSR(const Particle particle) {
		bool isAfterFSR(false);
		const int particle_ID = particle.pid();
		int forLoop  = 0;
		
		Particle current = particle;

		//		std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

		//	std::cout << "Check children for ID " << particle_ID << std::endl;
		
		while(!isAfterFSR){

		  forLoop  = 0;
		  
		  //std::cout << "----------------------" << std::endl;

		  //		  for (const Particle& child : current.allDescendants()) {
		    
		  for (const Particle& child : current.children()) {
		    
		    //std::cout << "child in after FSR = " << child.pid() << std::endl;
				
		    //if(child.pid() == 15 || child.pid() == -15)
		    //		return child;
		    
		    if (child.pid() == particle_ID){
		      current = child;
		      forLoop++;
		      break;
		    }
		  }
		  
		  if (forLoop == 0)       isAfterFSR = true;      
		}
		return current;
    }
    
	  
	  
  };



  // This global object acts as a hook for the plugin system
  AnalysisBuilder<ATLAS_tt_tW_ent> plugin_ATLAS_tt_tW_ent;


}

