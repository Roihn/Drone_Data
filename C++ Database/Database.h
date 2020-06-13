#ifndef DATABASE
#define DATABASE
using namespace std;
#include <string>

const unsigned int MAX_HOSPITAL=100;
const unsigned int MAX_ORDERS=100;

struct hospital{
    string name;
    string address;
    string phoneNumber;
};
struct orders{
    hospital receiver;
    string pickUpTime; //eg. 19:30
    float weight; //in kg
    string typeOfDelivery;
};

void printHospital(hospital & h);
void printOrder(orders & o);
void initialize(hospital & userHospital);
void addHospital(hospital * hlist, int & hnum);
int findHospital(string name,hospital * hlist, int hnum);
void order(orders *olist,int onum, hospital *h, int hnum, string name, string pickuptime, float weight, string type);



#endif // Database
