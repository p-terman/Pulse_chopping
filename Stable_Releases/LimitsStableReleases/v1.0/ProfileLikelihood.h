// ProfileLikelihood.h : a header file to define all the RooRealVars for ProfileLikelihood.C
#include "RooRealVar.h"

using namespace RooFit;

double limitCL = 0.90; // confidence level for limit
bool setOneSided = kTRUE;
bool bgNormFixed = kFALSE;
bool bandsFixed = kTRUE;

//double ntrials = 100; // number of pseudoexperiments
//int npointsHypoTest = 2;  // number of points to scan in HypoTest
double ntrials = 1000; // number of pseudoexperiments
int npointsHypoTest = 20;  // number of points to scan in HypoTest
double poimin = 1.0; // min value of poi to test in hypo test scan
double poimax = 9.0; // max value of poi to test in hypo test scan

// Input signal model parameters
double nrmA = 0.;
double nrmB = 0.;
double nrsA = 0.;
double nrsB = 0.;
double m0 = 0.;
double nSigPerKgPbDay = 0.;

//Number of events in calibration samples
RooRealVar nNrCalib("nNrCalib","Number of NR calibration events",1000);
RooRealVar nErCalib("nErCalib","Number of ER calibration events",1000);

//Parameters of interest
RooRealVar sig_xs("sig_xs","#sigma_{0} [pb]", 1.e-07, 1.e-14, 1.e-07); // spin-independent WIMP-nucleon cross-section [pb]
//RooRealVar sig_xs("sig_xs","#sigma_{0} [pb]", 1.46e-09,1e-14, 1e-07); // spin-independent WIMP-nucleon cross-section [pb]
RooRealVar mWimp("mWimp","WIMP mass [GeV/c^{2}]", 100); // WIMP mass [GeV/c2], having a single constant value

//We tend to use xenon...
RooRealVar targetZ("targetZ","Protons per target nucleus",54);
RooRealVar targetA("targetA","Nucleons per target nucleus ",131);

//Defining search volume
 //Net time we were open for WIMP business (excludes DAQ dead-time, e-train dead-time, etc.)
//RooRealVar T("T", "net livetime [days]", 77.3); // exposure time [days] .
//RooRealVar T("T", "net livetime [days]", 84.5); // exposure time [days] .
//RooRealVar r("r","radius [cm]",0,0,17.); //the reconstructed radial position [cm] relative to central axis of LUX
//RooRealVar z("z","z [cm]",9,47); //the reconstructed z position [cm], relative to top face of bottom PMT array

RooRealVar T("T", "net livetime [days]", 88.3); // exposure time [days] .
RooRealVar r("r","radius [cm]",0,0,18.); //the reconstructed radial position [cm] relative to central axis of LUX
RooRealVar z("z","z [cm]",7,47); //the reconstructed z position [cm], relative to top face of bottom PMT array

//Halo parameters
RooRealVar rho("rho","WIMP density [GeV.c^-{2}.cm^{-3}]",0.3); // density of WIMPs in LUX [GeV.c^-2.cm^-3]
RooRealVar vE("vE","v_{earth} [km/s]",232.); // speed of the Earth in the DM halo frame [km/s]
RooRealVar dayOfYear("dayOfYear","days after Dec31, used to find Earth velocity",44);//day 44 of the year corresponds to 232 km/sec. Vary this to investigate annual modulation
RooRealVar vEsc("vEsc","v_{esc} [km/s]",544); // local escape velocity [km/s]
RooRealVar v0("v0","v_0 of halo",220); // sqrt(2/3) times the velocity dispersion of WIMPs in halo frame

// Form factor parameters
RooRealVar ff_c("ff_c","Nuclear radius parameter",5.6384); // nuclear radius parameter [fm]
RooRealVar ff_r0("ff_r0","Nuclear radius parameter",6.0945);  // nuclear radius parameter - not currently used in f.f. [fm]
RooRealVar ff_a("ff_a","Nuclear radius parameter",0.523); // nuclear radius parameter [fm]
//RooRealVar ff_s("ff_s","Skin depth parameter",0.9); // nuclear skin thickness[fm]
RooRealVar ff_s("ff_s","Skin depth parameter",1.0); // nuclear skin thickness[fm]
RooRealVar idm_delta("idm_delta","Inelastic mass splitting",0.); // inelastic mass splitting [keV]
RooRealVar halo_beta("halo_beta","Halo beta parameter",0.); // currently assumed 0 in WIMP velocity integral

//Energy variables
RooRealVar Enr("Enr","Enr [keV]",2,50); //nuclear recoil energy [keV]
//RooRealVar Enr("Enr","Enr [keV]",2,4); //nuclear recoil energy [keV]
RooRealVar Eee("Eee","Eee [keV]",0.1,20); //electron recoil energy [keV]

// Numbers of quanta generated by an event
RooRealVar nPhot("nPhot","nPhot",0,1200); //number of liquid scintillation photons generated by an event
RooRealVar nE("nE","nE",0,800); // number of ionisation electrons generated by an event

// Number of quanta reconstructed by our measurement of S1 and S2
//RooRealVar S1("S1","S1 [estimated photons]",0,200);
//RooRealVar S2("S2","S2 [estimated electrons]",0,200);

RooRealVar S1("S1","S1 [estimated photons]",2,30);
//RooRealVar S1("S1","S1 [estimated photons]",2,40);
//RooRealVar S1("S1","S1 [estimated photons]",3,30);
RooRealVar logS2S1("logS2S1","log10(S2/S1)",0.5,3);

// Compton background model parameters
//RooRealVar rateCompton("rateCompton","Rate of Compton bkg events",3.35e-05); // cts/day/kg/keVee
//RooRealVar ra("ra","Compton bkg elliposid radius param", 12.2); // [cm]
//RooRealVar za("za","Compton bkg elliposid z param", 27.7); // [cm]
//RooRealVar zb("zb","Compton bkg elliposid z param", 11.6); // [cm]

//Updated bg model - 9/17/13
RooRealVar rateCompton("rateCompton","Rate of Compton bkg events",1.11e-04); // cts/day/kg/keVee
RooRealVar ra("ra","Compton bkg elliposid radius param", 11.3); // [cm]
RooRealVar rd("rd","Compton bkg elliposid radius param", 2.56); // [cm]

RooRealVar za("za","Compton bkg elliposid z param", 26.9); // [cm]
RooRealVar zb("zb","Compton bkg elliposid z param", 11.7); // [cm]
RooRealVar zd("zd","Compton bkg elliposid z param", 2.56); // [cm]

// Xe-127 background model parameters
//RooRealVar rateActivatedXe("rateActivatedXe","Rate of Xe-127 bkg events",4e-04); // cts/day/kg/keVee
RooRealVar rateActivatedXeA("rateActivatedXeA","Rate of Xe-127 bkg events",3.86e-06); // cts/day/kg/keVee
RooRealVar rateActivatedXeB("rateActivatedXeB","Rate of Xe-127 bkg events",5.23e-07); // cts/day/kg/keVee

// Rn-222 background model parameters
//RooRealVar rateRn("rateRn","Rate of Rn bkg events",5e-04); // cts/day/kg/keVee
RooRealVar rateRn("rateRn","Rate of Rn bkg events",1.56e-04); // cts/day/kg/keVee

// Detector parameters
//RooRealVar xeDensity("xeDensity","Density of liquid xenon", 2.87e-03); // [kg/cm3]
RooRealVar xeDensity("xeDensity","Density of liquid xenon", 2.888e-03); // [kg/cm3]
RooRealVar zLiquid("zLiquid","z position at liquid level", 49.5); // [cm]
RooRealVar driftVelocity("driftVelocity","Drift speed of electrons",0.15); // [cm/us]
RooRealVar eTau("eTau","Electron lifetime", 800); // [us]

RooRealVar thresNe("thresNe","Threshold on number of electrons",2.); // # electrons
RooRealVar singleElec("singleElec","Single electron area", 26.); // [phe]

// Normalization parameters for background pdfs
RooRealVar nCompton("nCompton","Number of Compton bkg events", 100, 0, 1000);
RooRealVar nActivatedXe("nActivatedXe","Number of Xe-127 bkg events", 100, 0, 1000);
RooRealVar nRn("nRn","Number of Rn bkg events", 100, 0, 1000);

RooRealVar relUncertaintyBg("relUncertaintyBg","Relative uncertainty on number bkg events",0.3); 
//RooRealVar sigmaCompton("sigmaCompton","Uncertainty on number of Compton bkg events",0, 1000); 
//RooRealVar sigmaActivatedXe("sigmaActivatedXe","Uncertainty on number of Xe-127 bkg events",0, 1000); 
//RooRealVar sigmaRn("sigmaRn","Uncertainty on number of Rn-222 bkg events",0, 1000); 


