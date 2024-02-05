#include<iostream>
//#include "./bike.h"
using namespace std;

template <class T>
class vectors {
    public:
        T*  arr;
        int curr;
        int capacity;

        vectors();
        void insertHead(T data);
        T Pop();
        void remove(int idx);
        vectors(const vectors&obj); 
};

