#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;


int main() {
    vector<int> d (100100) ; 
    vector<int> v (100100) ; 
    int n ; cin >> n  ;
    for(int i =0 ;i<n ; i++){
        cin >> d[i+1] ; 
    }
    v[1]=0;
    v[2]=0;
    v[3] =d[3];
    for(int i =4;i<=n;i++){
        int ns = v[i-1]; 
        int s = v[i-3] +d[i] ; 

        int k = max(ns,s) ; 
        v[i] = k ;
    }
    cout << v[n] ; 
}
/*
12
1
2
5
4
3 0 6 1 2 7 2 1
*/