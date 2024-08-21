#include <bits/stdc++.h>
#define MAXX 100
#define INTMAXX 9999999999
using namespace std;

int main() {
    int n, m ; cin >> n >> m ; 
    int a,b,w ; 
    bool visited[n] ; 

    vector<pair<int,int>> adj [MAXX] ; 
    ////create graph
    for(int i = 0  ; i<m ; i++) {
        cin >>a >> b >> w;  
        adj[a].push_back(make_pair(b,w)) ;
        adj[b].push_back(make_pair(a,w)) ;
    }   




    return 0;
}