#ifndef __dstarMC_h__
#define __dstarMC_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"
#include "TH2.h"
#include "TH3.h"
#include "TRandom3.h"


class	dstarMC  : public PPhysics
{
private:
    // pi0
    GH1*	time;
    GH1*    theta;
    TH1D*    theta_MC;
    GH1*    theta_hel0;
    GH1*    theta_hel1;
    GH1*    theta_charged;
    GH1*    theta_neutral;
    TH1D*    theta_charged_MC;
    TH1D*    theta_neutral_MC;

    GH1*    TaggerChannel;
    GH1*    TaggerChannel_hel0;
    GH1*    TaggerChannel_hel1;
    GH1*    coplanarity;
    TH1D*    coplanarity_MC;
    GH1*    coplanarity_cut;
//    GH1* coplanarity_neutral;
//    GH1* coplanarity_charged;

    GHistBGSub2*    PSA_charged;
    GHistBGSub2*    PSA_neutral;

    GHistBGSub2*    dE_E_CB;
    GHistBGSub2*    dE_E_TAPS;

 //   TH1*	TaggerAccScal;
    TH1*	TaggerAccScal_fede;
    TH1*	TaggerScalers_uncorr;
    TH1*	TaggerScalers_corr;
    TH1*	LivetimeHist;
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

    bool coplanarity_condition;

    double px_PSA_cut[7];
    double py_PSA_cut[7];

protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void	ProcessScalerRead();
    virtual Bool_t    Write();

public:
    dstarMC();
    virtual ~dstarMC();
    virtual Bool_t  Init();    //   Double_t Target_Pol(Double_t target_pol_degree);
};
#endif
