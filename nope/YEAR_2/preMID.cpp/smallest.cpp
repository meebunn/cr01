#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> dd(x);
    vector<int> data(x);
    vector<int> prefixSum(x);
    int min = INT_MAX;

    for (int i = 0; i < x; i++) {
        int n;
        cin >> n;
        dd[i] = n;
        if (n < min) {
            min = n;
        }
        data[i] = min;
        prefixSum[i] = i > 0 ? prefixSum[i - 1] + (dd[i] > n) : (dd[i] > n);
    }

    while (y--) {
        int m, n;
        cin >> m >> n;
        if (m == 1) {
            cout << data[n - 1] << endl;
        } else if (m == 2) {
            int index = lower_bound(prefixSum.begin(), prefixSum.end(), n) - prefixSum.begin();
            cout << index << endl;
        }
    }

    return 0;
}
