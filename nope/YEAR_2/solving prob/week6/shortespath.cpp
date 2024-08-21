#include <bits/stdc++.h>

using namespace std;

const int max_n = 100010;
vector<int> adj[max_n];
vector<int> weight[max_n];
set<pair<int, int>> min_q;

int d[max_n];
bool explore[max_n];

int main() {
    int n, m;
    cin >> n >> m;
    const int INF = 100000000;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        weight[x].push_back(w);
        weight[y].push_back(w);
    }

    for (int i = 0; i < n; i++) {
        d[i] = INF;
        explore[i] = false;
    }

    d[0] = 0;
    min_q.insert(make_pair(0, 0)); 

    int total = 0; 

    while (!min_q.empty()) {
        auto it = *(min_q.begin());
        int node = it.second;
        min_q.erase(it);
        if (explore[node])
            continue;
        explore[node] = true;

        total += d[node]; 

        for (int i = 0; i < adj[node].size(); i++) {
            int v = adj[node][i];
            int w = weight[node][i];
            if (!explore[v] && w < d[v]) {
                d[v] = w;
                min_q.insert(make_pair(d[v], v));
            }
        }
    }

    cout << total ;

    return 0;
}
