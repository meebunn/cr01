#include <iostream>
#include <vector>
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
    
    int n;  
    cin >> n; 
    for(int i = 1 ; i<=n ; i++){
        int x ; 
        cin >> x  ;
        adj[i].push_back(x) ;
        adj[x].push_back(i) ; 
    }
    int num = 0; 
    for(int i = 1  ; i <=n ; i++){
        if(!visited[i]){
            dfs(i) ; 
            num++ ; 
        }
       
    }
    cout << num ; 
}