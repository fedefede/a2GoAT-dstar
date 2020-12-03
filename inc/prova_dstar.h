#ifndef __prova_dstar_h__
#define __prova_dstar_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"
#include "TH2.h"
#include "TH3.h"
#include "TRandom3.h"


class	prova_dstar  : public PPhysics
{
private:
    // pi0
    GH1*	time;
    GH1*    theta;
    GH1*    coplanarity;
    GH1*    coplanarity_hel0;
    GH1*    coplanarity_hel1;
    GH1*    theta_hel0;
    GH1*    theta_hel1;
    GH1*    theta_charged;
    GH1*    theta_neutral;

    GH1*    MM;
    GH1*    MM_hel0;
    GH1*    MM_hel1;
    GH1*    MM_copl;
    GH1*    MM_copl_hel0;
    GH1*    MM_copl_hel1;

    GH1*    MM_1track;
    GH1*    MM_1track_hel0;
    GH1*    MM_1track_hel1;
    GH1*    MM_1track_copl;
    GH1*    MM_1track_copl_hel0;
    GH1*    MM_1track_copl_hel1;

    GH1*    TaggerChannel;
    GH1*    TaggerChannel_hel0;
    GH1*    TaggerChannel_hel1;

    GH1*    theta_neutron_calculated;
    GH1*    diff_theta_neutron_calculated_measured;
    GHistBGSub2*    neutron_theta_calc_measured;
    GH1*    theta_neutron_calculated_hel0;
    GH1*    diff_theta_neutron_calculated_measured_hel0;
    GHistBGSub2*    neutron_theta_calc_measured_hel0;
    GH1*    theta_neutron_calculated_hel1;
    GH1*    diff_theta_neutron_calculated_measured_hel1;
    GHistBGSub2*    neutron_theta_calc_measured_hel1;

    GH1*    theta_neutron_calculated_copl;
    GH1*    diff_theta_neutron_calculated_measured_copl;
    GHistBGSub2*    neutron_theta_calc_measured_copl;
    GH1*    theta_neutron_calculated_copl_hel0;
    GH1*    diff_theta_neutron_calculated_measured_copl_hel0;
    GHistBGSub2*    neutron_theta_calc_measured_copl_hel0;
    GH1*    theta_neutron_calculated_copl_hel1;
    GH1*    diff_theta_neutron_calculated_measured_copl_hel1;
    GHistBGSub2*    neutron_theta_calc_measured_copl_hel1;

    GH1*    theta_neutron_calcd_copl_protonCB;
    GH1*    diff_theta_neutron_calcd_measured_copl_protonCB;
    GHistBGSub2*    neutron_theta_calc_measured_copl_protonCB;
    GH1*    theta_neutron_calcd_copl_protonCB_hel0;
    GH1*    diff_theta_neutron_calcd_measured_copl_protonCB_hel0;
    GHistBGSub2*    neutron_theta_calc_measured_copl_protonCB_hel0;
    GH1*    theta_neutron_calcd_copl_protonCB_hel1;
    GH1*    diff_theta_neutron_calcd_measured_copl_protonCB_hel1;
    GHistBGSub2*    neutron_theta_calc_measured_copl_protonCB_hel1;

    GH1*    theta_neutron_calcd_copl_protonCB_neutronTAPS;
    GH1*    diff_theta_neutron_calcd_measured_copl_protonCB_neutronTAPS;
    GHistBGSub2*    neutron_theta_calc_measured_copl_protonCB_neutronTAPS;


    GH1*    theta_neutron_calculated_copl_with_cuts;
    GH1*    diff_theta_neutron_calculated_measured_copl_with_cuts;
    GHistBGSub2*    neutron_theta_calc_measured_copl_with_cuts;

    GH1*    diff_theta_neutron_calculated_measured_physics;
    GH1*    diff_theta_neutron_calculated_measured_physics_copl;

    GH1*    coplanarity_cut;
    GH1*    theta_copl;
    GH1*    theta_hel0_copl;
    GH1*    theta_hel1_copl;
    GH1*    theta_charged_copl;
    GH1*    theta_neutral_copl;

    GH1*    TaggerChannel_copl;
    GH1*    TaggerChannel_hel0_copl;
    GH1*    TaggerChannel_hel1_copl;

    GHistBGSub2*    PSA_charged_copl;
    GHistBGSub2*    PSA_charged_copl_PSA_cut;
    GHistBGSub2*    PSA_charged_copl_VETO_cut;
    GHistBGSub2*    PSA_charged_copl_PID_cut_PSA_cut_VETO_cut;

    GHistBGSub2*    PSA_neutral_copl;
    GHistBGSub2*    PSA_neutral_copl_PID_cut;
    GHistBGSub2*    PSA_neutral_copl_PSA_cut;
    GHistBGSub2*    PSA_neutral_copl_PID_cut_PSA_cut;
    GHistBGSub2*    PSA_neutral_copl_PID_cut_PSA_cut_VETO_cut;
    GHistBGSub2*    TOF_charged_copl;

    GHistBGSub2*    TOF_charged_copl_PSA_cut;
    GHistBGSub2*    TOF_charged_copl_VETO_cut;
    GHistBGSub2*    TOF_charged_copl_PID_cut_PSA_cut_VETO_cut;
    GHistBGSub2*    TOF_neutral_copl;
    GHistBGSub2*    TOF_neutral_copl_PID_cut;
    GHistBGSub2*    TOF_neutral_copl_PSA_cut;
    GHistBGSub2*    TOF_neutral_copl_PID_cut_PSA_cut;
    GHistBGSub2*    TOF_neutral_copl_PID_cut_PSA_cut_VETO_cut;
    GHistBGSub2*    dE_E_CB_copl;
    GHistBGSub2*    dE_E_CB_copl_hel0;
    GHistBGSub2*    dE_E_CB_copl_hel1;
    GHistBGSub2*    dE_E_CB_copl2;
    GHistBGSub2*    dE_E_CB_copl_PSA_cut;
    GHistBGSub2*    dE_E_CB_copl_PSA_cut_PID_cut;
    GHistBGSub2*    dE_E_CB_copl_PID_cut_PSA_cut_VETO_cut;

    GHistBGSub2*    dE_E_TAPS_copl;
    GHistBGSub2*    dE_E_TAPS_copl_VETO_cut;
    GHistBGSub2*    dE_E_TAPS_copl_PSA_cut;
    GHistBGSub2*    dE_E_TAPS_PID_cut_PSA_cut_VETO_cut;
    GHistBGSub2* cluster_size_CB;
    GHistBGSub2* cluster_size_CB_copl;
    GHistBGSub2* cluster_size_CB_charged_copl;
    GHistBGSub2* cluster_size_CB_neutral_copl;
    GHistBGSub2* cluster_size_CB_charged_copl_dE;
    GHistBGSub2* cluster_size_CB_neutral_copl_dE;
    //   TH1*	TaggerAccScal;
    TH1*	TaggerAccScal_fede;
    TH1*	TaggerScalers_uncorr;
    TH1*	TaggerScalers_corr;
    TH1*	LivetimeHist;
    TH1*	detector_CB_TAPS;
    TH1*	detector_CB_TAPS_copl;
    //  TH1*	Doppia_traccia_residua;
    //  TH1*	Doppia_traccia_residua_copl;
    TH1*	AllScl_fede;

    Int_t num_run;
    Double_t beam_asymmetry[670];
    Double_t corr_para;
    Double_t corr_anti;
    Double_t corr_ratio;
    Double_t live_time_correction_1period;
    Int_t eventzero;
    Int_t conteggio;
    Int_t conteggio_N;
    Int_t conteggio_C;

    Double_t discriminante_neutron_check;
    Double_t discriminante_proton_check;
    double value_theta_neutron_calculated;
    double diff_theta_check;

    bool coplanarity_condition;
    bool inside_dE_E_CB_cut;
    bool inside_PSA_cut;
    bool above_dE_E_TAPS_cut;
    bool diff_theta_netron_condition;
    double px_E_CB;
    double py_E_PID;
    double px_E_TAPS;
    double py_E_VETO;


    double r_psa_calc;
    double phi_psa_calc;
    double cluster_energy_calc;
    double short_energy_calc;


    double px_dE_E_CB_cut[7];
    double py_dE_E_CB_cut[7];

    double px_PSA_cut[7];
    double py_PSA_cut[7];

    double px_dE_E_TAPS_cut[7];
    double py_dE_E_TAPS_cut[7];
protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void	ProcessScalerRead();
    virtual Bool_t    Write();

public:
    prova_dstar();
    virtual ~prova_dstar();
    virtual Bool_t  Init();    //   Double_t Target_Pol(Double_t target_pol_degree);

    //    void    Fill_theta_proton(const GTreeParticle& tree,  Int_t track_index, Int_t tagger_index, GHistBGSub2* gHist, GH1* gHist1, GH1* gHist2, GHistBGSub2* gHist3, GHistBGSub2* gHist4,
    //                              GHistBGSub2* gHist5,  Bool_t peso_beam_pol);

    void    Fill_theta_neutron_calc_measured(Int_t tagger_index, GH1* gHist, GH1* gHist2, GHistBGSub2* gHist3, Bool_t TaggerBinning);
};
#endif
