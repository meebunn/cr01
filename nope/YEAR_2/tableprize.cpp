#include <bits/stdc++.h>

using namespace std;
int n, m , k ;
int a[220][220] ; 
int dp[220][220][220] ;

int f(int i ,int j, int k , int maxk ){

    if(j>=m && j <0) 
        return 0 ; 
    if(k >maxk)
        return 0  ;
    if(i>=n) 
        return 0 ; 

    if(dp[i][j][k]!=-1 ){
        return dp[i][j][k] ; 
    }
    int maxx  = INT_MIN ;
    int x = f(i+1,j,k,maxk) ; 
    int y = f(i+1,j+1,k+1,maxk) ; 
    int z = f(i+1,j-1,k+1,maxk) ; 
    maxx = max({x,y,z}) +a[i][j] ;
    
    return dp[i][j][k] = maxx ; 
}

int main() {

    cin >> n >>m >> k ; 
    memset(dp,-1,sizeof(dp)) ;  

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j <m ; j++){
            cin >> a[i][j] ; 
        }
    }
    /// base case i = 0 ; 
    int res = INT_MIN ; 
    for(int j = 0 ; j <n ;j++){
        res = max(res, f(0, j, 0, k));
    }
    
    cout << res ; 





    return 0;
}