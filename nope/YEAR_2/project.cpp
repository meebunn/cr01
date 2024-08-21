#include <bits/stdc++.h>

using namespace std;  

int bfs(map<int, vector<int>>& adj, int start) {
    queue<int> q;
    map<int, int> visited;
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
    int n, m, k ;
    cin >> n >> m >> k ;
     
    return 0;
}