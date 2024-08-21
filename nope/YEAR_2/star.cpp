#include <bits/stdc++.h>

using namespace std;
int a[100100]; 
int b[100100] ;
int dp[100100][3] ;
int n ; 

int f(int i,int k  ) {

    if(i>n) {
        return 0 ; 
    }
    if(dp[i][k] !=-1) {
        return dp[i][k] ; 
    }
    int maxx = INT_MIN ;
    int t1= INT_MIN , t2 = INT_MIN , t3 = INT_MIN  ;
    
    t1 = f(i+1,0) ; /// mai 

    if(k!= 1) {
        t2  = f(i+1,1)+a[i] ; 
    }
    if(k!= 2) {
        t3 = f(i+1,2) +b[i] ; 

    }
    maxx = max({t1,t2,t3})  ;

    return dp[i][k] = maxx ; 

}
int main() {

    cin >> n ;
    memset(dp,-1,sizeof(dp)); 
    for(int i = 1 ; i<=n ;i++){
        int x, y ; 
        cin >> x  >> y ; 
        a[i] = x ;
        b[i] = y ; 
    }

    cout << f(0,0) << endl ; 
    return 0;
}