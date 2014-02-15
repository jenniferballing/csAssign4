#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include <string>
#include <sstream>

using namespace std;

class Person
{
	string name;
	string address;
	string city;
	string state;
	string zipCode;

public:
	Person(void);
	Person (string, string, string, string, string);
     Person(const Person &);

	string getName ();
	string getAdd ();
	string getCity ();
	string getState ();
	string getZip ();

	void setName (string);
	void setAdd (string);
	void setCity (string);
	void setState (string);
	void setZip (string);

	~Person(void);
};
#endif

