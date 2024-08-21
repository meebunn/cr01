#include <bits/stdc++.h>

using namespace std;

double dis(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void createADJ(vector<pair<int, int>>& inp, vector<vector<size_t>>& adj, int n, int jump) {
    inp.push_back(make_pair(0, 0));

    for (int i = 1; i <= n - 2; i++) {
        int x, y;
        cin >> x >> y;
        inp.push_back(make_pair(x, y));
    }

    inp.push_back(make_pair(100, 100));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (i != j && dis(inp[i].first, inp[i].second, inp[j].first, inp[j].second) <= jump) {
                adj[i].push_back(j);
            }
        }
    }
}

int bfsLayerCount(vector<vector<size_t>>& adj, int start, int destination) {
    queue<int> q;
    vector<int> visited(adj.size(), 0);
    q.push(start);
    visited[start] = true;

    int layers = 0;

    while (!q.empty()) {
        int layerSize = q.size();  
        layers++;

        for (int i = 0; i < layerSize; i++) {
            int current = q.front();
            q.pop();

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);

                    if (neighbor == destination) {
                        return layers;
                    }
                }
            }
        }
    }

    return -1;  // No path found
}

int main() {
    int n, jump;
    cin >> n >> jump;
    n += 2;

    vector<pair<int, int>> inp;
    vector<vector<size_t>> adj(n);
    createADJ(inp, adj, n, jump);

    int layers = bfsLayerCount(adj, 0, n - 1);
    cout << layers << endl;

    return 0;
}
