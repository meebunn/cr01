#include <bits/stdc++.h>

using namespace std;

int main() {
    #include <bits/stdc++.h>
#define minmax -99999999 
using namespace std;
int n;
int a[200100];
int b[200100];
int dp[200100];

int recur(int i){
   
    if (i > n){
        return 0 ; 
    }
    if(dp[i]!= -1) {
        return dp[i] ; 
    }
    
    int maxx = INT_MIN ; 
    for (int j = 1; j <= 4; j++)
    {
        maxx = max(maxx, recur(i + j) + a[i]);
        if(b[i+j] == 1) break ;
    }
    
    dp[i] = maxx ;

    return dp[i] ;
}

int main()
{
    cin >> n;

    memset(dp, -1, sizeof(dp));
    a[0] = 0 ; 
    b[0] = 0 ; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i+1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i+1];
    }

    int v = recur(0) ; 
    cout << v;  
    

}
    return 0;
}