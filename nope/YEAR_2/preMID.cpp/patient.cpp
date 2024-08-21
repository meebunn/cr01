#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> still(100000);
    vector<int> fine(100000);

    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int c;
        cin >> c;

        if (c == 0) {
            still[i] = still[i] + still[i - 1] - fine[i];
        } else {
            while (c--) {
                int num_patient, days;
                cin >> num_patient >> days;
                still[i] += num_patient;
                fine[i + days] += num_patient;
            }

            still[i] = still[i] + still[i - 1] - fine[i];
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << still[i] << endl; 
    }

    return 0;
}
