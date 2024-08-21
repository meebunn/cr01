#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int MAX_SIZE = 100100;
    vector<int> mor(MAX_SIZE);
    vector<int> eve(MAX_SIZE);

    while (1) {
        int n, d, r;
        cin >> n >> d >> r;

        if (n == 0 && d == 0 && r == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> mor[i];

        for (int i = 0; i < n; i++)
            cin >> eve[i];

        sort(mor.begin(), mor.begin() + n);
        sort(eve.begin(), eve.begin() + n, greater<int>());

        int exc = 0;


        for (int i = 0; i < n; i++) {
            int k = mor[i] + eve[i] - d;
            if (k > 0)
                exc += k;
        }

        cout << exc * r << endl;
    }

    return 0;
}
