#ifndef READFLATTREE_H
#define READFLATTREE_H

#include "../../../MEMmultilepton/interface/MultiLepton.h"

#include "TROOT.h"
#include "TBranch.h"
#include "TTree.h"
#include <iostream>

using namespace std;

class ReadFlatTree {

  public:

  string InputFileName;
  TFile* fInput;
  TTree* tInput;

//  string OutputFileName;
  TFile* fOutput;
  TTree* tOutput;

  ReadFlatTree();
  ~ReadFlatTree();

  void InitializeDryRun(string);

  bool doUpdateAllJets;
  void SetUpdateAllJets(bool);

  void LoadPipelineVars(string);
  void InitializeMEMRun(string, string);
  void FillGenMultilepton(Long64_t, MultiLepton*);
  int ApplyGenSelection(Long64_t, MultiLepton*);
  void WriteMultilepton(MultiLepton*);
  void ReadMultilepton(Long64_t, MultiLepton*);
  void PipelineVariable();

  //Pipeline
  ifstream fconf;

  std::vector<string> pipelineFloat_varname;
  std::vector<string> pipelineInt_varname;
  std::vector<string> pipelineChar_varname;

  Float_t* pipelineFloat;
  Int_t* pipelineInt;
  Char_t* pipelineChar;

  TBranch** b_pipelineFloat;
  TBranch** b_pipelineInt;
  TBranch** b_pipelineChar;


  //Divers
  Float_t mc_weight;
  Float_t weight;
  Float_t PV_weight;
  Float_t weight_scale_muF0p5, weight_scale_muF2, weight_scale_muR0p5, weight_scale_muR2;
  Float_t weight_csv_down, weight_csv_up;

  //Deprecated : MC truth
  Int_t mc_truth_h0_id;
  TLorentzVector* mc_truth_h0_p4;
  Int_t mc_truth_h0Wl1_id;
  TLorentzVector* mc_truth_h0Wl1_p4;
  Int_t mc_truth_h0Wl2_id;
  TLorentzVector* mc_truth_h0Wl2_p4;
  TLorentzVector* mc_truth_h0Wnu1_p4;
  TLorentzVector* mc_truth_h0Wnu2_p4;
  Int_t mc_truth_h0Wq11_id;
  TLorentzVector* mc_truth_h0Wq11_p4;
  Int_t mc_truth_h0Wq12_id;
  TLorentzVector* mc_truth_h0Wq12_p4;
  Int_t mc_truth_h0Wq21_id;
  TLorentzVector* mc_truth_h0Wq21_p4;
  Int_t mc_truth_h0Wq22_id;
  TLorentzVector* mc_truth_h0Wq22_p4;
  Int_t mc_truth_t1_id;
  TLorentzVector* mc_truth_t1_p4;
  Int_t mc_truth_t2_id;
  TLorentzVector* mc_truth_t2_p4;
  Int_t mc_truth_tb1_id;
  TLorentzVector* mc_truth_tb1_p4;
  Int_t mc_truth_tb2_id;
  TLorentzVector* mc_truth_tb2_p4;
  Int_t mc_truth_tWl1_id;
  TLorentzVector* mc_truth_tWl1_p4;
  TLorentzVector* mc_truth_tWnu1_p4;
  Int_t mc_truth_tWl2_id;
  TLorentzVector* mc_truth_tWl2_p4;
  TLorentzVector* mc_truth_tWnu2_p4;
  Int_t mc_truth_tWq11_id;
  TLorentzVector* mc_truth_tWq11_p4;
  Int_t mc_truth_tWq21_id;
  TLorentzVector* mc_truth_tWq21_p4;
  Int_t mc_truth_tWq12_id;
  TLorentzVector* mc_truth_tWq12_p4;
  Int_t mc_truth_tWq22_id;
  TLorentzVector* mc_truth_tWq22_p4;
  Int_t mc_truth_Z_id;
  TLorentzVector* mc_truth_Z_p4;
  Int_t mc_truth_Zl1_id;
  TLorentzVector* mc_truth_Zl1_p4;
  Int_t mc_truth_Zl2_id;
  TLorentzVector* mc_truth_Zl2_p4;
  Int_t mc_truth_W_id;
  TLorentzVector*  mc_truth_W_p4;
  Int_t mc_truth_Wl_id;
  TLorentzVector*  mc_truth_Wl_p4;
  Int_t genJet_n;
  Int_t mc_truth_gammal1_id;
  TLorentzVector*  mc_truth_gammal1_p4;
  Int_t mc_truth_gammal2_id;
  TLorentzVector*  mc_truth_gammal2_p4;
  std::vector<float>* genJet_pt;
  std::vector<float>* genJet_eta;
  std::vector<float>* genJet_phi;
  std::vector<float>* genJet_E;

  //TTH BDTs
  Float_t nJet25_Recl;
  Float_t max_Lep_eta, MT_met_lep1, mindr_lep1_jet, mindr_lep2_jet, LepGood_conePt0, LepGood_conePt1;
  Float_t signal_2lss_TT_MVA;
  Float_t signal_2lss_TTV_MVA;
  Float_t signal_3l_TT_MVA;
  Float_t signal_3l_TTV_MVA;

  //TZQ BDTs
  // Float_t btagDiscri, dRAddLepQ, dRAddLepClosestJet, dPhiAddLepB, ZEta, Zpt, mtop, AddLepAsym, etaQ, AddLepETA, LeadJetEta, dPhiZAddLep, dRZAddLep, dRjj, ptQ, tZq_pT, METpt;
  // Float_t dRAddLepB, dRZTop, TopPT, m3l;
  // Float_t Weight, Channel, NJets, NBJets, mTW;
  // Float_t Q2__plus, Q2__minus, PU__plus, PU__minus, MuEff__plus, MuEff__minus, EleEff__plus, EleEff__minus, LFcont__plus, LFcont__minus, HFstats1__plus, HFstats1__minus, HFstats2__plus, HFstats2__minus, CFerr1__plus, CFerr1__minus, CFerr2__plus, CFerr2__minus, HFcont__plus, HFcont__minus, LFstats1__plus, LFstats1__minus, LFstats2__plus, LFstats2__minus, pdf__plus, pdf__minus, Weight_noTag, Weight_noPU;

  //THQ2016 BDT input variables
  Float_t nJet25, maxEtaJet25, lepCharge, nJetEta1, dEtaFwdJetBJet, dEtaFwdJet2BJet, dEtaFwdJetClosestLep, dPhiHighestPtSSPair, minDRll, Lep3Pt;
  //THQ2016 additional variables
  Float_t channel, weightfake, weightflip, event_run, inv_mll, hardestBjetPt, hardestBjetEta, fwdJetPt, lep1Pt, lep2Pt, lep3Pt, MET, nLooseBJets, nMediumBJets, nLightJets, nTightLep, nFakeableLep, nLightJets_Fwd40;
 Int_t event_id;

  //MEM studies (Jing)
  std::vector<double>* mc_kin_tthfl_inputvars;
  std::vector<double>* mc_kin_tthsl_inputvars;
  std::vector<double>* mc_kin_ttz_inputvars;
  std::vector<double>* mc_kin_ttw_inputvars;
  std::vector<double>* mc_kin_ttwjj_inputvars;
  std::vector<double>* mc_kin_ttbarfl_inputvars;
  std::vector<double>* mc_kin_ttbarsl_inputvars;
  std::vector<double>* mc_kin_tllj_inputvars;
  std::vector<double>* mc_kin_wzjj_inputvars;
  std::vector<double>* mc_kin_thj_inputvars;

  std::vector<double>* mc_kinInt_tthfl_inputvars;
  std::vector<double>* mc_kinInt_tthsl_inputvars;
  std::vector<double>* mc_kinInt_ttz_inputvars;
  std::vector<double>* mc_kinInt_ttw_inputvars;
  std::vector<double>* mc_kinInt_ttwjj_inputvars;
  std::vector<double>* mc_kinInt_ttbarfl_inputvars;
  std::vector<double>* mc_kinInt_ttbarsl_inputvars;
  std::vector<double>* mc_kinInt_tllj_inputvars;
  std::vector<double>* mc_kinInt_wzjj_inputvars;
  std::vector<double>* mc_kinInt_thj_inputvars;

  //All branches
  TBranch* b_mc_event;
  TBranch* b_mc_weight;
  TBranch* b_weight;
  TBranch* b_PV_weight;
  TBranch* b_weight_scale_muF0p5;
  TBranch* b_weight_scale_muF2;
  TBranch* b_weight_scale_muR0p5;
  TBranch* b_weight_scale_muR2;
  TBranch* b_weight_csv_down;
  TBranch* b_weight_csv_up;

  TBranch* b_mc_truth_h0_id;
  TBranch* b_mc_truth_h0_p4;
  TBranch* b_mc_truth_h0Wl1_id;
  TBranch* b_mc_truth_h0Wl1_p4;
  TBranch* b_mc_truth_h0Wl2_id;
  TBranch* b_mc_truth_h0Wl2_p4;
  TBranch* b_mc_truth_h0Wnu1_p4;
  TBranch* b_mc_truth_h0Wnu2_p4;
  TBranch* b_mc_truth_h0Wq11_id;
  TBranch* b_mc_truth_h0Wq11_p4;
  TBranch* b_mc_truth_h0Wq12_id;
  TBranch* b_mc_truth_h0Wq12_p4;
  TBranch* b_mc_truth_h0Wq21_id;
  TBranch* b_mc_truth_h0Wq21_p4;
  TBranch* b_mc_truth_h0Wq22_id;
  TBranch* b_mc_truth_h0Wq22_p4;
  TBranch* b_mc_truth_t1_id;
  TBranch* b_mc_truth_t1_p4;
  TBranch* b_mc_truth_t2_id;
  TBranch* b_mc_truth_t2_p4;
  TBranch* b_mc_truth_tb1_id;
  TBranch* b_mc_truth_tb1_p4;
  TBranch* b_mc_truth_tb2_id;
  TBranch* b_mc_truth_tb2_p4;
  TBranch* b_mc_truth_tWl1_id;
  TBranch* b_mc_truth_tWl1_p4;
  TBranch* b_mc_truth_tWl2_id;
  TBranch* b_mc_truth_tWl2_p4;
  TBranch* b_mc_truth_tWnu1_p4;
  TBranch* b_mc_truth_tWnu2_p4;
  TBranch* b_mc_truth_tWq11_id;
  TBranch* b_mc_truth_tWq11_p4;
  TBranch* b_mc_truth_tWq21_id;
  TBranch* b_mc_truth_tWq21_p4;
  TBranch* b_mc_truth_tWq12_id;
  TBranch* b_mc_truth_tWq12_p4;
  TBranch* b_mc_truth_tWq22_id;
  TBranch* b_mc_truth_tWq22_p4;
  TBranch* b_mc_truth_Z_id;
  TBranch* b_mc_truth_Z_p4;
  TBranch* b_mc_truth_Zl1_id;
  TBranch* b_mc_truth_Zl1_p4;
  TBranch* b_mc_truth_Zl2_id;
  TBranch* b_mc_truth_Zl2_p4;
  TBranch* b_mc_truth_W_id;
  TBranch* b_mc_truth_W_p4;
  TBranch* b_mc_truth_Wl_id;
  TBranch* b_mc_truth_Wl_p4;
  TBranch* b_mc_truth_gammal1_id;
  TBranch* b_mc_truth_gammal1_p4;
  TBranch* b_mc_truth_gammal2_id;
  TBranch* b_mc_truth_gammal2_p4;
  TBranch* b_genJet_n;
  TBranch* b_genJet_pt;
  TBranch* b_genJet_eta;
  TBranch* b_genJet_phi;
  TBranch* b_genJet_E;

  TBranch* b_max_Lep_eta;
  TBranch* b_MT_met_lep1;
  TBranch* b_mindr_lep1_jet;
  TBranch* b_mindr_lep2_jet;
  TBranch* b_LepGood_conePt0;
  TBranch* b_LepGood_conePt1;
  TBranch* b_nJet25_Recl;

  TBranch* b_signal_2lss_TT_MVA;
  TBranch* b_signal_2lss_TTV_MVA;
  TBranch* b_signal_3l_TT_MVA;
  TBranch* b_signal_3l_TTV_MVA;

  //--- tZq

  // TBranch* b_btagDiscri;
  // TBranch* b_dRAddLepQ;
  // TBranch* b_dRAddLepClosestJet;
  // TBranch* b_dPhiAddLepB;
  // TBranch* b_ZEta;
  // TBranch* b_Zpt;
  // TBranch* b_mtop;
  // TBranch* b_AddLepAsym;
  // TBranch* b_etaQ;
  // TBranch* b_AddLepETA;
  // TBranch* b_LeadJetEta;
  // TBranch* b_dPhiZAddLep;
  // TBranch* b_dRZAddLep;
  // TBranch* b_dRjj;
  // TBranch* b_ptQ;
  // TBranch* b_tZq_pT;
  // TBranch* b_METpt;
  // TBranch* b_dRAddLepB;
  // TBranch* b_dRZTop;
  // TBranch* b_TopPT;
  // TBranch* b_m3l;
  // TBranch* b_Weight;
  // TBranch* b_channel;
  // TBranch* b_NJets;
  // TBranch* b_NBJets;
  // TBranch* b_mTW;
  // TBranch* b_Q2__plus;
  // TBranch* b_Q2__minus;
  // TBranch* b_PU__plus;
  // TBranch* b_PU__minus;
  // TBranch* b_MuEff__plus;
  // TBranch* b_MuEff__minus;
  // TBranch* b_EleEff__plus;
  // TBranch* b_EleEff__minus;
  // TBranch* b_LFcont__plus;
  // TBranch* b_LFcont__minus;
  // TBranch* b_HFstats1__plus;
  // TBranch* b_HFstats1__minus;
  // TBranch* b_HFstats2__plus;
  // TBranch* b_HFstats2__minus;
  // TBranch* b_CFerr1__plus;
  // TBranch* b_CFerr1__minus;
  // TBranch* b_CFerr2__plus;
  // TBranch* b_CFerr2__minus;
  // TBranch* b_HFcont__plus;
  // TBranch* b_HFcont__minus;
  // TBranch* b_LFstats1__plus;
  // TBranch* b_LFstats1__minus;
  // TBranch* b_LFstats2__plus;
  // TBranch* b_LFstats2__minus;
  // TBranch* b_pdf__plus;
  // TBranch* b_pdf__minus;
  // TBranch* b_Weight_noTag;
  // TBranch* b_Weight_noPU;
  //  Float_t Q2__plus, Q2__minus, PU__plus, PU__minus, MuEff__plus, MuEff__minus, EleEff__plus, EleEff__minus, LFcont__plus, LFcont__minus, HFstats1__plus, HFstats1__minus, HFstats2__plus, HFstats2__minus, CFerr1__plus, CFerr1__minus, CFerr2__plus, CFerr2__minus, HFcont__plus, HFcont__minus, LFstats1__plus, LFstats1__minus, LFstats2__plus, LFstats2__minus, pdf__plus, pdf__minus, Weight_noTag, Weight_noPU;


  //--- tHq2016
  TBranch* b_channel;
  TBranch* b_weightfake;
  TBranch* b_weightflip;
  TBranch* b_event_id;
  TBranch* b_event_run;
  TBranch* b_nJet25;
  TBranch* b_maxEtaJet25;
  TBranch* b_lepCharge;
  TBranch* b_nJetEta1;
  TBranch* b_dEtaFwdJetBJet;
  TBranch* b_dEtaFwdJet2BJet;
  TBranch* b_dEtaFwdJetClosestLep;
  TBranch* b_dPhiHighestPtSSPair;
  TBranch* b_minDRll;
  TBranch* b_Lep3Pt;
  TBranch* b_inv_mll;
  TBranch* b_hardestBjetPt;
  TBranch* b_hardestBjetEta;
  TBranch* b_fwdJetPt;
  TBranch* b_lep1Pt;
  TBranch* b_lep2Pt;
  TBranch* b_lep3Pt;
  TBranch* b_MET;
  TBranch* b_nLooseBJets;
  TBranch* b_nMediumBJets;
  TBranch* b_nLightJets;
  TBranch* b_nTightLep;
  TBranch* b_nFakeableLep;
  TBranch* b_nLightJets_Fwd40;



  Int_t mc_event;
  Float_t mc_totp4_px;
  Float_t mc_totp4_py;
  Float_t mc_totp4_pt;
  Float_t mc_thad_pt;
  Float_t mc_thad_b_pt;
  Float_t mc_thad_b_eta;
  Float_t mc_thad_j1_pt;
  Float_t mc_thad_j1_eta;
  Float_t mc_thad_j2_pt;
  Float_t mc_thad_j2_eta;
  Float_t mc_tlep_pt;
  Float_t mc_tlep_b_pt;
  Float_t mc_tlep_b_eta;
  Float_t mc_tlep_l_pt;
  Float_t mc_tlep_l_eta;
  Float_t mc_tlep2_pt;
  Float_t mc_tlep2_b_pt;
  Float_t mc_tlep2_b_eta;
  Float_t mc_tlep2_l_pt;
  Float_t mc_tlep2_l_eta;
  Int_t   mc_ttbar_decay;
  Int_t   mc_boson_decay;
  Float_t mc_boson_pt;
  Float_t mc_boson_l1_pt;
  Float_t mc_boson_l1_eta;
  Float_t mc_boson_l2_pt;
  Float_t mc_boson_l2_eta;
  Float_t mc_boson_ll_mass;
  Float_t mc_boson_ll_pt;
  Float_t mc_boson_ll_dphi;
  Float_t mc_boson_j1_pt;
  Float_t mc_boson_j1_eta;
  Float_t mc_boson_j2_pt;
  Float_t mc_boson_j2_eta;
  Float_t mc_boson_jj_mass;
  Float_t mc_boson_jj_pt;
  Float_t mc_boson_jj_dphi;
  Float_t mc_met;
  Int_t mc_njets25;

  Int_t mc_3l_category;

  Int_t mc_ttZhypAllowed;
  Int_t mc_hasLLcombZpeak;
  Int_t mc_passMllGt12;
  Int_t mc_passLepPresel;
  Int_t mc_passJetPresel25;
  Int_t mc_passBjetPresel25;

  Int_t catJets;
  Char_t is_2lss_TTH_SR;
  Char_t is_3l_TTH_SR;

  // Char_t is_emu_TT_CR; //CHANGED -- removed
  //Char_t is_Zl_CR;
  // Char_t is_3l_TTZ_CR;
  // Char_t is_3l_WZrel_CR;
  // Char_t is_3l_TZQ_SR;

  Char_t is_3l_THQ_SR; //CHANGED -- added
  Char_t is_2l_THQ_SR;
  Char_t is_3l_THQ_Training;
  Char_t is_2l_THQ_Training;
  Char_t is_3l_Z_CR;
  Char_t is_2l_EMU_CR;
  Char_t is_3l_AppFakes_SR;
  Char_t is_2l_AppFakes_SR;
  Char_t is_2l_QFlip_SR;
  Char_t is_3l_GammaConv_SR;
  Char_t is_2l_GammaConv_SR;

  Char_t cat_HtoWW;
  Char_t cat_HtoZZ;
  Char_t cat_Htott;

  //MEM input variables

  Int_t 		multilepton_Lepton1_Id, 		multilepton_Lepton2_Id, 		multilepton_Lepton3_Id, 		multilepton_Lepton4_Id;
  TLorentzVector 	multilepton_Lepton1_P4, 		multilepton_Lepton2_P4, 		multilepton_Lepton3_P4, 		multilepton_Lepton4_P4;

  Float_t           	multilepton_Lepton1_DeltaR_Matched,  	multilepton_Lepton2_DeltaR_Matched,  	multilepton_Lepton3_DeltaR_Matched,  	multilepton_Lepton4_DeltaR_Matched;
  Int_t           	multilepton_Lepton1_Label_Matched,   	multilepton_Lepton2_Label_Matched,   	multilepton_Lepton3_Label_Matched,   	multilepton_Lepton4_Label_Matched;
  Int_t           	multilepton_Lepton1_Id_Matched,      	multilepton_Lepton2_Id_Matched,      	multilepton_Lepton3_Id_Matched,      	multilepton_Lepton4_Id_Matched;
  TLorentzVector  	multilepton_Lepton1_P4_Matched,      	multilepton_Lepton2_P4_Matched,      	multilepton_Lepton3_P4_Matched,      	multilepton_Lepton4_P4_Matched;

  Int_t 		multilepton_Bjet1_Id, 								multilepton_Bjet2_Id;
  TLorentzVector 	multilepton_Bjet1_P4, 								multilepton_Bjet2_P4;
  Float_t 		multilepton_Bjet1_CSV, 								multilepton_Bjet2_CSV;
  Float_t		multilepton_Bjet1_JEC_Up, 		multilepton_Bjet1_JEC_Down, 		multilepton_Bjet2_JEC_Up, 		multilepton_Bjet2_JEC_Down;
  Float_t 		multilepton_Bjet1_JER_Up, 		multilepton_Bjet1_JER_Down, 		multilepton_Bjet2_JER_Up, 		multilepton_Bjet2_JER_Down;

  Float_t           	multilepton_Bjet1_DeltaR_Matched,   						multilepton_Bjet2_DeltaR_Matched;
  Int_t           	multilepton_Bjet1_Label_Matched,    						multilepton_Bjet2_Label_Matched;
  Int_t           	multilepton_Bjet1_Id_Matched,       						multilepton_Bjet2_Id_Matched;
  TLorentzVector  	multilepton_Bjet1_P4_Matched,       						multilepton_Bjet2_P4_Matched;

  Int_t 		multilepton_h0_Id, 			multilepton_t1_Id,			multilepton_t2_Id;
  Int_t                 multilepton_h0_Label,                   multilepton_t1_Label,                   multilepton_t2_Label;
  TLorentzVector 	multilepton_h0_P4,			multilepton_t1_P4,			multilepton_t2_P4;

        Int_t multilepton_JetHighestPt1_Id, multilepton_JetHighestPt2_Id, multilepton_JetClosestMw1_Id, multilepton_JetClosestMw2_Id, multilepton_JetLowestMjj1_Id, multilepton_JetLowestMjj2_Id, multilepton_JetHighestEta1_Id, multilepton_JetHighestEta2_Id;
        TLorentzVector multilepton_JetHighestPt1_P4, multilepton_JetHighestPt2_P4, multilepton_JetClosestMw1_P4, multilepton_JetClosestMw2_P4, multilepton_JetLowestMjj1_P4, multilepton_JetLowestMjj2_P4, multilepton_JetHighestEta1_P4, multilepton_JetHighestEta2_P4;
        Float_t multilepton_JetHighestPt1_CSV, multilepton_JetHighestPt2_CSV, multilepton_JetClosestMw1_CSV, multilepton_JetClosestMw2_CSV, multilepton_JetLowestMjj1_CSV, multilepton_JetLowestMjj2_CSV, multilepton_JetHighestEta1_CSV, multilepton_JetHighestEta2_CSV;
        Float_t multilepton_JetHighestPt1_JEC_Up, multilepton_JetHighestPt2_JEC_Up, multilepton_JetClosestMw1_JEC_Up, multilepton_JetClosestMw2_JEC_Up, multilepton_JetLowestMjj1_JEC_Up, multilepton_JetLowestMjj2_JEC_Up, multilepton_JetHighestEta1_JEC_Up, multilepton_JetHighestEta2_JEC_Up;
        Float_t multilepton_JetHighestPt1_JEC_Down, multilepton_JetHighestPt2_JEC_Down, multilepton_JetClosestMw1_JEC_Down, multilepton_JetClosestMw2_JEC_Down, multilepton_JetLowestMjj1_JEC_Down, multilepton_JetLowestMjj2_JEC_Down, multilepton_JetHighestEta1_JEC_Down, multilepton_JetHighestEta2_JEC_Down;
        Float_t multilepton_JetHighestPt1_JER_Up, multilepton_JetHighestPt2_JER_Up, multilepton_JetClosestMw1_JER_Up, multilepton_JetClosestMw2_JER_Up, multilepton_JetLowestMjj1_JER_Up, multilepton_JetLowestMjj2_JER_Up, multilepton_JetHighestEta1_JER_Up, multilepton_JetHighestEta2_JER_Up;
        Float_t multilepton_JetHighestPt1_JER_Down, multilepton_JetHighestPt2_JER_Down, multilepton_JetClosestMw1_JER_Down, multilepton_JetClosestMw2_JER_Down, multilepton_JetLowestMjj1_JER_Down, multilepton_JetLowestMjj2_JER_Down, multilepton_JetHighestEta1_JER_Down, multilepton_JetHighestEta2_JER_Down;

  Int_t multilepton_JetHighestPt1_2ndPair_Id, multilepton_JetHighestPt2_2ndPair_Id, multilepton_JetClosestMw1_2ndPair_Id, multilepton_JetClosestMw2_2ndPair_Id, multilepton_JetLowestMjj1_2ndPair_Id, multilepton_JetLowestMjj2_2ndPair_Id;
  TLorentzVector  multilepton_JetHighestPt1_2ndPair_P4, multilepton_JetHighestPt2_2ndPair_P4, multilepton_JetClosestMw1_2ndPair_P4, multilepton_JetClosestMw2_2ndPair_P4, multilepton_JetLowestMjj1_2ndPair_P4, multilepton_JetLowestMjj2_2ndPair_P4;
  Float_t multilepton_JetHighestPt1_2ndPair_CSV, multilepton_JetHighestPt2_2ndPair_CSV, multilepton_JetClosestMw1_2ndPair_CSV, multilepton_JetClosestMw2_2ndPair_CSV, multilepton_JetLowestMjj1_2ndPair_CSV, multilepton_JetLowestMjj2_2ndPair_CSV;
  Float_t multilepton_JetHighestPt1_2ndPair_JEC_Up, multilepton_JetHighestPt2_2ndPair_JEC_Up, multilepton_JetClosestMw1_2ndPair_JEC_Up, multilepton_JetClosestMw2_2ndPair_JEC_Up, multilepton_JetLowestMjj1_2ndPair_JEC_Up, multilepton_JetLowestMjj2_2ndPair_JEC_Up;
  Float_t multilepton_JetHighestPt1_2ndPair_JEC_Down, multilepton_JetHighestPt2_2ndPair_JEC_Down, multilepton_JetClosestMw1_2ndPair_JEC_Down, multilepton_JetClosestMw2_2ndPair_JEC_Down, multilepton_JetLowestMjj1_2ndPair_JEC_Down, multilepton_JetLowestMjj2_2ndPair_JEC_Down;
  Float_t multilepton_JetHighestPt1_2ndPair_JER_Up, multilepton_JetHighestPt2_2ndPair_JER_Up, multilepton_JetClosestMw1_2ndPair_JER_Up, multilepton_JetClosestMw2_2ndPair_JER_Up, multilepton_JetLowestMjj1_2ndPair_JER_Up, multilepton_JetLowestMjj2_2ndPair_JER_Up;
  Float_t multilepton_JetHighestPt1_2ndPair_JER_Down, multilepton_JetHighestPt2_2ndPair_JER_Down, multilepton_JetClosestMw1_2ndPair_JER_Down, multilepton_JetClosestMw2_2ndPair_JER_Down, multilepton_JetLowestMjj1_2ndPair_JER_Down, multilepton_JetLowestMjj2_2ndPair_JER_Down;

  Float_t nJets;
  vector<Float_t>* JetsPt;
  vector<Float_t>* JetsEta;
  vector<Float_t>* JetsPhi;
  vector<Float_t>* JetsE;
  vector<Float_t>* JetsCSV;

  TLorentzVector multilepton_mET;
  Double_t multilepton_mETcov00, multilepton_mETcov01, multilepton_mETcov10, multilepton_mETcov11;
  Float_t multilepton_sumET;
  TLorentzVector multilepton_Ptot;

  TLorentzVector* multilepton_Bjet1_P4_ptr;
  TLorentzVector* multilepton_Bjet1_P4_Matched_ptr;
  TLorentzVector* multilepton_Bjet2_P4_ptr;
  TLorentzVector* multilepton_Bjet2_P4_Matched_ptr;
  TLorentzVector* multilepton_Lepton1_P4_ptr;
  TLorentzVector* multilepton_Lepton1_P4_Matched_ptr;
  TLorentzVector* multilepton_Lepton2_P4_ptr;
  TLorentzVector* multilepton_Lepton2_P4_Matched_ptr;
  TLorentzVector* multilepton_Lepton3_P4_ptr;
  TLorentzVector* multilepton_Lepton3_P4_Matched_ptr;
  TLorentzVector* multilepton_Lepton4_P4_ptr;
  TLorentzVector* multilepton_Lepton4_P4_Matched_ptr;
  TLorentzVector* multilepton_JetHighestPt1_P4_ptr;
  TLorentzVector* multilepton_JetHighestPt2_P4_ptr;
  TLorentzVector* multilepton_JetClosestMw1_P4_ptr;
  TLorentzVector* multilepton_JetClosestMw2_P4_ptr;
  TLorentzVector* multilepton_JetLowestMjj1_P4_ptr;
  TLorentzVector* multilepton_JetLowestMjj2_P4_ptr;
  TLorentzVector* multilepton_JetHighestEta1_P4_ptr;
  TLorentzVector* multilepton_JetHighestEta2_P4_ptr;
  TLorentzVector* multilepton_JetHighestPt1_2ndPair_P4_ptr;
  TLorentzVector* multilepton_JetHighestPt2_2ndPair_P4_ptr;
  TLorentzVector* multilepton_JetClosestMw1_2ndPair_P4_ptr;
  TLorentzVector* multilepton_JetClosestMw2_2ndPair_P4_ptr;
  TLorentzVector* multilepton_JetLowestMjj1_2ndPair_P4_ptr;
  TLorentzVector* multilepton_JetLowestMjj2_2ndPair_P4_ptr;
  TLorentzVector* multilepton_h0_P4_ptr;
  TLorentzVector* multilepton_t1_P4_ptr;
  TLorentzVector* multilepton_t2_P4_ptr;

  TLorentzVector* multilepton_mET_ptr;
  TLorentzVector* multilepton_Ptot_ptr;

  //MEM output variables
  Double_t mc_mem_tthfl_weight;
  Double_t mc_mem_tthfl_weight_JEC_up, mc_mem_tthfl_weight_JEC_down, mc_mem_tthfl_weight_JER_up, mc_mem_tthfl_weight_JER_down;
  Double_t mc_mem_tthfl_weight_log;
  Double_t mc_mem_tthfl_weight_err;
  Float_t mc_mem_tthfl_weight_chi2;
  Float_t mc_mem_tthfl_weight_time;
  Double_t mc_mem_tthfl_weight_max;
  Double_t mc_mem_tthfl_weight_avg;
  Double_t mc_mem_tthfl_weight_logmean;
  Double_t mc_kin_tthfl_weight_logmax;
  Double_t mc_kin_tthfl_weight_logmaxint;
  Double_t mc_mem_tthfl_weight_kinmax;
  Double_t mc_mem_tthfl_weight_kinmaxint;

  TLorentzVector mc_kin_tthfl_tophad_P4;
  TLorentzVector mc_kin_tthfl_tophad_Bjet_P4;
  TLorentzVector mc_kin_tthfl_tophad_W_P4;
  TLorentzVector mc_kin_tthfl_tophad_Jet1_P4;
  TLorentzVector mc_kin_tthfl_tophad_Jet2_P4;
  Float_t mc_kin_tthfl_tophad_Pt;
  Float_t mc_kin_tthfl_tophad_Wmass;
  Float_t mc_kin_tthfl_tophad_Benergy;
  Float_t mc_kin_tthfl_tophad_Jet1energy;
  Float_t mc_kin_tthfl_tophad_Jet2energy;
  TLorentzVector mc_kin_tthfl_toplep_P4;
  TLorentzVector mc_kin_tthfl_toplep_Bjet_P4;
  TLorentzVector mc_kin_tthfl_toplep_W_P4;
  TLorentzVector mc_kin_tthfl_toplep_Lep_P4;
  TLorentzVector mc_kin_tthfl_toplep_Neut_P4;
  Float_t mc_kin_tthfl_toplep_Pt;
  Float_t mc_kin_tthfl_toplep_Wmass;
  Float_t mc_kin_tthfl_toplep_Benergy;
  Float_t mc_kin_tthfl_toplep_Neutenergy;
  TLorentzVector mc_kin_tthfl_toplep2_P4;
  TLorentzVector mc_kin_tthfl_toplep2_Bjet_P4;
  TLorentzVector mc_kin_tthfl_toplep2_W_P4;
  TLorentzVector mc_kin_tthfl_toplep2_Lep_P4;
  TLorentzVector mc_kin_tthfl_toplep2_Neut_P4;
  Float_t mc_kin_tthfl_toplep2_Pt;
  Float_t mc_kin_tthfl_toplep2_Wmass;
  Float_t mc_kin_tthfl_toplep2_Benergy;
  Float_t mc_kin_tthfl_toplep2_Neutenergy;
  TLorentzVector mc_kin_tthfl_h2l2nu_P4;
  TLorentzVector mc_kin_tthfl_h2l2nu_W1_P4;
  TLorentzVector mc_kin_tthfl_h2l2nu_W2_P4;
  TLorentzVector mc_kin_tthfl_h2l2nu_Lep1_P4;
  TLorentzVector mc_kin_tthfl_h2l2nu_Neut1_P4;
  TLorentzVector mc_kin_tthfl_h2l2nu_Lep2_P4;
  TLorentzVector mc_kin_tthfl_h2l2nu_Neut2_P4;
  Float_t mc_kin_tthfl_h2l2nu_Pt;
  Float_t mc_kin_tthfl_h2l2nu_W1mass;
  Float_t mc_kin_tthfl_h2l2nu_Neut1energy;
  Float_t mc_kin_tthfl_h2l2nu_W2mass;
  Float_t mc_kin_tthfl_h2l2nu_Neut2energy;

  Double_t mc_mem_tthsl_weight;
  Double_t mc_mem_tthsl_weight_JEC_up, mc_mem_tthsl_weight_JEC_down, mc_mem_tthsl_weight_JER_up, mc_mem_tthsl_weight_JER_down;
  Double_t mc_mem_tthsl_weight_log;
  Double_t mc_mem_tthsl_weight_err;
  Float_t mc_mem_tthsl_weight_chi2;
  Float_t mc_mem_tthsl_weight_time;
  Double_t mc_mem_tthsl_weight_max;
  Double_t mc_mem_tthsl_weight_avg;
  Double_t mc_mem_tthsl_weight_logmean;
  Double_t mc_kin_tthsl_weight_logmax;
  Double_t mc_kin_tthsl_weight_logmaxint;
  Double_t mc_mem_tthsl_weight_kinmax;
  Double_t mc_mem_tthsl_weight_kinmaxint;

  TLorentzVector mc_kin_tthsl_tophad_P4;
  TLorentzVector mc_kin_tthsl_tophad_Bjet_P4;
  TLorentzVector mc_kin_tthsl_tophad_W_P4;
  TLorentzVector mc_kin_tthsl_tophad_Jet1_P4;
  TLorentzVector mc_kin_tthsl_tophad_Jet2_P4;
  Float_t mc_kin_tthsl_tophad_Pt;
  Float_t mc_kin_tthsl_tophad_Wmass;
  Float_t mc_kin_tthsl_tophad_Benergy;
  Float_t mc_kin_tthsl_tophad_Jet1energy;
  Float_t mc_kin_tthsl_tophad_Jet2energy;
  TLorentzVector mc_kin_tthsl_toplep_P4;
  TLorentzVector mc_kin_tthsl_toplep_Bjet_P4;
  TLorentzVector mc_kin_tthsl_toplep_W_P4;
  TLorentzVector mc_kin_tthsl_toplep_Lep_P4;
  TLorentzVector mc_kin_tthsl_toplep_Neut_P4;
  Float_t mc_kin_tthsl_toplep_Pt;
  Float_t mc_kin_tthsl_toplep_Wmass;
  Float_t mc_kin_tthsl_toplep_Benergy;
  Float_t mc_kin_tthsl_toplep_Neutenergy;
  TLorentzVector mc_kin_tthsl_toplep2_P4;
  TLorentzVector mc_kin_tthsl_toplep2_Bjet_P4;
  TLorentzVector mc_kin_tthsl_toplep2_W_P4;
  TLorentzVector mc_kin_tthsl_toplep2_Lep_P4;
  TLorentzVector mc_kin_tthsl_toplep2_Neut_P4;
  Float_t mc_kin_tthsl_toplep2_Pt;
  Float_t mc_kin_tthsl_toplep2_Wmass;
  Float_t mc_kin_tthsl_toplep2_Benergy;
  Float_t mc_kin_tthsl_toplep2_Neutenergy;
  TLorentzVector mc_kin_tthsl_hlnujj_P4;
  TLorentzVector mc_kin_tthsl_hlnujj_W1_P4;
  TLorentzVector mc_kin_tthsl_hlnujj_W2_P4;
  TLorentzVector mc_kin_tthsl_hlnujj_Lep_P4;
  TLorentzVector mc_kin_tthsl_hlnujj_Neut_P4;
  TLorentzVector mc_kin_tthsl_hlnujj_Jet1_P4;
  TLorentzVector mc_kin_tthsl_hlnujj_Jet2_P4;
  Float_t mc_kin_tthsl_hlnujj_Pt;
  Float_t mc_kin_tthsl_hlnujj_W1mass;
  Float_t mc_kin_tthsl_hlnujj_Neut1energy;
  Float_t mc_kin_tthsl_hlnujj_W2mass;
  Float_t mc_kin_tthsl_hlnujj_Jet1energy;
  Float_t mc_kin_tthsl_hlnujj_Jet2energy;

  Double_t mc_mem_tth_weight;
  Double_t mc_mem_tth_weight_JEC_up, mc_mem_tth_weight_JEC_down, mc_mem_tth_weight_JER_up, mc_mem_tth_weight_JER_down;
  Double_t mc_mem_tth_weight_log;
  Double_t mc_mem_tth_weight_err;
  Float_t mc_mem_tth_weight_chi2;
  Float_t mc_mem_tth_weight_time;
  Double_t mc_mem_tth_weight_max;
  Double_t mc_mem_tth_weight_avg;
  Double_t mc_mem_tth_weight_logmean;
  Double_t mc_kin_tth_weight_logmax;
  Double_t mc_kin_tth_weight_logmaxint;
  Double_t mc_mem_tth_weight_kinmax;
  Double_t mc_mem_tth_weight_kinmaxint;

  Double_t mc_mem_ttz_weight;
  Double_t mc_mem_ttz_weight_JEC_up, mc_mem_ttz_weight_JEC_down, mc_mem_ttz_weight_JER_up, mc_mem_ttz_weight_JER_down;
  Double_t mc_mem_ttz_weight_log;
  Double_t mc_mem_ttz_weight_err;
  Float_t mc_mem_ttz_weight_chi2;
  Float_t mc_mem_ttz_weight_time;
  Double_t mc_mem_ttz_weight_max;
  Double_t mc_mem_ttz_weight_avg;
  Double_t mc_mem_ttz_weight_logmean;
  Double_t mc_kin_ttz_weight_logmax;
  Double_t mc_kin_ttz_weight_logmaxint;
  Double_t mc_mem_ttz_weight_kinmax;
  Double_t mc_mem_ttz_weight_kinmaxint;

  TLorentzVector mc_kin_ttz_tophad_P4;
  TLorentzVector mc_kin_ttz_tophad_Bjet_P4;
  TLorentzVector mc_kin_ttz_tophad_W_P4;
  TLorentzVector mc_kin_ttz_tophad_Jet1_P4;
  TLorentzVector mc_kin_ttz_tophad_Jet2_P4;
  Float_t mc_kin_ttz_tophad_Pt;
  Float_t mc_kin_ttz_tophad_Wmass;
  Float_t mc_kin_ttz_tophad_Benergy;
  Float_t mc_kin_ttz_tophad_Jet1energy;
  Float_t mc_kin_ttz_tophad_Jet2energy;
  TLorentzVector mc_kin_ttz_toplep_P4;
  TLorentzVector mc_kin_ttz_toplep_Bjet_P4;
  TLorentzVector mc_kin_ttz_toplep_W_P4;
  TLorentzVector mc_kin_ttz_toplep_Lep_P4;
  TLorentzVector mc_kin_ttz_toplep_Neut_P4;
  Float_t mc_kin_ttz_toplep_Pt;
  Float_t mc_kin_ttz_toplep_Wmass;
  Float_t mc_kin_ttz_toplep_Benergy;
  Float_t mc_kin_ttz_toplep_Neutenergy;
  TLorentzVector mc_kin_ttz_toplep2_P4;
  TLorentzVector mc_kin_ttz_toplep2_Bjet_P4;
  TLorentzVector mc_kin_ttz_toplep2_W_P4;
  TLorentzVector mc_kin_ttz_toplep2_Lep_P4;
  TLorentzVector mc_kin_ttz_toplep2_Neut_P4;
  Float_t mc_kin_ttz_toplep2_Pt;
  Float_t mc_kin_ttz_toplep2_Wmass;
  Float_t mc_kin_ttz_toplep2_Benergy;
  Float_t mc_kin_ttz_toplep2_Neutenergy;
  TLorentzVector mc_kin_ttz_zll_P4;
  TLorentzVector mc_kin_ttz_zll_Lep1_P4;
  TLorentzVector mc_kin_ttz_zll_Lep2_P4;
  Float_t mc_kin_ttz_zll_Pt;
  Float_t mc_kin_ttz_zll_Zmass;

  Double_t mc_mem_ttw_weight;
  Double_t mc_mem_ttw_weight_JEC_up, mc_mem_ttw_weight_JEC_down, mc_mem_ttw_weight_JER_up, mc_mem_ttw_weight_JER_down;
  Double_t mc_mem_ttw_weight_log;
  Double_t mc_mem_ttw_weight_err;
  Float_t mc_mem_ttw_weight_chi2;
  Float_t mc_mem_ttw_weight_time;
  Double_t mc_mem_ttw_weight_max;
  Double_t mc_mem_ttw_weight_avg;
  Double_t mc_mem_ttw_weight_logmean;
  Double_t mc_kin_ttw_weight_logmax;
  Double_t mc_kin_ttw_weight_logmaxint;
  Double_t mc_mem_ttw_weight_kinmax;
  Double_t mc_mem_ttw_weight_kinmaxint;

  TLorentzVector mc_kin_ttw_tophad_P4;
  TLorentzVector mc_kin_ttw_tophad_Bjet_P4;
  TLorentzVector mc_kin_ttw_tophad_W_P4;
  TLorentzVector mc_kin_ttw_tophad_Jet1_P4;
  TLorentzVector mc_kin_ttw_tophad_Jet2_P4;
  Float_t mc_kin_ttw_tophad_Pt;
  Float_t mc_kin_ttw_tophad_Wmass;
  Float_t mc_kin_ttw_tophad_Benergy;
  Float_t mc_kin_ttw_tophad_Jet1energy;
  Float_t mc_kin_ttw_tophad_Jet2energy;
  TLorentzVector mc_kin_ttw_toplep_P4;
  TLorentzVector mc_kin_ttw_toplep_Bjet_P4;
  TLorentzVector mc_kin_ttw_toplep_W_P4;
  TLorentzVector mc_kin_ttw_toplep_Lep_P4;
  TLorentzVector mc_kin_ttw_toplep_Neut_P4;
  Float_t mc_kin_ttw_toplep_Pt;
  Float_t mc_kin_ttw_toplep_Wmass;
  Float_t mc_kin_ttw_toplep_Benergy;
  Float_t mc_kin_ttw_toplep_Neutenergy;
  TLorentzVector mc_kin_ttw_toplep2_P4;
  TLorentzVector mc_kin_ttw_toplep2_Bjet_P4;
  TLorentzVector mc_kin_ttw_toplep2_W_P4;
  TLorentzVector mc_kin_ttw_toplep2_Lep_P4;
  TLorentzVector mc_kin_ttw_toplep2_Neut_P4;
  Float_t mc_kin_ttw_toplep2_Pt;
  Float_t mc_kin_ttw_toplep2_Wmass;
  Float_t mc_kin_ttw_toplep2_Benergy;
  Float_t mc_kin_ttw_toplep2_Neutenergy;
  TLorentzVector mc_kin_ttw_wlnu_W_P4;
  TLorentzVector mc_kin_ttw_wlnu_Lep_P4;
  TLorentzVector mc_kin_ttw_wlnu_Neut_P4;
  Float_t mc_kin_ttw_wlnu_Pt;
  Float_t mc_kin_ttw_wlnu_Wmass;
  Float_t mc_kin_ttw_wlnu_Neutenergy;

  Double_t mc_mem_ttwjj_weight;
  Double_t mc_mem_ttwjj_weight_JEC_up, mc_mem_ttwjj_weight_JEC_down, mc_mem_ttwjj_weight_JER_up, mc_mem_ttwjj_weight_JER_down;
  Double_t mc_mem_ttwjj_weight_log;
  Double_t mc_mem_ttwjj_weight_err;
  Float_t mc_mem_ttwjj_weight_chi2;
  Float_t mc_mem_ttwjj_weight_time;
  Double_t mc_mem_ttwjj_weight_max;
  Double_t mc_mem_ttwjj_weight_avg;
  Double_t mc_mem_ttwjj_weight_logmean;
  Double_t mc_kin_ttwjj_weight_logmax;
  Double_t mc_kin_ttwjj_weight_logmaxint;
  Double_t mc_mem_ttwjj_weight_kinmax;
  Double_t mc_mem_ttwjj_weight_kinmaxint;

  Double_t mc_mem_ttbarfl_weight;
  Double_t mc_mem_ttbarfl_weight_JEC_up, mc_mem_ttbarfl_weight_JEC_down, mc_mem_ttbarfl_weight_JER_up, mc_mem_ttbarfl_weight_JER_down;
  Double_t mc_mem_ttbarfl_weight_log;
  Double_t mc_mem_ttbarfl_weight_err;
  Float_t mc_mem_ttbarfl_weight_chi2;
  Float_t mc_mem_ttbarfl_weight_time;
  Double_t mc_mem_ttbarfl_weight_max;
  Double_t mc_mem_ttbarfl_weight_avg;
  Double_t mc_mem_ttbarfl_weight_logmean;
  Double_t mc_kin_ttbarfl_weight_logmax;
  Double_t mc_kin_ttbarfl_weight_logmaxint;
  Double_t mc_mem_ttbarfl_weight_kinmax;
  Double_t mc_mem_ttbarfl_weight_kinmaxint;

  Double_t mc_mem_ttbarsl_weight;
  Double_t mc_mem_ttbarsl_weight_JEC_up, mc_mem_ttbarsl_weight_JEC_down, mc_mem_ttbarsl_weight_JER_up, mc_mem_ttbarsl_weight_JER_down;
  Double_t mc_mem_ttbarsl_weight_log;
  Double_t mc_mem_ttbarsl_weight_err;
  Float_t mc_mem_ttbarsl_weight_chi2;
  Float_t mc_mem_ttbarsl_weight_time;
  Double_t mc_mem_ttbarsl_weight_max;
  Double_t mc_mem_ttbarsl_weight_avg;
  Double_t mc_mem_ttbarsl_weight_logmean;
  Double_t mc_kin_ttbarsl_weight_logmax;
  Double_t mc_kin_ttbarsl_weight_logmaxint;
  Double_t mc_mem_ttbarsl_weight_kinmax;
  Double_t mc_mem_ttbarsl_weight_kinmaxint;

  Double_t mc_mem_ttbar_weight;
  Double_t mc_mem_ttbar_weight_JEC_up, mc_mem_ttbar_weight_JEC_down, mc_mem_ttbar_weight_JER_up, mc_mem_ttbar_weight_JER_down;
  Double_t mc_mem_ttbar_weight_log;
  Double_t mc_mem_ttbar_weight_err;
  Float_t mc_mem_ttbar_weight_chi2;
  Float_t mc_mem_ttbar_weight_time;
  Double_t mc_mem_ttbar_weight_max;
  Double_t mc_mem_ttbar_weight_avg;
  Double_t mc_mem_ttbar_weight_logmean;
  Double_t mc_kin_ttbar_weight_logmax;
  Double_t mc_kin_ttbar_weight_logmaxint;
  Double_t mc_mem_ttbar_weight_kinmax;
  Double_t mc_mem_ttbar_weight_kinmaxint;

  Double_t mc_mem_tllj_weight;
  Double_t mc_mem_tllj_weight_JEC_up, mc_mem_tllj_weight_JEC_down, mc_mem_tllj_weight_JER_up, mc_mem_tllj_weight_JER_down;
  Double_t mc_mem_tllj_weight_log;
  Double_t mc_mem_tllj_weight_err;
  Float_t mc_mem_tllj_weight_chi2;
  Float_t mc_mem_tllj_weight_time;
  Double_t mc_mem_tllj_weight_max;
  Double_t mc_mem_tllj_weight_avg;
  Double_t mc_mem_tllj_weight_logmean;
  Double_t mc_kin_tllj_weight_logmax;
  Double_t mc_kin_tllj_weight_logmaxint;
  Double_t mc_mem_tllj_weight_kinmax;
  Double_t mc_mem_tllj_weight_kinmaxint;

  Double_t mc_mem_wzjj_weight;
  Double_t mc_mem_wzjj_weight_JEC_up, mc_mem_wzjj_weight_JEC_down, mc_mem_wzjj_weight_JER_up, mc_mem_wzjj_weight_JER_down;
  Double_t mc_mem_wzjj_weight_log;
  Double_t mc_mem_wzjj_weight_err;
  Float_t mc_mem_wzjj_weight_chi2;
  Float_t mc_mem_wzjj_weight_time;
  Double_t mc_mem_wzjj_weight_max;
  Double_t mc_mem_wzjj_weight_avg;
  Double_t mc_mem_wzjj_weight_logmean;
  Double_t mc_kin_wzjj_weight_logmax;
  Double_t mc_kin_wzjj_weight_logmaxint;
  Double_t mc_mem_wzjj_weight_kinmax;
  Double_t mc_mem_wzjj_weight_kinmaxint;

  Double_t mc_mem_thj_weight;
  Double_t mc_mem_thj_weight_JEC_up, mc_mem_thj_weight_JEC_down, mc_mem_thj_weight_JER_up, mc_mem_thj_weight_JER_down;
  Double_t mc_mem_thj_weight_log;
  Double_t mc_mem_thj_weight_err;
  Float_t mc_mem_thj_weight_chi2;
  Float_t mc_mem_thj_weight_time;
  Double_t mc_mem_thj_weight_max;
  Double_t mc_mem_thj_weight_avg;
  Double_t mc_mem_thj_weight_logmean;
  Double_t mc_kin_thj_weight_logmax;
  Double_t mc_kin_thj_weight_logmaxint;
  Double_t mc_mem_thj_weight_kinmax;
  Double_t mc_mem_thj_weight_kinmaxint;


  //Double_t mc_mem_ttz_tthfl_likelihood;
  //Double_t mc_mem_ttz_tthsl_likelihood;
  //Double_t mc_mem_ttw_tthfl_likelihood;
  //Double_t mc_mem_ttw_tthsl_likelihood;
  Double_t mc_mem_ttz_tth_likelihood;
  Double_t mc_mem_ttz_tth_likelihood_nlog;
  Double_t mc_mem_ttz_tth_likelihood_max;
  Double_t mc_mem_ttz_tth_likelihood_avg;

  Double_t mc_mem_ttw_tth_likelihood;
  Double_t mc_mem_ttw_tth_likelihood_nlog;
  Double_t mc_mem_ttw_tth_likelihood_max;
  Double_t mc_mem_ttw_tth_likelihood_avg;

  Double_t mc_mem_ttwjj_tth_likelihood;
  Double_t mc_mem_ttwjj_tth_likelihood_nlog;
  Double_t mc_mem_ttwjj_tth_likelihood_max;
  Double_t mc_mem_ttwjj_tth_likelihood_avg;

  Double_t mc_mem_ttbar_tth_likelihood;
  Double_t mc_mem_ttbar_tth_likelihood_nlog;
  Double_t mc_mem_ttbar_tth_likelihood_max;
  Double_t mc_mem_ttbar_tth_likelihood_avg;

  Double_t mc_mem_ttz_tllj_likelihood;
  Double_t mc_mem_ttz_tllj_likelihood_nlog;
  Double_t mc_mem_ttz_tllj_likelihood_max;
  Double_t mc_mem_ttz_tllj_likelihood_avg;

  Double_t mc_mem_ttv_tth_likelihood;
  Double_t mc_mem_ttv_tth_likelihood_nlog;
  Double_t mc_mem_ttv_tth_likelihood_max;
  Double_t mc_mem_ttv_tth_likelihood_avg;

  Double_t mc_mem_ttvjj_tth_likelihood;
  Double_t mc_mem_ttvjj_tth_likelihood_nlog;
  Double_t mc_mem_ttvjj_tth_likelihood_max;
  Double_t mc_mem_ttvjj_tth_likelihood_avg;
  /*
  std::vector<double>* MEAllWeights_TTLL;
  std::vector<double>* MEAllWeights_TTHfl;
  std::vector<double>* MEAllWeights_TTHsl;
  std::vector<double>* MEAllWeights_TTH;
  std::vector<double>* MEAllWeights_TTW;
  std::vector<double>* MEAllWeights_TTWJJ;
  std::vector<double>* MEAllWeights_TTbarfl;
  std::vector<double>* MEAllWeights_TTbarsl;
  std::vector<double>* MEAllWeights_TTbar;
  std::vector<double>* MEAllWeights_TLLJ;

  std::vector<float>* MEAllWeights_TTLL_log;
  std::vector<float>* MEAllWeights_TTHfl_log;
  std::vector<float>* MEAllWeights_TTHsl_log;
  std::vector<float>* MEAllWeights_TTH_log;
  std::vector<float>* MEAllWeights_TTW_log;
  std::vector<float>* MEAllWeights_TTWJJ_log;
  std::vector<float>* MEAllWeights_TTbarfl_log;
  std::vector<float>* MEAllWeights_TTbarsl_log;
  std::vector<float>* MEAllWeights_TTbar_log;
  std::vector<float>* MEAllWeights_TLLJ_log;
  */
  TBranch* b_catJets;
  TBranch* b_is_2lss_TTH_SR;
  TBranch* b_is_3l_TTH_SR;

  // TBranch* b_is_3l_TTZ_CR; //CHANGED -- removed
  // TBranch* b_is_emu_TT_CR;
  //TBranch* b_is_Zl_CR;
  //TBranch* b_is_3l_WZrel_CR;
  // TBranch* b_is_3l_TZQ_SR;

  TBranch* b_is_3l_THQ_SR;
  TBranch* b_is_2l_THQ_SR;
  TBranch* b_is_3l_THQ_Training;
  TBranch* b_is_2l_THQ_Training;
  TBranch* b_is_3l_Z_CR;
  TBranch* b_is_2l_EMU_CR;
  TBranch* b_is_3l_AppFakes_SR;
  TBranch* b_is_2l_AppFakes_SR;
  TBranch* b_is_2l_QFlip_SR;
  TBranch* b_is_3l_GammaConv_SR;
  TBranch* b_is_2l_GammaConv_SR;

  TBranch* b_mc_3l_category;
  TBranch* b_mc_ttbar_decay;
  TBranch* b_mc_boson_decay;
  TBranch* b_mc_ttZhypAllowed;

  TBranch* b_cat_HtoWW;
  TBranch* b_cat_HtoZZ;
  TBranch* b_cat_Htott;

  TBranch* b_multilepton_Lepton1_Id;
  TBranch* b_multilepton_Lepton1_P4;
  TBranch* b_multilepton_Lepton1_DeltaR_Matched;
  TBranch* b_multilepton_Lepton1_Label_Matched;
  TBranch* b_multilepton_Lepton1_Id_Matched;
  TBranch* b_multilepton_Lepton1_P4_Matched;

  TBranch* b_multilepton_Lepton2_Id;
  TBranch* b_multilepton_Lepton2_P4;
  TBranch* b_multilepton_Lepton2_DeltaR_Matched;
  TBranch* b_multilepton_Lepton2_Label_Matched;
  TBranch* b_multilepton_Lepton2_Id_Matched;
  TBranch* b_multilepton_Lepton2_P4_Matched;

  TBranch* b_multilepton_Lepton3_Id;
  TBranch* b_multilepton_Lepton3_P4;
  TBranch* b_multilepton_Lepton3_DeltaR_Matched;
  TBranch* b_multilepton_Lepton3_Label_Matched;
  TBranch* b_multilepton_Lepton3_Id_Matched;
  TBranch* b_multilepton_Lepton3_P4_Matched;

  TBranch* b_multilepton_Lepton4_Id;
  TBranch* b_multilepton_Lepton4_P4;
  TBranch* b_multilepton_Lepton4_DeltaR_Matched;
  TBranch* b_multilepton_Lepton4_Label_Matched;
  TBranch* b_multilepton_Lepton4_Id_Matched;
  TBranch* b_multilepton_Lepton4_P4_Matched;

  TBranch* b_multilepton_Bjet1_Id;
  TBranch* b_multilepton_Bjet1_P4;
  TBranch* b_multilepton_Bjet1_CSV;
  TBranch* b_multilepton_Bjet1_JEC_Up;
  TBranch* b_multilepton_Bjet1_JEC_Down;
  TBranch* b_multilepton_Bjet1_JER_Up;
  TBranch* b_multilepton_Bjet1_JER_Down;
  TBranch* b_multilepton_Bjet1_DeltaR_Matched;
  TBranch* b_multilepton_Bjet1_Label_Matched;
  TBranch* b_multilepton_Bjet1_Id_Matched;
  TBranch* b_multilepton_Bjet1_P4_Matched;

  TBranch* b_multilepton_Bjet2_Id;
  TBranch* b_multilepton_Bjet2_P4;
  TBranch* b_multilepton_Bjet2_CSV;
  TBranch* b_multilepton_Bjet2_JEC_Up;
  TBranch* b_multilepton_Bjet2_JEC_Down;
  TBranch* b_multilepton_Bjet2_JER_Up;
  TBranch* b_multilepton_Bjet2_JER_Down;
  TBranch* b_multilepton_Bjet2_DeltaR_Matched;
  TBranch* b_multilepton_Bjet2_Label_Matched;
  TBranch* b_multilepton_Bjet2_Id_Matched;
  TBranch* b_multilepton_Bjet2_P4_Matched;

  TBranch* b_multilepton_JetHighestPt1_Id;
  TBranch* b_multilepton_JetHighestPt1_P4;
  TBranch* b_multilepton_JetHighestPt1_CSV;
  TBranch* b_multilepton_JetHighestPt1_JEC_Up;
  TBranch* b_multilepton_JetHighestPt1_JEC_Down;
  TBranch* b_multilepton_JetHighestPt1_JER_Up;
  TBranch* b_multilepton_JetHighestPt1_JER_Down;

  TBranch* b_multilepton_JetHighestPt2_Id;
  TBranch* b_multilepton_JetHighestPt2_P4;
  TBranch* b_multilepton_JetHighestPt2_CSV;
  TBranch* b_multilepton_JetHighestPt2_JEC_Up;
  TBranch* b_multilepton_JetHighestPt2_JEC_Down;
  TBranch* b_multilepton_JetHighestPt2_JER_Up;
  TBranch* b_multilepton_JetHighestPt2_JER_Down;

  TBranch* b_multilepton_JetClosestMw1_Id;
  TBranch* b_multilepton_JetClosestMw1_P4;
  TBranch* b_multilepton_JetClosestMw1_CSV;
  TBranch* b_multilepton_JetClosestMw1_JEC_Up;
  TBranch* b_multilepton_JetClosestMw1_JEC_Down;
  TBranch* b_multilepton_JetClosestMw1_JER_Up;
  TBranch* b_multilepton_JetClosestMw1_JER_Down;

  TBranch* b_multilepton_JetClosestMw2_Id;
  TBranch* b_multilepton_JetClosestMw2_P4;
  TBranch* b_multilepton_JetClosestMw2_CSV;
  TBranch* b_multilepton_JetClosestMw2_JEC_Up;
  TBranch* b_multilepton_JetClosestMw2_JEC_Down;
  TBranch* b_multilepton_JetClosestMw2_JER_Up;
  TBranch* b_multilepton_JetClosestMw2_JER_Down;

  TBranch* b_multilepton_JetLowestMjj1_Id;
  TBranch* b_multilepton_JetLowestMjj1_P4;
  TBranch* b_multilepton_JetLowestMjj1_CSV;
  TBranch* b_multilepton_JetLowestMjj1_JEC_Up;
  TBranch* b_multilepton_JetLowestMjj1_JEC_Down;
  TBranch* b_multilepton_JetLowestMjj1_JER_Up;
  TBranch* b_multilepton_JetLowestMjj1_JER_Down;

  TBranch* b_multilepton_JetLowestMjj2_Id;
  TBranch* b_multilepton_JetLowestMjj2_P4;
  TBranch* b_multilepton_JetLowestMjj2_CSV;
  TBranch* b_multilepton_JetLowestMjj2_JEC_Up;
  TBranch* b_multilepton_JetLowestMjj2_JEC_Down;
  TBranch* b_multilepton_JetLowestMjj2_JER_Up;
  TBranch* b_multilepton_JetLowestMjj2_JER_Down;

  TBranch* b_multilepton_JetHighestEta1_Id;
  TBranch* b_multilepton_JetHighestEta1_P4;
  TBranch* b_multilepton_JetHighestEta1_CSV;
  TBranch* b_multilepton_JetHighestEta1_JEC_Up;
  TBranch* b_multilepton_JetHighestEta1_JEC_Down;
  TBranch* b_multilepton_JetHighestEta1_JER_Up;
  TBranch* b_multilepton_JetHighestEta1_JER_Down;

  TBranch* b_multilepton_JetHighestEta2_Id;
  TBranch* b_multilepton_JetHighestEta2_P4;
  TBranch* b_multilepton_JetHighestEta2_CSV;
  TBranch* b_multilepton_JetHighestEta2_JEC_Up;
  TBranch* b_multilepton_JetHighestEta2_JEC_Down;
  TBranch* b_multilepton_JetHighestEta2_JER_Up;
  TBranch* b_multilepton_JetHighestEta2_JER_Down;

  TBranch* b_multilepton_JetHighestPt_Mjj;
  TBranch* b_multilepton_JetClosestMw_Mjj;
  TBranch* b_multilepton_JetLowestMjj_Mjj;

  TBranch* b_multilepton_JetHighestPt1_2ndPair_P4;
  TBranch* b_multilepton_JetHighestPt1_2ndPair_Id;
  TBranch* b_multilepton_JetHighestPt1_2ndPair_CSV;
  TBranch* b_multilepton_JetHighestPt1_2ndPair_JEC_Up;
  TBranch* b_multilepton_JetHighestPt1_2ndPair_JEC_Down;
  TBranch* b_multilepton_JetHighestPt1_2ndPair_JER_Up;
  TBranch* b_multilepton_JetHighestPt1_2ndPair_JER_Down;

  TBranch* b_multilepton_JetHighestPt2_2ndPair_P4;
  TBranch* b_multilepton_JetHighestPt2_2ndPair_Id;
  TBranch* b_multilepton_JetHighestPt2_2ndPair_CSV;
  TBranch* b_multilepton_JetHighestPt2_2ndPair_JEC_Up;
  TBranch* b_multilepton_JetHighestPt2_2ndPair_JEC_Down;
  TBranch* b_multilepton_JetHighestPt2_2ndPair_JER_Up;
  TBranch* b_multilepton_JetHighestPt2_2ndPair_JER_Down;

  TBranch* b_multilepton_JetClosestMw1_2ndPair_Id;
  TBranch* b_multilepton_JetClosestMw1_2ndPair_P4;
  TBranch* b_multilepton_JetClosestMw1_2ndPair_CSV;
  TBranch* b_multilepton_JetClosestMw1_2ndPair_JEC_Up;
  TBranch* b_multilepton_JetClosestMw1_2ndPair_JEC_Down;
  TBranch* b_multilepton_JetClosestMw1_2ndPair_JER_Up;
  TBranch* b_multilepton_JetClosestMw1_2ndPair_JER_Down;

  TBranch* b_multilepton_JetClosestMw2_2ndPair_Id;
  TBranch* b_multilepton_JetClosestMw2_2ndPair_P4;
  TBranch* b_multilepton_JetClosestMw2_2ndPair_CSV;
  TBranch* b_multilepton_JetClosestMw2_2ndPair_JEC_Up;
  TBranch* b_multilepton_JetClosestMw2_2ndPair_JEC_Down;
  TBranch* b_multilepton_JetClosestMw2_2ndPair_JER_Up;
  TBranch* b_multilepton_JetClosestMw2_2ndPair_JER_Down;

  TBranch* b_multilepton_JetLowestMjj1_2ndPair_Id;
  TBranch* b_multilepton_JetLowestMjj1_2ndPair_P4;
  TBranch* b_multilepton_JetLowestMjj1_2ndPair_CSV;
  TBranch* b_multilepton_JetLowestMjj1_2ndPair_JEC_Up;
  TBranch* b_multilepton_JetLowestMjj1_2ndPair_JEC_Down;
  TBranch* b_multilepton_JetLowestMjj1_2ndPair_JER_Up;
  TBranch* b_multilepton_JetLowestMjj1_2ndPair_JER_Down;

  TBranch* b_multilepton_JetLowestMjj2_2ndPair_Id;
  TBranch* b_multilepton_JetLowestMjj2_2ndPair_P4;
  TBranch* b_multilepton_JetLowestMjj2_2ndPair_CSV;
  TBranch* b_multilepton_JetLowestMjj2_2ndPair_JEC_Up;
  TBranch* b_multilepton_JetLowestMjj2_2ndPair_JEC_Down;
  TBranch* b_multilepton_JetLowestMjj2_2ndPair_JER_Up;
  TBranch* b_multilepton_JetLowestMjj2_2ndPair_JER_Down;

  TBranch* b_nJets;
  TBranch* b_JetsPt;
  TBranch* b_JetsEta;
  TBranch* b_JetsPhi;
  TBranch* b_JetsE;
  TBranch* b_JetsCSV;

  TBranch* b_multilepton_h0_P4;
  TBranch* b_multilepton_h0_Id;
  TBranch* b_multilepton_h0_Label;
  TBranch* b_multilepton_t1_P4;
  TBranch* b_multilepton_t1_Id;
  TBranch* b_multilepton_t1_Label;
  TBranch* b_multilepton_t2_P4;
  TBranch* b_multilepton_t2_Id;
  TBranch* b_multilepton_t2_Label;

  TBranch* b_multilepton_mET;
  TBranch* b_multilepton_mETcov00;
  TBranch* b_multilepton_mETcov01;
  TBranch* b_multilepton_mETcov10;
  TBranch* b_multilepton_mETcov11;
  TBranch* b_multilepton_sumET;
  TBranch* b_multilepton_Ptot;

  TH1F** hMEPhaseSpace_Error;
  TH1F** hMEPhaseSpace_ErrorTot;
  TH1F** hMEPhaseSpace_ErrorTot_Fail;
  TH1F** hMEPhaseSpace_ErrorTot_Pass;

  TH1D* hMEAllWeights[8][12];
  TH1D* hMEAllWeights_nlog[8][12];

  private:
};


#endif

