#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 2048;
const int MAX_P = 309;
const int MAX_K = 16;
int n, k;
long long nWays[MAX_N][MAX_K][MAX_P];
int prime[MAX_P];

void sieve() {
    memset(prime, 0, sizeof(prime));
    prime[0] = prime[1] = true;
    for (int i = 2; i < MAX_N; ++i) {
        if (!prime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                prime[j] = true;
            }
        }
    }
}

long long countWays(int n, int k, int i) {
    if (n == 0 && k == 0)
        return 1;
    if (n < 0 || k < 0 || prime[i] > n || i == MAX_P)
        return 0;
    if (nWays[n][k][i] != -1)
        return nWays[n][k][i];

    long long a = countWays(n - prime[i], k - 1, i + 1) ;
    long long b = countWays(n, k, i + 1) ;
    long long res = a + b ; 
    return nWays[n][k][i] =  res ; 
}

int main() {
    sieve();
    memset(nWays, -1, sizeof(nWays));
    while (cin >> n >> k && (n || k))
        cout << countWays(n, k, 0) << endl;
    return 0;
}
