#include <bits/stdc++.h>

using namespace std;

long long n;
long long a[100100];
long long b[100100];
long long c[100100];
long long dp[100100];

long long rec(long long i) {

    if (i > n) 
        return 0;
    if (dp[i] != -1) 
        return dp[i];

    long long  maxx = INT_MIN;

    for (int j = 0; j <= 2; j++) {
        /// 3 cases
            long long val;

            if (j == 0) 
                val = rec(i + 1) + a[i];
            else if (j == 1) 
                val = rec(i + 2) + b[i];
            else 
                val = rec(i + 4) + c[i];

            maxx = max(maxx, val);
    }

    return dp[i] = maxx;
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (long long i = 1; i <= n; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        a[i] = x;
        b[i] = y;
        c[i] = z;
    }
    a[0] = 0;
    b[0] = 0;
    c[0] = 0;
    cout << rec(0) ;

    return 0 ; 
}
