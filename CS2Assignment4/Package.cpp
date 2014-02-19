#include "Package.h"
#include <fstream>
#include "Person.h"

fstream fin ("package.txt");


Package::Package(void)
{
	weight =0;
	costPerOz=0;
}

Package::Package(double w, double cost, Person s, Person r)
{
	weight=w;
	costPerOz=cost;
	Person temp1;
	Person temp2;
	
	//Use my copy constructor
	sender = s;
	receiver = r;
}

double Package::getWeight()
{
	return weight;	
}
double Package::getCostPerOz()
{
	return costPerOz;
}
void Package::setWeight(double w)
{
	weight = w;
}
void Package::setCostPerOz(double cost)
{
	costPerOz = cost;
}

double Package::costCalc()
{
	return weight*costPerOz;
}

Package::~Package(void)
{
}
