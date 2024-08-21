#include <bits/stdc++.h>

using namespace std;

void dfs(int start, vector<list<int>>& data, vector<int>& visited) {
    cout << start << " ";
    visited[start] = 1;

    for (auto neighbor : data[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor, data, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<list<int>> data(n + 1);
    vector<int> dg(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        data[y].push_front(x);
        dg[x] = 1;
    }

    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (dg[i] == 0) {
            start = i;
            break;
        }
    }

    vector<int> visited(n + 1, 0);
    dfs(start, data, visited);

    return 0;
}
