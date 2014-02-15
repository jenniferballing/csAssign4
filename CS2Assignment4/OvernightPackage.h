#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include <iostream>
#include <string>
#include "Package.h"
#include "Person.h"

class OvernightPackage:public Package
{
     double flatRate;
public:
     OvernightPackage(void);
     OvernightPackage(double, double, double, Person, Person);
     void setFlatRate(double);
     double getFlatRate();
     ~OvernightPackage(void);
};
#endif
