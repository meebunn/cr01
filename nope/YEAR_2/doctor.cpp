#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, m, l;
vector<int> adj[100100];
vector<int> weight[100100];
int numpp[100100];
int dist[100100];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            int w = weight[u][i];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m >> l;

    for (int i = 0; i < n; i++) {
        cin >> numpp[i + 1];
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weight[a].push_back(c);
        weight[b].push_back(c);
    }

    dijkstra(1);
    int sum= 0 ; 
    
    for (int i = 1; i <= n; i++) {
        if(numpp[i] > l ){
            sum+= l*dist[i] ; 
        }
        else{
            sum+= numpp[i]*dist[i] ; 
        }
    }
    cout << sum   << endl ;
    return 0;
}
