#include<iostream>
#include "./user.h"
using namespace std;

User::User(int userId, int accBike[51], int startT, int endT, int startP, int endP, int accBiken){
    this->userID=userId;

    this->startT=startT;
    this->endT=endT;
    this->startP=startP;
    this->endP=endP;
    this->accBiken=accBiken;
    this->accept=0;
}

User::User(){
    this->userID=0;
    this->startT=0;
    this->endT=0;
    this->startP=0;
    this->endP=0; 
    this->accept=0;
    this->accBiken=accBiken;   
}

User User::operator=(User const&obj){
    userID = obj.userID;  
    startT = obj.startT;
    endT = obj.endT; 
    startP = obj.startP; 
    endP = obj.endP; 
    accBiken = obj.accBiken;
    return *this;
}

void merge(User arr[], int l, int m, int r);

void sortArray(User arr[], int n){
    int sizee;
    int left_start;
   for (sizee=1; sizee<=n-1; sizee = 2*sizee)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*sizee)
       {
           // Find ending point of left subarray. mid+1 is starting 
           // point of right
           int mid = min(left_start + sizee - 1, n-1);
  
           int right_end = min(left_start + 2*sizee - 1, n-1);
  
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
}


void merge(User arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    /* create temp arrays */
    User L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if(L[i].startT<R[j].startT){
            arr[k] = L[i];
            i++;
        }
        else if(R[j].startT<L[i].startT){
            arr[k] = R[j];
            j++;
        }
        else if(L[i].startT==R[j].startT){
            if(L[i].userID<R[j].userID){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void User::printAccBike(void){
    for(int i=0; i<30; i++){
        cout<<this->accBike[i]<<" ";
    }
}
