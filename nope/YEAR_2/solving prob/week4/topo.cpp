#include <bits/stdc++.h>
#define MAX_NODE 100000
using namespace std;

vector<int> visited(MAX_NODE,0) ;  
vector<int> adj[MAX_NODE];


int main() {
    int v,e ; cin>> v >> e  ; 
    int c = 0 ;
    vector<int> inDG(v+1) ; 
    vector<vector<int>> adj(v+1) ; 
    while(e--){
        int x, y ; cin >> x >> y ; 
        adj[x].push_back(y) ; 
        inDG[y]++ ; 
        for(auto p : adj[y]){
            if( p == x) c=-1 ; 
        }
    }
    if(c == -1 ) cout << "no" ;
    else {
        //bfs 
        queue<int> q ; 

        for(int i = 1 ; i <=v ;i++){
            if(inDG[i] == 0 ) q.push(i);
        }
        while(!q.empty()){
            int crr = q.front() ; 
            q.pop() ; 
            cout << crr << endl ; 
            for(auto g : adj[crr]){
                inDG[g]-- ; 

                if(inDG[g] == 0 && !visited[g]) {
                    q.push(g) ; 
                    visited[g] = 1 ; 
                }
            }
        }

    }
}