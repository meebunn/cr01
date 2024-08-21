#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXX 300300

using namespace std; 

vector<int> adj[MAXX] ; 
bool visited[MAXX] ; 


void dfs(int s) {
    visited[s] = true ; 
    for(auto j :adj[s] ){
        if(!visited[j]) {
            dfs(j) ; 
        }
    }
}
int main(){
    int v , e ;
    cin >> v >> e ; 
    int num=0 ;
    for(int i = 0 ; i<e ; i++){
        int x ,y ; cin >> x >> y ; 
        x-- ; y-- ; 
        adj[x].push_back(y) ; 
        adj[y].push_back(x) ; 
    }

    for(int i = 0  ; i < v ; i++){
        if(!visited[i]){
            dfs(i) ; 
            num++ ; 
        }
       
    }
    cout << num ; 
}