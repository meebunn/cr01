#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> data;
    vector<pair<int, int>> cover;

    for (int i = 0; i < n; i++) {
        cout << endl;
        int m;
        cin >> m;
        data.clear();

        while (1) {
            int x, y;
            cin >> x >> y;
            if (x == 0 && y == 0) break;
            data.push_back(make_pair(y, x));
        }

        sort(data.begin(), data.end());
        reverse(data.begin(), data.end());

        int minValue = 100000;
        int start, finish;
        for (auto p : data) {
            if (p.first <= m && abs(m - p.first) < minValue && p.second <= 0) {
                minValue = abs(m - p.first);
                start = p.second;
                finish = p.first;
            }
        }
        cover.push_back(make_pair(start, finish));

       
    return 0;
}
