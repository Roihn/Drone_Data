#include <fstream>
#include <string>
#include <iostream>
#include "Database.h"
#include <cstdlib>
#include <sstream>
/*
    1. Sending Goods
        Input: Hospital address, type of goods (eg. blood samples), time
    2. Information of Hospital (Initialize-set up one time, no need to do it again) (Logfile Setup)
        Capacity (eg. how many blood samples it can send), name, address, contact number,
*/

int main(){
    ///Initialize
    //sender hospital
    hospital h = {};
    initialize(h);
    printHospital(h);

    //add hospitals
    hospital hlist[MAX_HOSPITAL]={};
    int hlistSize=0;
    addHospital(hlist, hlistSize);

    ///Order Log
    //open log file
    ifstream bucky;
    bucky.open("log");
    if(!bucky.is_open()){
        cerr<<"order not open";
        exit(EXIT_FAILURE);
    }
    //fill order list
    orders olist[MAX_ORDERS];
    int olistSize = 0;
    while(bucky.good()){
        string line;
        getline(bucky,line);
        if(line.substr(0,5)=="order"){ //order hospital_name, time, weight, type
            istringstream iStream;
            string hospital_name;
            string time;
            float weight;
            string type; //eg. blood sample

            iStream.str(line);
            string command;
            iStream>>command>>hospital_name>>time>>weight>>type;

            //Store to order list
            order(olist,olistSize,hlist,hlistSize,hospital_name,time,weight,type);
            olistSize++;

        }
    }
}



//Effect: Initializes input hospital's information
//Modify: input hospital's name, address, number
void initialize(hospital & h){
    //1. open file
    ifstream bucky;
    bucky.open("hospital info");
    if(!bucky.is_open()){
        exit(EXIT_FAILURE);
    }

    //2. read file (name -> address -> phoneNumber)
    getline(bucky,h.name);
    getline(bucky,h.address);
    getline(bucky,h.phoneNumber);
    cout<<">> User Hospital Initialized"<<endl;
    printHospital(h);
}

void printHospital(hospital & h){
    cout<<"\tName: "<<h.name<<endl<<"\tAddress: "<<h.address<<endl<<"\tPhone number: "<<h.phoneNumber<<endl;
}

void printOrder(orders & o){
    cout<<"\tName: "<<o.receiver.name<<endl<<"\tType: "<<o.typeOfDelivery<<endl<<"\tWeight: "<<o.weight<<endl<<"\tPickup Time: "<<o.pickUpTime<<endl;
}

void addHospital(hospital * hlist, int & hnum){
    cout<<">> Add Hospitals"<<endl;
    //open file
    ifstream bucky;
    bucky.open("hospital list");
    if(!bucky.is_open()){
        exit(EXIT_FAILURE);
    }
    //add hospitals
    while(bucky.good()){
        getline(bucky,hlist[hnum].name);
        getline(bucky,hlist[hnum].address);
        getline(bucky,hlist[hnum].phoneNumber);
        printHospital(hlist[hnum]);
        cout<<endl;
        hnum++;
    }
}

//Effect: return index of hospital in hlist
int findHospital(string name,hospital * hlist, int hnum){
    for(int i=0;i<hnum;i++){
        if(hlist[i].name==name){
            return i;
        }
    }
    return 0;
}

//Stores orders in order array
//Input: index of order list to add to
void order(orders *olist,int onum, hospital *h, int hnum, string name, string pickuptime, float weight, string type){
    cout<<">> Orders"<<endl;
    int index = findHospital(name,h,hnum);
    olist[onum].receiver = h[index];
    olist[onum].pickUpTime = pickuptime;
    olist[onum].typeOfDelivery = type;
    olist[onum].weight = weight;
    printOrder(olist[onum]);
}
