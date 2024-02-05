#include <iostream>
using namespace std;

class User{
    public:
    int userID;
    int accBike[51];
    int startT;
    int endT;
    int startP = 0;
    int endP;
    int accBiken;
    int accept=0;
    int arriveT=0;
    int revenue=0;
    int bikeIDacc=0;
    User(int userId, int accBike[51], int startT, int endT, int startP, int endP, int accBiken);
    User operator=(User const&obj);
    User();
    void printAccBike(void);

};


void sortArray(User arr[], int n);
void merge(User arr[], int l, int m, int r);