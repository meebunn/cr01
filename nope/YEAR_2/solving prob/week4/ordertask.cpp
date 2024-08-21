#include <bits/stdc++.h>
#define MAX_NODE 100100 
using namespace std;

vector<vector<int>> adj(MAX_NODE); 
vector<int> inDG(MAX_NODE);
vector<int> visited(MAX_NODE);

int main() {
    while (1) {
        int v, e;
        cin >> v >> e;
        if (v == 0 && e == 0) break;

        // Reset vectors for the new test case
        fill(adj.begin(), adj.end(), vector<int>());
        fill(inDG.begin(), inDG.end(), 0);
        fill(visited.begin(), visited.end(), 0);

        while (e--) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            inDG[y]++;
        }

        queue<int> q;

        for (int i = 1; i <= v; i++) {
            if (inDG[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int crr = q.front();
            q.pop();
            cout << crr << " ";
            for (auto g : adj[crr]) {
                inDG[g]--;

                if (inDG[g] == 0 && !visited[g]) {
                    q.push(g);
                    visited[g] = 1;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
