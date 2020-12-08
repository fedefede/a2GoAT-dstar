#include "prova_dstar.h"
#include <stdio.h>
#include <string.h>

prova_dstar::prova_dstar()
{
    TaggerAccScal_fede      = new TH1D("TaggerAccScal_fede","TaggerAccScal_fede",352,0,352);
    TaggerScalers_uncorr    = new TH1D("TaggerScalers_uncorr","TaggerScalers_uncorr",352,0,352);
    LivetimeHist            = new TH1D("LivetimeHisto", "LivetimeHisto",200,0,100);
    TaggerScalers_corr      = new TH1D("TaggerScalers_corr","TaggerScalers_corr",352,0,352);
    detector_CB_TAPS      = new TH1D("detector_CB_TAPS","detector_CB_TAPS",3,0,3);
    detector_CB_TAPS_copl      = new TH1D("detector_CB_TAPS_copl","detector_CB_TAPS_copl",3,0,3);
    //    detector_CB_TAPS_copl      = new TH2D("detector_CB_TAPS_copl","detector_CB_TAPS_copl",2,0,2, 2, 0,2);
    //   Doppia_traccia_residua      = new TH1D("Doppia_traccia_residua","Doppia_traccia_residua",10,0,10);
    //   Doppia_traccia_residua_copl      = new TH1D("Doppia_traccia_residua_copl","Doppia_traccia_residua_copl",10,0,10);
    AllScl_fede      = new TH1D("AllScl_fede","AllScl_fede",8705,0,8705);

    //pi0
    time 	= new GH1("time", 	"time", 	1400, -700, 700);
    TaggerChannel    = new GH1 ("TaggerChannel", "TaggerChannel",  352, 0,   352);
    TaggerChannel_hel0    = new GH1 ("TaggerChannel_hel0", "TaggerChannel_hel0",  352, 0,   352);
    TaggerChannel_hel1    = new GH1 ("TaggerChannel_hel1", "TaggerChannel_hel1",  352, 0,   352);
    coplanarity = new GH1 ("coplanarity", "coplanarity",    360, 0, 360);
    coplanarity_hel0 = new GH1 ("coplanarity_hel0", "coplanarity_hel0",    360, 0, 360);
    coplanarity_hel1 = new GH1 ("coplanarity_hel1", "coplanarity_hel1",    360, 0, 360);

    //    coplanarity_charged = new GH1 ("coplanarity_charged", "coplanarity_charged",    360, 0, 360);
    //    coplanarity_neutral = new GH1 ("coplanarity_neutral", "coplanarity_neutral",    360, 0, 360);

    theta   = new GH1 ("theta", "theta",    180,    0,  180);
    theta_hel0   = new GH1 ("theta_hel0", "theta_hel0",    180,    0,  180);
    theta_hel1   = new GH1 ("theta_hel1", "theta_hel1",    180,    0,  180);
    theta_charged   = new GH1 ("theta_charged", "theta_charged",    180,    0,  180);
    theta_neutral   = new GH1 ("theta_neutral", "theta_neutral",    180,    0,  180);

    MM0   = new GH1 ("MM0", "MM0",    200,    -2000,  2000);
    MM1   = new GH1 ("MM1", "MM1",    200,    -2000,  2000);
    MM_neutral   = new GH1 ("MM_charged", "MM_charged",    200,    -2000,  2000);
    MM_charged   = new GH1 ("MM1", "MM1",    200,    -2000,  2000);
    MM0_hel0   = new GH1 ("MM0_hel0", "MM0_hel0",    200,    -2000,  2000);
    MM1_hel0   = new GH1 ("MM1_hel0", "MM1_hel0",    200,    -2000,  2000);
    MM0_hel1   = new GH1 ("MM0_hel1", "MM0_hel1",    200,    -2000,  2000);
    MM1_hel1   = new GH1 ("MM1_hel1", "MM1_hel1",    200,    -2000,  2000);
    MM0_copl   = new GH1 ("MM0_copl", "MM0_copl",    200,    -2000,  2000);
    MM1_copl   = new GH1 ("MM1_copl", "MM1_copl",    200,    -2000,  2000);
    MM0_copl_hel0   = new GH1 ("MM0_copl_hel0", "MM0_copl_hel0",    200,    -2000,  2000);
    MM1_copl_hel0   = new GH1 ("MM1_copl_hel0", "MM1_copl_hel0",    200,    -2000,  2000);
    MM0_copl_hel1   = new GH1 ("MM0_copl_hel1", "MM0_copl_hel1",    200,    -2000,  2000);
    MM1_copl_hel1   = new GH1 ("MM1_copl_hel1", "MM1_copl_hel1",    200,    -2000,  2000);

    TaggerChannel_copl    = new GH1 ("TaggerChannel_copl", "TaggerChannel_copl",  352, 0,   352);
    TaggerChannel_hel0_copl    = new GH1 ("TaggerChannel_hel0_copl", "TaggerChannel_hel0_copl",  352, 0,   352);
    TaggerChannel_hel1_copl    = new GH1 ("TaggerChannel_hel1_copl", "TaggerChannel_hel1_copl",  352, 0,   352);
    coplanarity_cut = new GH1 ("coplanarity_cut", "coplanarity_cut",    360, 0, 360);

    theta_neutron_calculated = new GH1 ("theta_neutron_calculated", "theta_neutron_calculated",     360, 0, 180);
    diff_theta_neutron_calculated_measured = new GH1 ("diff_theta_neutron_calculated_measured", "diff_theta_neutron_calculated_measured",    360, -180, 180);
    neutron_theta_calc_measured = new GHistBGSub2 ("neutron_theta_calc_measured", "neutron_theta_calc_measured",    180, 0, 180, 180, 0, 180);
    theta_neutron_calculated_hel0 = new GH1 ("theta_neutron_calculated_hel0", "theta_neutron_calculated_hel0",     360, 0, 180);
    diff_theta_neutron_calculated_measured_hel0 = new GH1 ("diff_theta_neutron_calculated_measured_hel0", "diff_theta_neutron_calculated_measured_hel0",    360, -180, 180);
    neutron_theta_calc_measured_hel0 = new GHistBGSub2 ("neutron_theta_calc_measured_hel0", "neutron_theta_calc_measured_hel0",    180, 0, 180, 180, 0, 180);
    theta_neutron_calculated_hel1 = new GH1 ("theta_neutron_calculated_hel1", "theta_neutron_calculated_hel1",     360, 0, 180);
    diff_theta_neutron_calculated_measured_hel1 = new GH1 ("diff_theta_neutron_calculated_measured_hel1", "diff_theta_neutron_calculated_measured_hel1",    360, -180, 180);
    neutron_theta_calc_measured_hel1 = new GHistBGSub2 ("neutron_theta_calc_measured_hel1", "neutron_theta_calc_measured_hel1",    180, 0, 180, 180, 0, 180);

    theta_neutron_calculated_copl = new GH1 ("theta_neutron_calculated_copl", "theta_neutron_calculated_copl",     180, 0, 180);
    diff_theta_neutron_calculated_measured_copl = new GH1 ("diff_theta_neutron_calculated_measured_copl", "diff_theta_neutron_calculated_measured_copl",     360, -180, 180);
    neutron_theta_calc_measured_copl = new GHistBGSub2 ("neutron_theta_calc_measured_copl", "neutron_theta_calc_measured_copl",    180, 0, 180, 180, 0, 180);
    theta_neutron_calculated_copl_hel0 = new GH1 ("theta_neutron_calculated_copl_hel0", "theta_neutron_calculated_copl_hel0",     180, 0, 180);
    diff_theta_neutron_calculated_measured_copl_hel0 = new GH1 ("diff_theta_neutron_calculated_measured_copl_hel0", "diff_theta_neutron_calculated_measured_copl_hel0",     360, -180, 180);
    neutron_theta_calc_measured_copl_hel0 = new GHistBGSub2 ("neutron_theta_calc_measured_copl_hel0", "neutron_theta_calc_measured_copl_hel0",    180, 0, 180, 180, 0, 180);
    theta_neutron_calculated_copl_hel1 = new GH1 ("theta_neutron_calculated_copl_hel1", "theta_neutron_calculated_copl_hel1",     180, 0, 180);
    diff_theta_neutron_calculated_measured_copl_hel1 = new GH1 ("diff_theta_neutron_calculated_measured_copl_hel1", "diff_theta_neutron_calculated_measured_copl_hel1",     360, -180, 180);
    neutron_theta_calc_measured_copl_hel1 = new GHistBGSub2 ("neutron_theta_calc_measured_copl_hel1", "neutron_theta_calc_measured_copl_hel1",    180, 0, 180, 180, 0, 180);

    theta_neutron_calcd_copl_protonCB = new GH1 ("theta_neutron_calcd_copl_protonCB", "theta_neutron_calcd_copl_protonCB",     180, 0, 180);
    diff_theta_neutron_calcd_measured_copl_protonCB = new GH1 ("diff_theta_neutron_calcd_measured_copl_protonCB", "diff_theta_neutron_calcd_measured_copl_protonCB",     360, -180, 180);
    neutron_theta_calc_measured_copl_protonCB = new GHistBGSub2 ("neutron_theta_calc_measured_copl_protonCB", "neutron_theta_calc_measured_copl_protonCB",    180, 0, 180, 180, 0, 180);
    theta_neutron_calcd_copl_protonCB_hel0 = new GH1 ("theta_neutron_calcd_copl_protonCB_hel0", "theta_neutron_calcd_copl_protonCB_hel0",     180, 0, 180);
    diff_theta_neutron_calcd_measured_copl_protonCB_hel0 = new GH1 ("diff_theta_neutron_calcd_measured_copl_protonCB_hel0", "diff_theta_neutron_calcd_measured_copl_protonCB_hel0",     360, -180, 180);
    neutron_theta_calc_measured_copl_protonCB_hel0 = new GHistBGSub2 ("neutron_theta_calc_measured_copl_protonCB_hel0", "neutron_theta_calc_measured_copl_protonCB_hel0",    180, 0, 180, 180, 0, 180);
    theta_neutron_calcd_copl_protonCB_hel1 = new GH1 ("theta_neutron_calcd_copl_protonCB_hel1", "theta_neutron_calcd_copl_protonCB_hel1",     180, 0, 180);
    diff_theta_neutron_calcd_measured_copl_protonCB_hel1 = new GH1 ("diff_theta_neutron_calcd_measured_copl_protonCB_hel1", "diff_theta_neutron_calcd_measured_copl_protonCB_hel1",     360, -180, 180);
    neutron_theta_calc_measured_copl_protonCB_hel1 = new GHistBGSub2 ("neutron_theta_calc_measured_copl_protonCB_hel1", "neutron_theta_calc_measured_copl_protonCB_hel1",    180, 0, 180, 180, 0, 180);

    theta_neutron_calcd_copl_protonCB_neutronTAPS = new GH1 ("theta_neutron_calcd_copl_protonCB_neutronTAPS", "theta_neutron_calcd_copl_protonCB_neutronTAPS",     180, 0, 180);
    diff_theta_neutron_calcd_measured_copl_protonCB_neutronTAPS = new GH1 ("diff_theta_neutron_calcd_measured_copl_protonCB_neutronTAPS", "diff_theta_neutron_calcd_measured_copl_protonCB_neutronTAPS",     360, -180, 180);
    neutron_theta_calc_measured_copl_protonCB_neutronTAPS = new GHistBGSub2 ("neutron_theta_calc_measured_copl_protonCB_neutronTAPS", "neutron_theta_calc_measured_copl_protonCB_neutronTAPS",    180, 0, 180, 180, 0, 180);

    theta_neutron_calculated_copl_with_cuts = new GH1 ("theta_neutron_calculated_copl_with_cuts", "theta_neutron_calculated_copl_with_cuts",     180, 0, 180);
    diff_theta_neutron_calculated_measured_copl_with_cuts = new GH1 ("diff_theta_neutron_calculated_measured_copl_with_cuts", "diff_theta_neutron_calculated_measured_copl_with_cuts",     360, -180, 180);
    neutron_theta_calc_measured_copl_with_cuts = new GHistBGSub2 ("neutron_theta_calc_measured_copl_with_cuts", "neutron_theta_calc_measured_copl_with_cuts",    180, 0, 180, 180, 0, 180);

    //    diff_theta_neutron_calculated_measured_physics = new GH1 ("diff_theta_neutron_calculated_measured_physics", "diff_theta_neutron_calculated_measured_physics",    360, -180, 180);
    //    diff_theta_neutron_calculated_measured_physics_copl = new GH1 ("diff_theta_neutron_calculated_measured_physics_copl", "diff_theta_neutron_calculated_measured_physics_copl",    360, -180, 180);

    theta_copl   = new GH1 ("theta_copl", "theta_copl",    180,    0,  180);
    theta_hel0_copl   = new GH1 ("theta_hel0_copl", "theta_hel0_copl",    180,    0,  180);
    theta_hel1_copl   = new GH1 ("theta_hel1_copl", "theta_hel1_copl",    180,    0,  180);
    theta_charged_copl   = new GH1 ("theta_charged_copl", "theta_charged_copl",    180,    0,  180);
    theta_neutral_copl   = new GH1 ("theta_neutral_copl", "theta_neutral_copl",    180,    0,  180);

    PSA_neutral_copl = new GHistBGSub2("PSA_neutral_copl", "PSA_neutral_copl", 45,   5,   50,  250,   0,    1000);
    PSA_neutral_copl_PSA_cut = new GHistBGSub2("PSA_neutral_copl_PSA_cut", "PSA_neutral_copl_PSA_cut", 45,   5,   50,  250,   0,    1000);
    PSA_neutral_copl_PID_cut = new GHistBGSub2("PSA_neutral_copl_PID_cut", "PSA_neutral_copl_PID_cut", 45,   5,   50,  250,   0,    1000);
    PSA_neutral_copl_PID_cut_PSA_cut = new GHistBGSub2("PSA_neutral_copl_PID_cut_PSA_cut", "PSA_neutral_copl_PID_cut_PSA_cut", 45,   5,   50,  250,   0,    1000);
    PSA_neutral_copl_PID_cut_PSA_cut_VETO_cut = new GHistBGSub2("PSA_neutral_copl_PID_cut_PSA_cut_VETO_cut", "PSA_neutral_copl_PID_cut_PSA_cut_VETO_cut", 45,   5,   50,  250,   0,    1000);

    PSA_charged_copl = new GHistBGSub2("PSA_charged_copl", "PSA_charged_copl", 45,   5,   50,  250,   0,    1000);
    PSA_charged_copl_PSA_cut = new GHistBGSub2("PSA_charged_copl_PSA_cut", "PSA_charged_copl_PSA_cut", 45,   5,   50,  250,   0,    1000);
    PSA_charged_copl_VETO_cut = new GHistBGSub2("PSA_charged_copl_VETO_cut", "PSA_charged_copl_VETO_cut", 45,   5,   50,  250,   0,    1000);
    PSA_charged_copl_PID_cut_PSA_cut_VETO_cut = new GHistBGSub2("PSA_charged_copl_PID_cut_PSA_cut_VETO_cut", "PSA_charged_copl_PID_cut_PSA_cut_VETO_cut", 45,   5,   50,  250,   0,    1000);

    TOF_neutral_copl = new GHistBGSub2("TOF_neutral_copl", "TOF_neutral_copl", 200, 0, 600, 80, -40, 40);
    TOF_neutral_copl_PID_cut = new GHistBGSub2("TOF_neutral_copl_PID_cut", "TOF_neutral_copl_PID_cut", 200, 0, 600, 80, -40, 40);
    TOF_neutral_copl_PSA_cut = new GHistBGSub2("TOF_neutral_copl_PSA_cut", "TOF_neutral_copl_PSA_cut", 200, 0, 600, 80, -40, 40);
    TOF_neutral_copl_PID_cut_PSA_cut = new GHistBGSub2("TOF_neutral_copl_PID_cut_PSA_cut", "TOF_neutral_copl_PID_cut_PSA_cut", 200, 0, 600, 80, -40, 40);
    TOF_neutral_copl_PID_cut_PSA_cut_VETO_cut = new GHistBGSub2("TOF_neutral_copl_PID_cut_PSA_cut_VETO_cut", "TOF_neutral_copl_PID_cut_PSA_cut_VETO_cut", 200, 0, 600, 80, -40, 40);
    TOF_charged_copl = new GHistBGSub2("TOF_charged_copl", "TOF_charged_copl", 200, 0, 600, 80, -40, 40);
    TOF_charged_copl_PSA_cut = new GHistBGSub2("TOF_charged_copl_PSA_cut", "TOF_charged_copl_PSA_cut", 200, 0, 600, 80, -40, 40);
    TOF_charged_copl_VETO_cut = new GHistBGSub2("TOF_charged_copl_VETO_cut", "TOF_charged_copl_VETO_cut", 200, 0, 600, 80, -40, 40);
    TOF_charged_copl_PID_cut_PSA_cut_VETO_cut = new GHistBGSub2("TOF_charged_copl_PID_cut_PSA_cut_VETO_cut", "TOF_charged_copl_PID_cut_PSA_cut_VETO_cut", 200, 0, 600, 80, -40, 40);

    dE_E_CB_copl = new  GHistBGSub2("dE_E_CB_copl", "dE_E_CB_copl", 200,  0,  500, 50, 0, 10);
    dE_E_CB_copl_hel0 = new  GHistBGSub2("dE_E_CB_copl_hel0", "dE_E_CB_copl_hel0", 200,  0,  500, 50, 0, 10);
    dE_E_CB_copl_hel1 = new  GHistBGSub2("dE_E_CB_copl_hel1", "dE_E_CB_copl_hel1", 200,  0,  500, 50, 0, 10);
    dE_E_CB_copl2 = new  GHistBGSub2("dE_E_CB_copl2", "dE_E_CB_copl2", 200,  0,  500, 50, 0, 10);
    dE_E_CB_copl_PSA_cut = new  GHistBGSub2("dE_E_CB_copl_PSA_cut", "dE_E_CB_copl_PSA_cut", 200,  0,  500, 50, 0, 10);
    dE_E_CB_copl_PSA_cut_PID_cut = new  GHistBGSub2("dE_E_CB_copl_PSA_cut_PID_cut", "dE_E_CB_copl_PSA_cut_PID_cut", 200,  0,  500, 50, 0, 10);
    dE_E_CB_copl_PID_cut_PSA_cut_VETO_cut = new  GHistBGSub2("dE_E_CB_copl_PID_cut_PSA_cut_VETO_cut", "dE_E_CB_copl_PID_cut_PSA_cut_VETO_cut", 200,  0,  500, 50, 0, 10);
    dE_E_TAPS_copl = new  GHistBGSub2("dE_E_TAPS_copl", "dE_E_TAPS_copl", 200,  0,  400, 50, 0, 10);
    dE_E_TAPS_copl_VETO_cut = new  GHistBGSub2("dE_E_TAPS_copl_VETO_cut", "dE_E_TAPS_copl_VETO_cut", 200,  0,  400, 50, 0, 10);
    dE_E_TAPS_copl_PSA_cut = new  GHistBGSub2("dE_E_TAPS_copl_PSA_cut", "dE_E_TAPS_copl_PSA_cut", 200,  0,  400, 50, 0, 10);
    dE_E_TAPS_PID_cut_PSA_cut_VETO_cut = new  GHistBGSub2("dE_E_TAPS_PID_cut_PSA_cut_VETO_cut", "dE_E_TAPS_PID_cut_PSA_cut_VETO_cut", 200,  0,  400, 50, 0, 10);

    cluster_size_CB = new GHistBGSub2("cluster_size_CB", "cluster_size_CB", 100, 0, 400, 20, 0, 20);
    cluster_size_CB_neutral_copl = new GHistBGSub2("cluster_size_CB_neutral_copl", "cluster_size_CB_neutral_copl", 100, 0, 400, 20, 0, 20);
    cluster_size_CB_charged_copl = new GHistBGSub2("cluster_size_CB_charged_copl", "cluster_size_CB_charged_copl", 100, 0, 400, 20, 0, 20);
    cluster_size_CB_neutral_copl_dE = new GHistBGSub2("cluster_size_CB_neutral_copl_dE", "cluster_size_CB_neutral_copl_dE", 100, 0, 400, 20, 0, 20);
    cluster_size_CB_charged_copl_dE = new GHistBGSub2("cluster_size_CB_charged_copl_dE", "cluster_size_CB_charged_copl_dE", 100, 0, 400, 20, 0, 20);

//    px_dE_E_CB_cut[0] = 50; px_dE_E_CB_cut[1] = 150; px_dE_E_CB_cut[2] = 150; px_dE_E_CB_cut[3] = 175   ; px_dE_E_CB_cut[4] = 450; px_dE_E_CB_cut[5] = 450; px_dE_E_CB_cut[6] = 50;
//    py_dE_E_CB_cut[0] = 3; py_dE_E_CB_cut[1] =  1.7; py_dE_E_CB_cut[2] = 1; py_dE_E_CB_cut[3] = 0.65; py_dE_E_CB_cut[4] = 0.5; py_dE_E_CB_cut[5] = 1; py_dE_E_CB_cut[6] = 6;
    px_dE_E_CB_cut[0] = 50; px_dE_E_CB_cut[1] = 150; px_dE_E_CB_cut[2] = 220; px_dE_E_CB_cut[3] = 250   ; px_dE_E_CB_cut[4] = 450; px_dE_E_CB_cut[5] = 450; px_dE_E_CB_cut[6] = 50;
    py_dE_E_CB_cut[0] = 3; py_dE_E_CB_cut[1] =  1.7; py_dE_E_CB_cut[2] = 1.2; py_dE_E_CB_cut[3] = 0.8; py_dE_E_CB_cut[4] = 0.5; py_dE_E_CB_cut[5] = 1; py_dE_E_CB_cut[6] = 6;

    px_PSA_cut[0] = 0; px_PSA_cut[1] = 37; px_PSA_cut[2] = 41; px_PSA_cut[3] = 42; px_PSA_cut[4] = 43; px_PSA_cut[5] = 43; px_PSA_cut[6] = 0;
    py_PSA_cut[0] = 0; py_PSA_cut[1] =  0; py_PSA_cut[2] = 40; py_PSA_cut[3] = 100; py_PSA_cut[4] = 200; py_PSA_cut[5] = 1000; py_PSA_cut[6] = 1000;

}
prova_dstar::~prova_dstar()
{
}

Bool_t	prova_dstar::Init()
{
    cout << "Initialising physics analysis..." << endl;
    cout << "--------------------------------------------------" << endl << endl;

    if(!InitBackgroundCuts()) return kFALSE;

    //if(!PPhysics::Init()) return kFALSE;
    if(!InitDecodeDoubles()) return kFALSE;
    if(!InitBackgroundCuts()) return kFALSE;
    if(!InitTargetMass()) return kFALSE;
    if(!InitTaggerChannelCuts()) return kFALSE;
    if(!InitTaggerScalers()) return kFALSE;
    if(!InitDisplayScalers()) return kFALSE;
    //if(!PPhysics::Init()) return kFALSE;
    cout << "--------------------------------------------------" << endl;

    return kTRUE;
}

Bool_t	prova_dstar::Start()
{
    //TaggerAccScal->Reset();
    TaggerAccScal_fede->Reset();
    LivetimeHist->Reset();
    TaggerScalers_corr->Reset();
    TaggerScalers_uncorr->Reset();
    AllScl_fede->Reset();
    if(!IsGoATFile())
    {
        cout << "ERROR: Input File is not a GoAT file." << endl;
        return kFALSE;
    }
    SetAsPhysicsFile();
    TraverseValidEvents();
    eventzero = 0;
    conteggio = 0;
    conteggio_N = 0;
    conteggio_C = 0;
    //  cout << "cvssdere" << endl;
    return kTRUE;
    // //  conteggio_check_1 = 0;
    //  conteggio_check_2 = 0;
    //   conteggio_check_3 = 0;
}

void	prova_dstar::ProcessEvent()
{
    Int_t hel = GetTrigger()->GetHelicity();
    //  const Int_t *tp = GetTrigger()->GetTriggerPattern();
    Int_t nerror = 0;

    nerror = GetTrigger()->GetNErrors();

    if(nerror==0)
    {
        /// fill con indice i
        conteggio ++;
        //  cout << "evento numero: " << conteggio << endl;
        inside_dE_E_CB_cut = false;
        inside_PSA_cut = false;
        above_dE_E_TAPS_cut = false;
        diff_theta_netron_condition = false;

        if(GetDecodeDoubles()) GetTagger()->DecodeDoubles();

        if(fabs((GetTracks()->GetPhi(0))-(GetTracks()->GetPhi(1)))>140 && fabs((GetTracks()->GetPhi(0))-(GetTracks()->GetPhi(1)))<220) coplanarity_condition = true;
        else coplanarity_condition = false;

        if(GetTracks()->IsNeutral(0) == GetTracks()->IsCharged(1)) // strictly necessary, because the same condition in the 1st step of goat does NOT work!!!!!!
        {
            Filldetector(detector_CB_TAPS);

            if( diff_theta_check <30 && diff_theta_check > -30)
            {
                diff_theta_netron_condition = true;
            }
            for (Int_t i = 0; i < GetTracks()->GetNTracks(); i++)
            {
                if(GetTracks()->HasCB(i))
                {
                    if(GetTracks()->IsCharged(i))
                    {
                        px_E_CB = GetTracks()->GetClusterEnergy(i);
                        py_E_PID = GetTracks()->GetVetoEnergy(i);
                        if(TMath::IsInside(px_E_CB, py_E_PID, 7, px_dE_E_CB_cut, py_dE_E_CB_cut)==kTRUE)
                        {
                            inside_dE_E_CB_cut = true;
                        }
                    }
                }
                else if(GetTracks()->HasTAPS(i))
                {
                    cluster_energy_calc = GetTracks()->GetClusterEnergy(i);
                    short_energy_calc = GetTracks()->GetShortEnergy(i);
                    phi_psa_calc = (TMath::ATan(short_energy_calc/cluster_energy_calc)*TMath::RadToDeg());
                    r_psa_calc = TMath::Sqrt(TMath::Power(short_energy_calc,2)+TMath::Power(cluster_energy_calc,2));
                    if(TMath::IsInside(phi_psa_calc, r_psa_calc, 7, px_PSA_cut, py_PSA_cut)==kTRUE)
                    {
                        inside_PSA_cut = true;
                    }
                    if(GetTracks()->IsCharged(i))
                    {
                        if((GetTracks()->GetVetoEnergy(i)>((-4./150.*GetTracks()->GetClusterEnergy(i))+4.5)) && (GetTracks()->GetVetoEnergy(i)>0))
                        {
                            above_dE_E_TAPS_cut = true;
                        }
                    }
                }
            }
            int block = 0;
            for (Int_t i = 0; i < GetTracks()->GetNTracks(); i++)
            {
                for (Int_t j = 0; j < GetTagger()->GetNTagged(); j++)
                {
                    if(i==0)
                    {
                        Fillcoplanarity(j, coplanarity, kTRUE);
                        FillMissingMassSingleTrack(0, j, MM0, kTRUE);
                        FillMissingMassSingleTrack(1, j, MM1, kTRUE);
                        FillMissingMasscharged_neutral(0, 1, j, MM_neutral, MM_charged, kTRUE);
                        Fill_theta_neutron_calc_measured(j, theta_neutron_calculated, diff_theta_neutron_calculated_measured, neutron_theta_calc_measured, kTRUE);
                    }
                    FillTime_track(i,j,time);
                    Filltheta_track(i, j, theta, kTRUE);
                    FillTaggerChannel_track(i, j, TaggerChannel);
                    Fillcluster_size_track(i, j, cluster_size_CB);
                    if (hel == 0)
                    {
                        if(i==0)
                        {
                            Fillcoplanarity(j, coplanarity_hel0, kTRUE);
                            Fill_theta_neutron_calc_measured(j, theta_neutron_calculated_hel0, diff_theta_neutron_calculated_measured_hel0, neutron_theta_calc_measured_hel0, kTRUE);
                        }
                        Filltheta_track(i, j, theta_hel0, kTRUE);
                        FillTaggerChannel_track(i, j, TaggerChannel_hel0);
                    }
                    else if (hel == 1)
                    {
                        if(i==0)
                            if(i==0)
                            {
                                Fillcoplanarity(j, coplanarity_hel1, kTRUE);
                                Fill_theta_neutron_calc_measured(j, theta_neutron_calculated_hel1, diff_theta_neutron_calculated_measured_hel1, neutron_theta_calc_measured_hel1, kTRUE);
                            }
                        Filltheta_track(i, j, theta_hel1, kTRUE);
                        FillTaggerChannel_track(i, j, TaggerChannel_hel1);
                    }

                    if(coplanarity_condition == true)
                    {
                        Fillcluster_size_track(i, j, cluster_size_CB_neutral_copl);
                        if(i==0)
                        {
                            Fillcoplanarity(j, coplanarity_cut, kTRUE);
                            FillMissingMasstrack(0, 1, j, MM0_copl, kTRUE);
                            FillMissingMasstrack(0, 1, j, MM1_copl, kTRUE);
                            Fill_theta_neutron_calc_measured(j, theta_neutron_calculated_copl, diff_theta_neutron_calculated_measured_copl, neutron_theta_calc_measured_copl, kTRUE);
                            Filldetector(detector_CB_TAPS_copl);

                        }
                        Filltheta_track(i, j, theta_copl, kTRUE);
                        FillTaggerChannel_track(i, j, TaggerChannel_copl);
                        if (hel == 0)
                        {
                            if(i==0) Fill_theta_neutron_calc_measured(j, theta_neutron_calculated_copl_hel0, diff_theta_neutron_calculated_measured_copl_hel0, neutron_theta_calc_measured_copl_hel0, kTRUE);
                            Filltheta_track(i, j, theta_hel0_copl, kTRUE);
                            FillTaggerChannel_track(i, j, TaggerChannel_hel0_copl);
                            FillMissingMasstrack(0, 1, j, MM0_copl_hel0, kTRUE);
                            FillMissingMasstrack(0, 1, j, MM1_copl_hel0, kTRUE);
                        }
                        else if (hel == 1)
                        {
                            if(i==0) Fill_theta_neutron_calc_measured(j, theta_neutron_calculated_copl_hel1, diff_theta_neutron_calculated_measured_copl_hel1, neutron_theta_calc_measured_copl_hel1, kTRUE);
                            Filltheta_track(i, j, theta_hel1_copl, kTRUE);
                            FillTaggerChannel_track(i, j, TaggerChannel_hel1_copl);
                            FillMissingMasstrack(0, 1, j, MM0_copl_hel1, kTRUE);
                            FillMissingMasstrack(0, 1, j, MM1_copl_hel1, kTRUE);
                        }

                        if(GetTracks()->IsCharged(i))
                        {
                            Filltheta_track(i, j, theta_charged, kTRUE);

                            if(GetTracks()->HasCB(i))
                            {
                                FilldE_E_CB_track(i, j, dE_E_CB_copl);
                                Fillcluster_size_track(i, j, cluster_size_CB_charged_copl);
                                if (hel == 0)
                                {
                                    FilldE_E_CB_track(i, j, dE_E_CB_copl_hel0);
                                }
                                if (hel == 1)
                                {
                                    FilldE_E_CB_track(i, j, dE_E_CB_copl_hel1);
                                }
                            }
                            if(GetTracks()->HasTAPS(i))
                            {
                                FillPSA_track(i, j, PSA_charged_copl);
                                FilldE_E_TAPS_track(i, j, dE_E_TAPS_copl);
                                FillTOF_TAPS(i, j, TOF_charged_copl);
                            }
                        }
                        if(GetTracks()->IsNeutral(i))
                        {
                            Filltheta_track(i, j, theta_neutral, kTRUE);
                            if(GetTracks()->HasCB(i))
                            {
                                Fillcluster_size_track(i, j, cluster_size_CB_neutral_copl);
                            }
                            if(GetTracks()->HasTAPS(i))
                            {
                                FillPSA_track(i, j, PSA_neutral_copl);
                                FillTOF_TAPS(i, j, TOF_neutral_copl);
                            }
                        }
                        /// FROM HERE NEW CUTS FOR PSA - PID - VETO
                        if(inside_dE_E_CB_cut == kTRUE)
                        {
                            if(i==0)
                            {
                                Fill_theta_neutron_calc_measured(j, theta_neutron_calcd_copl_protonCB, diff_theta_neutron_calcd_measured_copl_protonCB, neutron_theta_calc_measured_copl_protonCB, kTRUE);
                                if (hel == 0)
                                {
                                    Fill_theta_neutron_calc_measured(j, theta_neutron_calcd_copl_protonCB_hel0, diff_theta_neutron_calcd_measured_copl_protonCB_hel0, neutron_theta_calc_measured_copl_protonCB_hel0, kTRUE);
                                }
                                if (hel == 1)
                                {
                                    Fill_theta_neutron_calc_measured(j, theta_neutron_calcd_copl_protonCB_hel1, diff_theta_neutron_calcd_measured_copl_protonCB_hel1, neutron_theta_calc_measured_copl_protonCB_hel1, kTRUE);
                                }
                            }
                            if(GetTracks()->IsCharged(i))
                            {
                                if(GetTracks()->HasCB(i))
                                {
                                    FilldE_E_CB_track(i, j, dE_E_CB_copl2);
                                    Fillcluster_size_track(i, j, cluster_size_CB_charged_copl_dE);
                                }
                            }
                            if(GetTracks()->IsNeutral(i))
                            {
                                if(GetTracks()->HasTAPS(i))
                                {
                                    FillPSA_track(i, j, PSA_neutral_copl_PID_cut);
                                    FillTOF_TAPS(i, j, TOF_neutral_copl_PID_cut);
                                }
                                if(GetTracks()->HasCB(i))
                                {
                                    Fillcluster_size_track(i, j, cluster_size_CB_neutral_copl_dE);
                                }
                            }
                        }
                        if(inside_PSA_cut == kTRUE)
                        {
                            if(GetTracks()->IsCharged(i))
                            {
                                if(GetTracks()->HasCB(i))
                                {
                                    FilldE_E_CB_track(i, j, dE_E_CB_copl_PSA_cut);

                                }
                                if(GetTracks()->HasTAPS(i))
                                {
                                    FillPSA_track(i, j, PSA_charged_copl_PSA_cut);
                                    FillTOF_TAPS(i, j, TOF_charged_copl_PSA_cut);
                                    FilldE_E_TAPS_track(i, j, dE_E_TAPS_copl_PSA_cut);
                                }
                            }
                            if(GetTracks()->IsNeutral(i))
                            {
                                if(GetTracks()->HasTAPS(i))
                                {
                                    FillPSA_track(i, j, PSA_neutral_copl_PSA_cut);
                                    FillTOF_TAPS(i, j, TOF_neutral_copl_PSA_cut);
                                }
                            }
                        }
                        if(inside_PSA_cut == kTRUE && inside_dE_E_CB_cut == kTRUE)
                        {
                            if(i==0)
                            {
                                Fill_theta_neutron_calc_measured(j, theta_neutron_calcd_copl_protonCB_neutronTAPS, diff_theta_neutron_calcd_measured_copl_protonCB_neutronTAPS, neutron_theta_calc_measured_copl_protonCB_neutronTAPS, kTRUE);
                            }
                            if(GetTracks()->IsCharged(i))
                            {
                                if(GetTracks()->HasCB(i))
                                {
                                    FilldE_E_CB_track(i, j, dE_E_CB_copl_PSA_cut_PID_cut);
                                }
                            }

                            if(GetTracks()->IsNeutral(i))
                            {
                                if(GetTracks()->HasTAPS(i))
                                {
                                    FillPSA_track(i, j, PSA_neutral_copl_PID_cut_PSA_cut);
                                    FillTOF_TAPS(i, j, TOF_neutral_copl_PID_cut_PSA_cut);
                                }
                            }
                        }
                        if(above_dE_E_TAPS_cut == kTRUE)
                        {
                            if(GetTracks()->IsCharged(i))
                            {
                                if(GetTracks()->HasTAPS(i))
                                {
                                    FilldE_E_TAPS_track(i, j, dE_E_TAPS_copl_VETO_cut);
                                    FillPSA_track(i, j, PSA_charged_copl_VETO_cut);
                                    FillTOF_TAPS(i, j, TOF_charged_copl_VETO_cut);
                                }
                            }
                        }
                        if(inside_PSA_cut == kTRUE && (inside_dE_E_CB_cut == kTRUE || above_dE_E_TAPS_cut == kTRUE))
                        {
                            if(i==0)
                            {
                                //                                cout << "PSA, dE-CB or dE-TAPS cut i == 00000000000000000000000000000000000000000" << endl;
                                //                                Fill_theta_neutron_calc_measured(j, theta_neutron_calculated_copl_with_cuts, diff_theta_neutron_calculated_measured_copl_with_cuts, kTRUE);
                            }
                            if(GetTracks()->IsCharged(i))
                            {
                                if(GetTracks()->HasCB(i))
                                {
                                    FilldE_E_CB_track(i, j, dE_E_CB_copl_PID_cut_PSA_cut_VETO_cut);
                                }
                                if(GetTracks()->HasTAPS(i))
                                {
                                    FilldE_E_TAPS_track(i, j, dE_E_TAPS_PID_cut_PSA_cut_VETO_cut);
                                    FillPSA_track(i, j, PSA_charged_copl_PID_cut_PSA_cut_VETO_cut);
                                    FillTOF_TAPS(i, j, TOF_charged_copl_PID_cut_PSA_cut_VETO_cut);
                                }
                            }
                            if(GetTracks()->IsNeutral(i))
                            {
                                if(GetTracks()->HasTAPS(i))
                                {
                                    FillPSA_track(i, j, PSA_neutral_copl_PID_cut_PSA_cut_VETO_cut);
                                    FillTOF_TAPS(i, j, TOF_neutral_copl_PID_cut_PSA_cut_VETO_cut);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void	prova_dstar::ProcessScalerRead()
{
    // Fill Tagger Scalers
    FillScalers(GetTC_scaler_min(),GetTC_scaler_max(), TaggerAccScal_fede);

    //static bool Switch = false;
    static Double_t Livetime;
    //  std::cout << scalers->GetScaler(0) << std::endl;
    if(scalers->GetScaler(0))  //Tagger
    {
        //Switch = true;
        //      std::cout << std::endl;
        Livetime = Double_t(scalers->GetScaler(190))/(scalers->GetScaler(191));
    }

    LivetimeHist->Fill(Livetime*100);
    //Double_t corrfactor = Livetime*100;

    for(int i=0; i<=8705; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));

        AllScl_fede->Fill(i, value);
    }

    /// TAGGER CONFIGURAZIONE 2015!!!
    /// TAGGER Section AB 0-31
    for(int i=2864; i<=2895; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2864;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2864, newvalue);
    }

    /// TAGGER Section CD 31-63
    for(int i=2064; i<=2095; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2064+32;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2064+32, newvalue);
    }

    /// TAGGER Section EF 64-95
    for(int i=2576; i<=2607; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2576+64;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2576+64, newvalue);
    }

    /// TAGGER Section GH 96-127
    for(int i=2288; i<=2319; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2288+96;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2288+96, newvalue);
    }

    /// TAGGER Section IJ 128-159
    for(int i=2000; i<=2031; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2000+128;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2000+128, newvalue);
    }

    /// TAGGER Section KL 160-191
    for(int i=2352; i<=2383; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2352+160;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2352+160, newvalue);
    }

    /// TAGGER Section MN 192-223
    for(int i=2640; i<=2671; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2640+192;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2640+192, newvalue);
    }

    /// TAGGER Section OP 224-255
    for(int i=2032; i<=2063; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2032+224;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2032+224, newvalue);
    }

    /// TAGGER Section QR 256-287
    for(int i=2320; i<=2351; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2320+256;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2320+256, newvalue);
    }

    /// TAGGER Section ST 288-319
    for(int i=2608; i<=2639; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2608+288;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2608+288, newvalue);
    }

    /// TAGGER Section UV 320-351
    for(int i=2896; i<=2927; i++)
    {
        Double_t value = Double_t(scalers->GetScaler(i));
        Double_t newvalue = value*Livetime;
        //cout << "value   " << value << "   newvalue   " << newvalue << "   Livetime   " << Livetime << endl;
        Int_t p = i-2896+320;
        TaggerScalers_uncorr->Fill(p, value);
        TaggerScalers_corr->Fill(i-2896+320, newvalue);
    }

}

Bool_t	prova_dstar::Write()
{
    return GTreeManager::Write();
    GTreeManager::Write(TaggerAccScal_fede);
    GTreeManager::Write(TaggerScalers_uncorr);
    GTreeManager::Write(TaggerScalers_corr);
    GTreeManager::Write(LivetimeHist);
    GTreeManager::Write(AllScl_fede);
}


void prova_dstar::Fill_theta_neutron_calc_measured(Int_t tagger_index, GH1* gHist, GH1* gHist2, GHistBGSub2* gHist3, Bool_t TaggerBinning)
{
    double zp = 0;
    double zn = 0;
    double theta_proton = 0;
    double theta_neutron = 0;
    double time_neutron = 0;
    //    double theta_proton = 0;

    double deuteron_mass = 1875.612859;
    double proton_mass = 938.272046;
    double neutron_mass = 939.565379;
    double Eg = (GetTagger()->GetTaggedEnergy(tagger_index));
    //    cout << "tagger energy: " << Eg << endl;
    int index_proton;
    int index_neutron;
    for(Int_t r=0; r<GetTracks()->GetNTracks(); r++)
    {
        if(GetTracks()->IsCharged(r))
        {
            zp = TMath::Cos((GetTracks()->GetTheta(r))*TMath::DegToRad());
            theta_proton = GetTracks()->GetTheta(r);
            index_proton = r;
            //            cout << "check zp: " << zp << " theta: " << (GetTracks()->GetTheta(r)) << " check: " << (GetTracks()->GetTheta(r))*TMath::DegToRad() << endl;
        }
        else if(GetTracks()->IsNeutral(r))
        {
            theta_neutron = GetTracks()->GetTheta(r);
            index_neutron = r;
        }
        //    double En=(1./2.)*(-2*TMath::Power(Eg, 3)*TMath::Power(zp, 2) + 2*TMath::Power(Eg, 3) - 2*TMath::Power(Eg, 2)*deuteron_mass*TMath::Power(zp, 2) + 4*TMath::Power(Eg, 2)*deuteron_mass + 3*Eg*TMath::Power(deuteron_mass, 2) + Eg*TMath::Power(neutron_mass, 2) - Eg*TMath::Power(proton_mass, 2) - Eg*zp*TMath::Sqrt(4*TMath::Power(Eg, 2)*TMath::Power(deuteron_mass, 2) + 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2)*TMath::Power(zp, 2) - 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2) + 4*Eg*TMath::Power(deuteron_mass, 3) - 4*Eg*deuteron_mass*TMath::Power(neutron_mass, 2) - 4*Eg*deuteron_mass*TMath::Power(proton_mass, 2) + TMath::Power(deuteron_mass, 4) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(neutron_mass, 2) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(neutron_mass, 4) - 2*TMath::Power(neutron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(proton_mass, 4)) + TMath::Power(deuteron_mass, 3) + deuteron_mass*TMath::Power(neutron_mass, 2) - deuteron_mass*TMath::Power(proton_mass, 2))/(-TMath::Power(Eg, 2)*TMath::Power(zp, 2) + TMath::Power(Eg, 2) + 2*Eg*deuteron_mass + TMath::Power(deuteron_mass, 2));
        //    double Ep=(2*TMath::Power(Eg, 2)*deuteron_mass + 3*Eg*TMath::Power(deuteron_mass, 2) - Eg*TMath::Power(neutron_mass, 2) + Eg*TMath::Power(proton_mass, 2) + Eg*zp*TMath::Sqrt(4*TMath::Power(Eg, 2)*TMath::Power(deuteron_mass, 2) + 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2)*TMath::Power(zp, 2) - 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2) + 4*Eg*TMath::Power(deuteron_mass, 3) - 4*Eg*deuteron_mass*TMath::Power(neutron_mass, 2) - 4*Eg*deuteron_mass*TMath::Power(proton_mass, 2) + TMath::Power(deuteron_mass, 4) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(neutron_mass, 2) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(neutron_mass, 4) - 2*TMath::Power(neutron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(proton_mass, 4)) + TMath::Power(deuteron_mass, 3) - deuteron_mass*TMath::Power(neutron_mass, 2) + deuteron_mass*TMath::Power(proton_mass, 2))/(-2*TMath::Power(Eg, 2)*TMath::Power(zp, 2) + 2*TMath::Power(Eg, 2) + 4*Eg*deuteron_mass + 2*TMath::Power(deuteron_mass, 2));
    }
    double zn_calc = (Eg - zp*TMath::Sqrt(-TMath::Power(proton_mass, 2) + TMath::Power(Eg + deuteron_mass - 1./2.*(2*TMath::Power(Eg, 3)*TMath::Power(zp, 2) - 2*TMath::Power(Eg, 3) + 2*TMath::Power(Eg, 2)*deuteron_mass*TMath::Power(zp, 2) - 4*TMath::Power(Eg, 2)*deuteron_mass - 3*Eg*TMath::Power(deuteron_mass, 2) - Eg*TMath::Power(neutron_mass, 2) + Eg*TMath::Power(proton_mass, 2) + Eg*zp*TMath::Sqrt(4*TMath::Power(Eg, 2)*TMath::Power(deuteron_mass, 2) + 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2)*TMath::Power(zp, 2) - 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2) + 4*Eg*TMath::Power(deuteron_mass, 3) - 4*Eg*deuteron_mass*TMath::Power(neutron_mass, 2) - 4*Eg*deuteron_mass*TMath::Power(proton_mass, 2) + TMath::Power(deuteron_mass, 4) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(neutron_mass, 2) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(neutron_mass, 4) - 2*TMath::Power(neutron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(proton_mass, 4)) - TMath::Power(deuteron_mass, 3) - deuteron_mass*TMath::Power(neutron_mass, 2) + deuteron_mass*TMath::Power(proton_mass, 2))/(TMath::Power(Eg, 2)*TMath::Power(zp, 2) - TMath::Power(Eg, 2) - 2*Eg*deuteron_mass - TMath::Power(deuteron_mass, 2)), 2)))/TMath::Sqrt(-TMath::Power(neutron_mass, 2) + (1.0/4.0)*TMath::Power(2*TMath::Power(Eg, 3)*TMath::Power(zp, 2) - 2*TMath::Power(Eg, 3) + 2*TMath::Power(Eg, 2)*deuteron_mass*TMath::Power(zp, 2) - 4*TMath::Power(Eg, 2)*deuteron_mass - 3*Eg*TMath::Power(deuteron_mass, 2) - Eg*TMath::Power(neutron_mass, 2) + Eg*TMath::Power(proton_mass, 2) + Eg*zp*TMath::Sqrt(4*TMath::Power(Eg, 2)*TMath::Power(deuteron_mass, 2) + 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2)*TMath::Power(zp, 2) - 4*TMath::Power(Eg, 2)*TMath::Power(proton_mass, 2) + 4*Eg*TMath::Power(deuteron_mass, 3) - 4*Eg*deuteron_mass*TMath::Power(neutron_mass, 2) - 4*Eg*deuteron_mass*TMath::Power(proton_mass, 2) + TMath::Power(deuteron_mass, 4) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(neutron_mass, 2) - 2*TMath::Power(deuteron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(neutron_mass, 4) - 2*TMath::Power(neutron_mass, 2)*TMath::Power(proton_mass, 2) + TMath::Power(proton_mass, 4)) - TMath::Power(deuteron_mass, 3) - deuteron_mass*TMath::Power(neutron_mass, 2) + deuteron_mass*TMath::Power(proton_mass, 2), 2)/TMath::Power(TMath::Power(Eg, 2)*TMath::Power(zp, 2) - TMath::Power(Eg, 2) - 2*Eg*deuteron_mass - TMath::Power(deuteron_mass, 2), 2));
    //    Double_t zn=(Eg - zp*std::sqrt(-std::pow(Mp, 2) + std::pow(Eg + Md - 1.0/2.0*(2*std::pow(Eg, 3)*std::pow(zp, 2) - 2*std::pow(Eg, 3) + 2*std::pow(Eg, 2)*Md*std::pow(zp, 2) - 4*std::pow(Eg, 2)*Md - 3*Eg*std::pow(Md, 2) - Eg*std::pow(Mn, 2) + Eg*std::pow(Mp, 2) + Eg*zp*std::sqrt(4*std::pow(Eg, 2)*std::pow(Md, 2) + 4*std::pow(Eg, 2)*std::pow(Mp, 2)*std::pow(zp, 2) - 4*std::pow(Eg, 2)*std::pow(Mp, 2) + 4*Eg*std::pow(Md, 3) - 4*Eg*Md*std::pow(Mn, 2) - 4*Eg*Md*std::pow(Mp, 2) + std::pow(Md, 4) - 2*std::pow(Md, 2)*std::pow(Mn, 2) - 2*std::pow(Md, 2)*std::pow(Mp, 2) + std::pow(Mn, 4) - 2*std::pow(Mn, 2)*std::pow(Mp, 2) + std::pow(Mp, 4)) - std::pow(Md, 3) - Md*std::pow(Mn, 2) + Md*std::pow(Mp, 2))/(std::pow(Eg, 2)*std::pow(zp, 2) - std::pow(Eg, 2) - 2*Eg*Md - std::pow(Md, 2)), 2)))/         std::sqrt(-std::pow(Mn, 2) + (1.0/4.0)*std::pow(2*std::pow(Eg, 3)*std::pow(zp, 2) - 2*std::pow(Eg, 3) + 2*std::pow(Eg, 2)*Md*std::pow(zp, 2) - 4*std::pow(Eg, 2)*Md - 3*Eg*std::pow(Md, 2) - Eg*std::pow(Mn, 2) + Eg*std::pow(Mp, 2) + Eg*zp*std::sqrt(4*std::pow(Eg, 2)*std::pow(Md, 2) + 4*std::pow(Eg, 2)*std::pow(Mp, 2)*std::pow(zp, 2) - 4*std::pow(Eg, 2)*std::pow(Mp, 2) + 4*Eg*std::pow(Md, 3) - 4*Eg*Md*std::pow(Mn, 2) - 4*Eg*Md*std::pow(Mp, 2) + std::pow(Md, 4) - 2*std::pow(Md, 2)*std::pow(Mn, 2) - 2*std::pow(Md, 2)*std::pow(Mp, 2) + std::pow(Mn, 4) - 2*std::pow(Mn, 2)*std::pow(Mp, 2) + std::pow(Mp, 4)) - std::pow(Md, 3) - Md*std::pow(Mn, 2) + Md*std::pow(Mp, 2), 2)/            std::pow(std::pow(Eg, 2)*std::pow(zp, 2) - std::pow(Eg, 2) - 2*Eg*Md - std::pow(Md, 2), 2));
    double time = GetTagger()->GetTaggedTime(tagger_index) - GetTracks()->GetTime(index_neutron);

    // diff_theta_check = theta_proton;
    // diff_theta_check = theta_neutron;
    value_theta_neutron_calculated = (TMath::ACos(zn_calc))*TMath::RadToDeg();
    diff_theta_check = value_theta_neutron_calculated-theta_neutron;
    gHist3->Fill(value_theta_neutron_calculated, theta_neutron, time);
    if(TaggerBinning)
    {
        gHist->Fill(value_theta_neutron_calculated, time, GetTagger()->GetTaggedChannel(tagger_index));
        gHist2->Fill(diff_theta_check, time, GetTagger()->GetTaggedChannel(tagger_index));

    }
    else
    {
        gHist->Fill(value_theta_neutron_calculated, time);
        gHist2->Fill(diff_theta_check, time);
    }
}
