#include <bits/stdc++.h>
using namespace std;

int v[2010] ;
int w[2010] ; 
int dp[2010][35] ;
int n; 
int x ;
int f(int i , int j) {

    if(i == x  ) 
        return 0  ;

    if(dp[i][j] != -1) {
        return dp[i][j] ; 
    }

    int ns = f(i+1,j) ; 
    int s = INT_MIN ; 
    if(j >=w[i]){
         s = f(i+1,j-w[i]) + v[i] ; 
    }

    return dp[i][j] = max(ns,s) ; 

} 

int main() {

    cin >> n ;
    for(int i = 0 ; i<n ;i++){
        cin >> x ; 
        for(int i = 0 ; i<x ; i++){
            int prc,wght ; 
            cin >>prc >>wght  ;
            v[i] = prc; 
            w[i] = wght ; 
        }
        int person,w ; 
        cin >>person ; 
        int sum = 0 ;
        for(int i = 0 ; i<person ;i++){
            cin >> w ; 
            memset(dp,-1,sizeof(dp)); 
            sum+=f(0,w) ;
        }


        cout << "OUTPUT : " <<  sum <<endl ; 
    }
    
    return 0;
}