#include "Person.h"


Person::Person(void)
{
	name=" ";
	address=" ";
	city=" ";
	state=" ";
	zipCode=" ";
}

Person::Person (string n, string a, string c, string s, string z)
{
	name=n;
	address=a;
	city=c;
	state=s;
	zipCode=z;
}

//copy constructor
Person::Person (const Person &obj)
{
	string tempN, tempA, tempC, tempS, tempZ;
	
	//parse obj
	stringstream sn(obj.name), sa(obj.address), sc(obj.city), ss(obj.state), sz(obj.zipCode);
	sn>>tempN;
	sa>>tempA;
	sc>>tempC;
	ss>>tempS;
	sz>>tempZ;

	 //Put back into strings and assign to this
	 stringstream ssn, ssa, ssc, sss, ssz;
	 ssn<<tempN;
	name=ssn.str();
	 ssn<<tempA;
	address=ssa.str();
	 ssn<<tempC;
	city=ssc.str();
	 ssn<<tempS;
	state=sss.str();
	 ssn<<tempZ;
	zipCode=ssz.str();	
}

string Person::getName ()
{
	return name;
}
string Person::getAdd ()
{
	return address;
}
string Person::getCity ()
{
	return city;
}
string Person::getState ()
{
	return state;
}
string Person::getZip ()
{
	return zipCode;
}

void Person::setName (string n)
{
	name=n;
}
void Person::setAdd (string a)
{
	address = a;
}
void Person::setCity (string c)
{
	city=c;
}
void Person::setState (string s)
{
	state=s;
}
void Person::setZip (string z)
{
	zipCode=z;
}

void Person::printFunction()
{
	cout<<name<<endl<<address<<endl;
	cout<<city<<" "<<state<<", "<<zipCode<<endl;
}

Person::~Person(void)
{
}
