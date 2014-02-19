#include "TwoDayPackage.h"


TwoDayPackage::TwoDayPackage(void)
{
     CPOIncrease=0;
}
TwoDayPackage::TwoDayPackage(double cpo, double w, double c, Person s, Person r): Package(w, c, s, r)
{
     CPOIncrease=cpo;
}
void TwoDayPackage::setCPOIncrease(double i)
{
     CPOIncrease = i;
}
double TwoDayPackage::getCPOIncrease()
{
     return CPOIncrease;
}
double TwoDayPackage::costCalc(double a)
{
    double c=getCostPerOz();
    double w=getWeight();
    double cost=(c+a)*w;
    return cost;
}

TwoDayPackage::~TwoDayPackage(void)
{

}
