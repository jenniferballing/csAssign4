#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

//Base Class
class Package
{
	//Shared with derived classes
	double weight;
	double costPerOz;
	Person sender;
	Person receiver;

public:
	Package(void);
	Package(double, double, Person, Person);
	double getWeight();
	double getCostPerOz();
	void setWeight(double);
	void setCostPerOz(double);
	double costCalc();
	~Package(void);
};
#endif

