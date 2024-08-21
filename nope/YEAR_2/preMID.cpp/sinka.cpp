#include <bits/stdc++.h>

using namespace std;

vector<list<int>> adj(100000);
vector<int> visited(100000);

int bfsLayerCount(int start, int destination) {
    queue<int> q;
    fill(visited.begin(), visited.end(), 0); 
    q.push(start);
    visited[start] = true;
    if(start == destination) return 0 ; 
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

    return -1 ;  
}

int main() {
    int n, m, s, v;
    cin >> n >> m >> s >> v; 

    vector <int> start (s) ; 
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0 ; i<s ; i++) cin >> start[i] ; 
    
    for(int i = 0 ; i<v ; i++) {
        int d ; cin >> d ; 

        int min = 10000000 ; 
        int k  ; 
        for(int j = 0 ; j<s ;j++) {
            k = bfsLayerCount(start[j],d) ; 
            if(k<min) min = k ;
        }   
        cout << min << endl ; 
    } 

    return 0;
}
