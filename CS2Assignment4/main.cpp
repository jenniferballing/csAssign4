#include "Package.h"
#include "Person.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include <fstream>
#include <iomanip>

void labelFunc(Person &s, Person &r, double cost);
void fileInputFunc ();

int main()
{
    fileInputFunc();
    
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

    cout<<"***SHIPPING LABEL***"<<endl<<endl;
    cout<<"Delivery Cost: $"<< fixed<<setprecision(2)<< cost<< endl<<endl<<endl;
    
    cout<<"FROM: "<<endl;
    cout<<StempN <<endl;
    cout<<StempA<<"\n"<<StempC<<", "<<StempS<<" "<<StempZ<<endl<<endl<<endl;

    cout<<"SHIP TO: "<<endl;
    cout<<RtempN <<endl;
    cout<<RtempA<<endl;
    cout<<RtempC<<", "<<RtempS<<" "<<RtempZ<<endl<<endl<<endl<<endl;    
}
void fileInputFunc ()
{
    int pause, weight;
    string pkgType, sName, sAdd, sCity, sState, sZip;
    string rName, rAdd, rCity, rState, rZip;
    double costPerOz, addPerOz, addFlatRate, costToShip;
    Person send, receive;
    
    ifstream fin ("package.txt");
    fin>> pkgType;
    while(!fin.eof())
    {        
        if( pkgType == "p" || pkgType  == "P")
        {
            fin>>weight>>costPerOz>>sName>> sAdd>> sCity>> sState>> sZip>> rName>> rAdd >> rCity>> rState>> rZip;
            costToShip=weight*costPerOz;
        }
        else if( pkgType == "O" || pkgType  == "o")
        {
            fin>>weight>>costPerOz>>sName>> sAdd>> sCity>> sState>> sZip>> rName>> rAdd >> rCity>> rState>> rZip>>addFlatRate;
            costToShip=weight*costPerOz+addFlatRate;
        }
        else if( pkgType == "T" || pkgType  == "t")
        {
            fin>>weight>>costPerOz>>sName>> sAdd>> sCity>> sState>> sZip>> rName>> rAdd >> rCity>> rState>> rZip>>addPerOz;
            costToShip=weight*(costPerOz+addPerOz);
        }

        send.setName(sName);
        send.setAdd(sAdd);
        send.setCity(sCity);
        send.setState(sState);
        send.setZip(sZip);

        receive.setName(rName);
        receive.setAdd(rAdd);
        receive.setCity(rCity);
        receive.setState(rState);
        receive.setZip(rZip);

        Person* sendPtr=new Person;
        Person* receivePtr= new Person;
        sendPtr=&send;
        receivePtr=&receive;

        labelFunc(send, receive, costToShip);
        fin>>pkgType; 
    }
}