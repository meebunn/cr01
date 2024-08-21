#include <bits/stdc++.h>

using namespace std;

int dp[220][350][350];
int n;
int a[200] ; 

int f(int i,int j,int k){
    if(i<=0){
        if(j == k)
            return 0;
        else
            return -333;

    }

    if(dp[i][j][k]!= -1) 
        return dp[i][j][k] ; 

    int b1 = f(i-1,j,k) ; 
    int b2 = a[i]+f(i-1,j-a[i],k) ;
    int b3 = a[i]+f(i-1,j,k-a[i]) ; 
    
    return dp[i][j][k] = max({b1,b2,b3}); 


}

int main() {
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i] ; 
    }

    a[0] = 0;
    memset(dp, -1, sizeof(dp));
    int ss = f(n,0,0)/2;
    cout << (ss ? ss : 0) ; 

}