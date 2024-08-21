#include <bits/stdc++.h>

using namespace std;
int a[100][100];
double dp[100][100]; 
int n, m, num ;
int res_min = INT_MAX ; 
int diff = INT_MAX ; 
void f() {

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            num = 0 ;
            for (int l = 0; l < m; l++) {
                if (l != j) {
                    dp[i][j] += abs(a[i][j] - a[i][l]);
                    num++;
                }
            }

            for (int k = 0; k < n; k++) {
                if (k != i) {
                    dp[i][j] += abs(a[i][j] - a[k][j]);
                    num++;
                }
            }
            dp[i][j] /= num ; 

        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    f(); // call f
    
    // cout << endl ;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(dp[i][j] < diff){
                res_min = a[i][j] ; 
                diff = dp[i][j] ; 
            }
        }
    }

    cout << res_min ; 
    return 0;
}
