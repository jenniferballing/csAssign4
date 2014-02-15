#include "Package.h"
#include "Person.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include <fstream>

void labelFunc(Person &s, Person &r, string cost);
void fileInputFunc ();
int main()
{
    int pause=0;
    fileInputFunc();

    cin>>pause;
    return 0;
}

void labelFunc(Person &s, Person &r, string cost)
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

    cout<<"Testing, testing..."<<endl;
    
    cout<<StempA<<endl;
    cout<<StempC<<endl;
    cout<<StempS<<endl;
    cout<<StempZ<<endl;
    cout<<RtempN<<endl;
    cout<<RtempA<<endl;
    cout<<RtempC<<endl;
    cout<<RtempS<<endl;
    cout<<RtempZ<<endl;
    
    cout<<"Sender: "<<StempN <<endl;
    cout<<StempN<<"\n"<<StempC<<", "<<StempS<<" "<<StempZ<<endl<<endl;

    cout<<"Recipient: "<<RtempN <<endl;
    cout<<RtempA<<"\n"<<RtempC<<", "<<RtempS<<" "<<RtempZ<<endl<<endl;

    cout<<"Delivery Cost: "<< cost;    
}
void fileInputFunc ()
{
    int pause, weight;
    string pkgType, sName, sAdd, sCity, sState, sZip;
    string rName, rAdd, rCity, rState, rZip;
    double costPerOz, addPerOz, addFlatRate;
    Person send, receive;
    
    ifstream fin ("package.txt");
    
    fin>> pkgType;
    if( pkgType == "p" || pkgType  == "P")
    {
        fin>>weight>>costPerOz>>sName>> sAdd>> sCity>> sState>> sZip>> rName>> rAdd >> rCity>> rState>> rZip;
    }
    else if( pkgType == "O" || pkgType  == "o")
    {
        fin>>weight>>costPerOz>>sName>> sAdd>> sCity>> sState>> sZip>> rName>> rAdd >> rCity>> rState>> rZip>>addFlatRate;
    }
    else if( pkgType == "T" || pkgType  == "t")
    {
        fin>>weight>>costPerOz>>sName>> sAdd>> sCity>> sState>> sZip>> rName>> rAdd >> rCity>> rState>> rZip>>addPerOz;
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

    string cost="6*5=30";
    Person* sendPtr=new Person;
    Person* receivePtr= new Person;
    sendPtr=&send;
    receivePtr=&receive;

    labelFunc(send, receive, cost);
}