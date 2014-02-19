#include "Package.h"
#include "Person.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//check pointers
//delete stuff

void labelFunc(Person &s, Person &r, double cost);
void fileInputFunc ();

int main()
{
    fileInputFunc();
    Person a();
    
    int pause=0;
    cin>>pause;
    return 0;
}

void labelFunc(Person &s, Person &r, double cost)
{
    string StempN=s.getName();
    string StempA=s.getAdd();
    string StempC=s.getCity();
    string StempS=s.getState();
    string StempZ=s.getZip();

    string RtempN=r.getName();
    string RtempA=r.getAdd();
    string RtempC=r.getCity();
    string RtempS=r.getState();
    string RtempZ=r.getZip();

    cout<<endl;
    cout<<"******SHIPPING LABEL******"<<endl<<endl;
    cout<<"Delivery Cost: $"<< fixed<<setprecision(2)<< cost<< endl<<endl<<endl;
    
    cout<<"FROM: "<<endl;
    cout<<StempN <<endl;
    cout<<StempA<<"\n"<<StempC<<", "<<StempS<<" "<<StempZ<<endl<<endl<<endl;

    cout<<"SHIP TO: "<<endl;
    cout<<RtempN <<endl;
    cout<<RtempA<<endl;
    cout<<RtempC<<", "<<RtempS<<" "<<RtempZ<<endl<<endl;
    cout<<"***************************"<<endl<<endl<<endl<<endl;    
}
void fileInputFunc ()
{
    string pkgType, sName, sAdd, sCity, sState, sZip, rName, rAdd, rCity, rState, rZip;
    double weight, costPerOz, addPerOz, addFlatRate, costToShip;
        
    ifstream fin ("package.txt");
    
    //Find the package type
    getline(fin, pkgType);
    
    //Continue until end of file
    while(!fin.eof())
    {        
        if( pkgType == "p" || pkgType  == "P")
        {
            string temp;

            //weight
            getline(fin, temp);
            weight=atof(temp.c_str());

            //costPerOz
            getline(fin, temp);
            costPerOz=atof(temp.c_str());
            
            //Sender info
            getline(fin, sName);
            getline(fin, sAdd);
            getline(fin, sCity);
            getline(fin, sState);
            getline(fin, sZip);

            //Recipient info
            getline(fin, rName);
            getline(fin, rAdd);
            getline(fin, rCity);
            getline(fin, rState);
            getline(fin, rZip);
            
            //Intances of Person
            Person s(sName, sAdd, sCity, sState, sZip);
            Person r(rName, rAdd, rCity, rState, rZip);

            //Intance of Package
            Package P (weight, costPerOz, s, r);
            
            //Calculate
            costToShip=P.costCalc();

            //Create label
            labelFunc(s, r, costToShip);
        }
        else if( pkgType == "O" || pkgType  == "o")
        {
            string temp;
            //line?
            getline(fin, temp);
            
            //weight
            getline(fin, temp);
            weight=atof(temp.c_str());
            
            //costPerOz
            getline(fin, temp);
            costPerOz=atof(temp.c_str());
            
            //sender info
            getline(fin, sName);
            getline(fin, sAdd);
            getline(fin, sCity);
            getline(fin, sState);
            getline(fin, sZip);

            //recipient info
            getline(fin, rName);
            getline(fin, rAdd);
            getline(fin, rCity);
            getline(fin, rState);
            getline(fin, rZip);

            //Additional flat charge
            getline(fin,temp);
            addFlatRate=atof(temp.c_str());
            
            //intances of Person
            Person s(sName, sAdd, sCity, sState, sZip);
            Person r(rName, rAdd, rCity, rState, rZip);
            
            //instance of OvernightPackage
            OvernightPackage O (addFlatRate, weight, costPerOz, s, r);
            
            //Calculate cost
            costToShip=O.costCalc(addFlatRate);

            //Create label
            labelFunc(s, r, costToShip);
        }
        else if( pkgType == "T" || pkgType  == "t")
        {
            string temp;
            //line?
            getline(fin, temp);

            //weight
            getline(fin, temp);
            weight=atof(temp.c_str());

            //costPerOz
            getline(fin, temp);
            costPerOz=atof(temp.c_str());

            //Sender info            
            getline(fin, sName);
            getline(fin, sAdd);
            getline(fin, sCity);
            getline(fin, sState);
            getline(fin, sZip);

            //Recipient info
            getline(fin, rName);
            getline(fin, rAdd);
            getline(fin, rCity);
            getline(fin, rState);
            getline(fin, rZip);

            //Additional cost per oz.
            getline(fin,temp);
            addPerOz=atof(temp.c_str());
            
            //Instances of Person
            Person s(sName, sAdd, sCity, sState, sZip);
            Person r(rName, rAdd, rCity, rState, rZip);
            
            //Instance of TwoDayPackage
            TwoDayPackage T (addPerOz, weight, costPerOz, s, r);
            
            //Calculate
            costToShip=T.costCalc(addPerOz);

            //Create label
            labelFunc(s, r, costToShip);
        }    
        fin>>pkgType; 
    }
}