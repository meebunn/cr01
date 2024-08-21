#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int s, int t) {
    stack<int> st;

    st.push(s);
    visited[s] = true;

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (current == t) {
            return true;
        }

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+2);
    vector<bool> visited(n, false); 

    for (int i = 0; i < m; i++) {
        char x ; 
        cin >> x ; 
        int y, z;
        cin >> y >> z;

        if( x == 'c'){
            adj[y].push_back(z);
            adj[z].push_back(y);
        }
        else if ( x == 'q'){
          
            fill(visited.begin(), visited.end(), false);
            bool r = dfs(adj, visited, y, z);
            cout << (r ? "yes" : "no") << endl;
        }
    }

    return 0;
}
