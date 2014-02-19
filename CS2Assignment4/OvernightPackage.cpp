#include "OvernightPackage.h"

OvernightPackage::OvernightPackage()
{
     flatRate=0;
}
OvernightPackage::OvernightPackage(double f, int w, double c, Person s, Person r):Package (w, c, s, r) 
{
     flatRate=f;
}
void OvernightPackage::setFlatRate(double f)
{
     flatRate=f;
}
double OvernightPackage::getFlatRate()
{
     return flatRate;
}
double OvernightPackage::costCalc(double a)
{
    int w=getWeight();
    double cpo=getCostPerOz();
    double cost=w*cpo;
    cost+=a;
    return cost;
}

OvernightPackage::~OvernightPackage(void)
{
}
