#include <bits/stdc++.h>

using namespace std;
int dp[20][100000] ; 
int cent[5] = {50,25,10,5,1} ;
int n ; 

int rec(int i , int remain){
    int x ,y ,k; 
    x = 0 ; 
    y =0 ; 

    if(i>=5){
        if(remain == 0 ){
            return 1 ;
        }
        else{
            return 0 ; 
        }
    }
    //mem
    if(dp[i][remain] != -1 ){
        return dp[i][remain] ; 
    }
    ///
    k = remain-cent[i] ; 
    if(k >= 0){
        x = rec(i,k) ; 
    }
    y = rec(i+1,remain) ; 
    
    return dp[i][remain] = x+y ; 

}
int main() {

    memset(dp,-1 ,sizeof(dp)) ;
    while(cin >> n) {
        memset(dp,-1 ,sizeof(dp)) ;
        cout << rec(0,n) ; 
    }

    return 0;
}