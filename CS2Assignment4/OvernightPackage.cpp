#include "OvernightPackage.h"

OvernightPackage::OvernightPackage()
{
     flatRate=0;
}
OvernightPackage::OvernightPackage(double f, double w, double c, Person s, Person r):Package (w, c, s, r) 
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

OvernightPackage::~OvernightPackage(void)
{
}
