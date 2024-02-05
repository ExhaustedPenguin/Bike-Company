#include "./vectors.h"
//#include "./user.h"
#include<iostream>

using namespace std;

template <class T>
vectors<T>::vectors(){
    this->arr=new T;
    this->curr=0;
    this->capacity=1;
}

template <class T>
vectors<T>::vectors(const vectors&obj){
    this->curr=obj.curr;
    this->capacity=obj.capacity;
    this->arr=new T[capacity];
    for(int i=0; i<obj.size; i++){
        arr[i]=obj.arr[i];
    }
}

template <class T>
void vectors<T>::insertHead(T data){
    if(curr==capacity){
        T* temp=new T[2*capacity];
        for(int i; i<capacity; i++){
            temp[i]=arr[i];
        }
        delete []arr;
        capacity*=2;
        arr=temp;
        arr[curr]=data;
    }
    arr[curr]=data;
    curr++;
}

template <class T>
T vectors<T>::Pop(){
    curr--;
    return *arr[curr];
}

template <class T>
void vectors<T>::remove(int idx){
    if(curr==idx){
        curr--;
        return;
    }
    for(int i=0; i<curr-idx-1; i++){
        arr[idx+i]=arr[idx+1+i];
    }
    curr--;
    return;
}





