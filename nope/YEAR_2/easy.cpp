#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string s1, s2;

int f() {

    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i; 
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; 
            else{ 
                int x = dp[i - 1][j - 1];
                int y = dp[i - 1][j];
                int z = dp[i][j - 1]; 
                dp[i][j] = 1 + min({x, y, z});
            }   
        }
    }

    return dp[m][n];
}

int main() {

    cin >> s1 >> s2;
    cout << f() ;

    return 0;
}
