#include <iostream>
using namespace std;

class Bike{
    public:
    int station;
    int bikeT;
    int bikeID;
    float rentalP;
    int rentalC;
    int prevArrive;
    Bike(void);
    Bike(int station, int bikeT, int bikeID, float rentalP, int rentalC);
    Bike(const Bike&obj); //copy constructor
    Bike operator=(Bike const&obj);
};