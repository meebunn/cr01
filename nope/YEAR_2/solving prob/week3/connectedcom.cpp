#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

void dfs(int p) {
    mark[p] = true;
    cout << p+1 << endl;
    for(int q: adj[p]) {
        if (!visited[q]) {
            dfs(q);
        }
    }
}

int main(){
    int v , e ; cin >> v >> e ;  
    vector<vector<int>> adj (v);
    vector<bool> mark(v,false) ; 

    for(int i = 0 ; i < e ; i ++){
        int x , y ; cin >> x >> y ;
        adj[x].push_back(y) ; 
        adj[y].push_back(x); 
    } 
    
    for(int i = 0 ; i < v ; i++){
        if(!mark[i]){
            dfs(i) ; 
        }
    }
}