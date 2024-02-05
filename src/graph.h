#include<iostream>
using namespace std;

class Graph{
    public:
        int dist[1003][1003];
        int shortest[1003][1003];
        int n;

        Graph();
        void CalculateShort();
};