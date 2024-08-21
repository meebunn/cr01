#include <bits/stdc++.h>

using namespace std;
int v[100100] ; 
int w[100100] ;
int c[1001001] ;

int main() {
    int ts ; 
    cin >> ts  ; 
    while(ts--){
        int n; cin >>n ; 
        for(int i =0 ; i <n ;i++){
            int x, y ; 
            cin >> x >> y ;
            v[i] = x ; 
            w[i] = y ;        
        }
        int num_p ; 
        cin >> num_p ; 
        for(int i = 0 ; i<num_p; i++) {
            int z ; 
            cin >> z; 
            c[i] = z ;
        }
        
    }
    return 0;
}