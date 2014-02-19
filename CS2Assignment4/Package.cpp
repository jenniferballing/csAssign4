#include "Package.h"
#include <fstream>
#include "Person.h"

fstream fin ("package.txt");


Package::Package(void)
{
	weight =0;
	costPerOz=0;
}

Package::Package(int w, double cost, Person s, Person r)
{
	weight=w;
	costPerOz=cost;
	Person temp1;
	Person temp2;
	
	//Use my copy constructor
	sender = s;
	receiver = r;
}

int Package::getWeight()
{
	return weight;	
}
double Package::getCostPerOz()
{
	return costPerOz;
}
void Package::setWeight(int w)
{
	weight = w;
}
void Package::setCostPerOz(double cost)
{
	costPerOz = cost;
}

double Package::costCalc()
{
	return (double)weight*costPerOz;
}

Package::~Package(void)
{
}
