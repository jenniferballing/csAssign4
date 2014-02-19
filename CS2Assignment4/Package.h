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
	int weight;
	double costPerOz;
	Person sender;
	Person receiver;

public:
	Package(void);
	Package(int, double, Person, Person);
	int getWeight();
	double getCostPerOz();
	void setWeight(int);
	void setCostPerOz(double);
	double costCalc();
	~Package(void);
};
#endif

