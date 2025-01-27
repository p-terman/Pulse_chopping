/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef ROOWIMPSPECTRUM
#define ROOWIMPSPECTRUM

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooWimpSpectrum : public RooAbsPdf {
public:
  RooWimpSpectrum() {} ; 
  RooWimpSpectrum(const char *name, const char *title,
	      RooAbsReal& _Enr,
	      RooAbsReal& _mWimp,
	      RooAbsReal& _v0,
	      RooAbsReal& _ve,
	      RooAbsReal& _vesc,
	      RooAbsReal& _rho,
	      RooAbsReal& _c,
	      RooAbsReal& _r,
	      RooAbsReal& _a,
	      RooAbsReal& _s,
	      RooAbsReal& _delta,
	      RooAbsReal& _beta);
  RooWimpSpectrum(const RooWimpSpectrum& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooWimpSpectrum(*this,newname); }
  inline virtual ~RooWimpSpectrum() { }

protected:

  RooRealProxy Enr ;
  RooRealProxy mWimp ;
  RooRealProxy v0 ;
  RooRealProxy ve ;
  RooRealProxy vesc ;
  RooRealProxy rho ;
  RooRealProxy c ;
  RooRealProxy r ;
  RooRealProxy a ;
  RooRealProxy s ;
  RooRealProxy delta ;
  RooRealProxy beta ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooWimpSpectrum,1) // Your description goes here...
};
 
#endif
