#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100100];
int b[100100];
int dp[100100];

int f(int i) {
    if (i > n)
        return 0;
    if (dp[i] != -1) {
        return dp[i];
    }

    int maxx = b[i];
    for (int j = i + 1; j <= n; j++) {
        // Find max
        if (a[i] - a[j] <= 4 && a[i] - a[j] >= 0) {
            maxx = max(maxx, b[i] + f(j));
        }
       
    }

    return dp[i] = maxx;
}

int main() {
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    a[0] = 0;
    b[0] = 0;

    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        res = max(res,f(i));
    }
    cout << res << endl  ;
    
    // for(int i = 0 ; i <=n ; i++){
    //     cout << dp[i] << " "  ; 
    // }

    return 0;
}
