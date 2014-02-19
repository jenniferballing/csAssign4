#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "package.h"

class TwoDayPackage:public Package
{
     double CPOIncrease;

public:
     TwoDayPackage(void);
     TwoDayPackage(double cpo, double w, double c, Person s, Person r);
     void setCPOIncrease(double);
     double getCPOIncrease();
     double costCalc(double);
     ~TwoDayPackage(void);
};
#endif
