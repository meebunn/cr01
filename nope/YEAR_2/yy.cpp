#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    cin >> c;
    for(int ts = 1 ; ts <=c ; ts++) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            s[i] = b[i] - a[i];
        }

        sort(s.begin(), s.end());

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] > 0) {
                sum += s[i];
            } else if (k != 0) {
                k--;
                continue;
            } else {
                sum += s[i];
            }
        }

        if (sum > 0) {
            cout <<"Case " << ts << ": " << sum << endl;
        } else {
            cout <<"Case " << ts << ": " << "No Profit" << endl;
        }
    }

    return 0;
}
