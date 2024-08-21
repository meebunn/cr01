#include <bits/stdc++.h>

using namespace std;
int parent[100100] ; 
int nchild[100100] ; 

int find(int i) {
    if(parent[i] == i) {
        return i ;
    }
    else{
        return find(parent[i]) ; 
    }
}

void union_set(int i , int j) {
    int x = find(i) ; 
    int y = find(j) ; 
    if(x == y ) return ; 

    if(x != y) {
        if(nchild[x]>=nchild[y]){
            parent[y] = x; 
            nchild[x] += nchild[y] ;
        }
        else{
            parent[x] = y ;
            nchild[y] +=nchild[x] ; 

        }
        
    }
    
}

int main() {
    int n , m ; 
    cin >>  n>> m; 
    for(int i = 0 ; i<n ; i++){
        parent[i] = i  ;
        nchild[i] = 1 ; 
    }

    for(int i = 0; i <m ; i++){
        char x; 
        int y,z ; 
        cin >> x >>y >> z ; 

        if(x ==  'c') {
            union_set(y,z) ; 
        }
        else if( x == 'q') {
            cout << (find(y) == find(z) ? "yes" : "no") << endl ;
        }
    }
    return 0;
}