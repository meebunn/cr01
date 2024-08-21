#include <bits/stdc++.h>

using namespace std;
int n , m , si , sj , ei , ej ;

int main() {
    cin >> n >> m >> si >> sj >> ei >> ej ; 
    int mymap[n+1][m+1] ;
    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= m ;j++) {
            cin >> mymap[i][j] ; 
        }
    }

    int label1 = mymap[si][sj] ; 
    int label2 = mymap[ei][ej] ; 
    
    return 0;
}