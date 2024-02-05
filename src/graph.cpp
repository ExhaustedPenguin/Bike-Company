#include<iostream>
#include "graph.h"
using namespace std;

Graph::Graph(){
    fill(&dist[0][0], &dist[1002][1002], 99999999);
}
void Graph::CalculateShort(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            shortest[i][j]=dist[i][j];
            if(i==j){
                shortest[i][j]=0;
            }
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((shortest[i][k]+shortest[k][j])<shortest[i][j])
                    shortest[i][j] = shortest[i][k] + shortest[k][j]; 
            }
        }
    }
}