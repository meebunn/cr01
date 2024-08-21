#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<long long, long long> track;

int main() {
    int x;
    cin >> x;

    while (x--) {
        int a;
        cin >> a;

        if (a == 1) {
            long long b, c;
            cin >> b >> c;
            track[b] = c;
        } else if (a == 2) {
            long long b;
            cin >> b;
            cout << track[b] << endl;
        } else if (a == 3) {
            long long b, c;
            cin >> b >> c;
            cout << min(track[b], c) << endl;
            track[b] = max(0LL, track[b] - c);
        }
    }

    return 0;
}
