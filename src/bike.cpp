#include "./bike.h"
using namespace std;

Bike::Bike(void){
    this->station=0;
    this->bikeT=0;
    this->bikeID=0;
    this->rentalP=0;
    this->rentalC=0;   
    this->prevArrive=0;
}

Bike::Bike(int station, int bikeT, int bikeID, float rentalP, int rentalC){
    this->station=station;
    this->bikeT=bikeT;
    this->bikeID=bikeID;
    this->rentalP=rentalP;
    this->rentalC=rentalC;
    this->prevArrive=0;
}

Bike::Bike(const Bike& obj){
    this->station = obj.station;
    this->bikeT = obj.bikeT;
    this->bikeID = obj.bikeID;
    this->rentalP = obj.rentalP;
    this->rentalC = obj.rentalC;
    this->prevArrive=0;
}

Bike Bike::operator=(Bike const&obj){
    Bike temp;
    temp.station=obj.station;
    temp.bikeT=obj.bikeT;
    temp.bikeID=obj.bikeID;
    temp.rentalP=obj.rentalP;
    temp.rentalC=obj.rentalC;
    return temp;
}




