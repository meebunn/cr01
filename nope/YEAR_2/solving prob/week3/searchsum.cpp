#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a(100100);

int main() {
    int x, y;
    cin >> x >> y;
    int r = 0;

    for (int i = 0; i < x; i++) {
        cin >> a[i];
        a[i] += r;
        r = a[i];
    }

    for (int i = 0; i < y; i++) {
        int data;
        cin >> data;
        int idx = upper_bound(a.begin(), a.begin() + x, data) - a.begin();
        cout << idx <<endl ;
    }

    return 0;
}