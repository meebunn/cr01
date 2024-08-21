#include <bits/stdc++.h>

using namespace std;
map<int, int> visited;

int bfs(map<int, vector<int>>& adj, int start) {
    queue<int> q;

    map<int, int> color;
    q.push(start);
    visited[start] = true;
    color[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                color[neighbor] = 3 - color[node];
                q.push(neighbor);
                visited[neighbor] = true;
            } else if (color[neighbor] == color[node]) {
                return -1;
            }
        }
    }

    return 1;
}

int main() {
    int v, e ;
    cin >> v >> e >> ;
    map<int, vector<int>> adj;

    int start = -1;
    for (int j = 0; j < e; j++) {
        int x, y;
        cin >> x >> y;
        if (start == -1)
            start = x;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    int k = bfs(adj, start);
    if (k == 1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;


    return 0;
}