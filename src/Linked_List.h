#include <iostream>
#include "./bike.h"

using namespace std;
class node
{
    public:
        Bike data;
        node* next;

        node(void);
        node(int station, int bikeT, int bikeID, float rentalP, int rentalC);

};

class linkedList{
    public:
        node* head;    
        linkedList(void);
        int insertNode(int station, int bikeT, int bikeID, float rentalP, int rentalC);
        node* deleteHead(void);
        void printList(void);
        void movedHead(node* move);
};

void SortBike(node** headRef);
node* SortedMerge(node* a, node* b);
void FrontBackSplit(node* source,node** frontRef, node** backRef);