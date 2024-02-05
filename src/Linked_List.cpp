#include <iostream>
#include "./Linked_List.h"

using namespace std;

void SortBike(node** headRef);
node* SortedMerge(node* a, node* b);
void FrontBackSplit(node* source,node** frontRef, node** backRef);

node::node(void){
    Bike data();
    next=NULL;
}

node::node(int station, int bikeT, int bikeID, float rentalP, int rentalC){
    this->data.station = station;
    this->data.bikeT = bikeT;
    this->data.bikeID = bikeID;
    this->data.rentalP = rentalP;
    this->data.rentalC = rentalC;    
    next=NULL;
}

linkedList::linkedList(void){head=NULL;}

int linkedList::insertNode(int station, int bikeT, int bikeID, float rentalP, int rentalC){
    node* temp = new node(station, bikeT, bikeID, rentalP,  rentalC);
    if(this->head==NULL){
        this->head=temp;
        head->next=NULL;
    }
    else{
        node* oldhead=head;
        this->head=temp;
        this->head->next=oldhead;
    }
    return temp->data.bikeID;
}

node* linkedList::deleteHead(void){
    if(head==NULL){
        return NULL;
    }
    node* temp=head->next;
    node* trash=head;
    if(temp!=NULL){
        this->head=temp;
    }
    else{
        this->head==NULL;
    }
    return trash;
}

void linkedList::printList(void){
    node* temp=this->head;
    while(temp){
        cout<<temp->data.bikeID<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void linkedList::movedHead(node* move){
    node* temp=this->head;
    if(head!=NULL){
        head=move;
        head->next=temp;
    }
    else{
        head=move;
        head->next=NULL;
    }
}



void SortBike(node** headRef)
{
    node* head = *headRef;
    node* a;
    node* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    SortBike(&a);
    SortBike(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
 
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
node* SortedMerge(node* a, node* b)
{
    node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data.rentalP > b->data.rentalP) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else if(a->data.rentalP < b->data.rentalP){
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    else {
        if (a->data.bikeID < b->data.bikeID) {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else{
            result = b;
            result->next = SortedMerge(a, b->next);            
        }
    }
    return (result);
}
 
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(node* source,node** frontRef, node** backRef)
{
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
 