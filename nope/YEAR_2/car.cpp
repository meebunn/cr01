#include <bits/stdc++.h>

using namespace std;
int n;
int a[200200] ;
int b[200200] ; 

int f() {
    int num=0 ; 
    int maxx  = b[n] ; 
    for(int i = n-1 ; i>0 ; i--) {
        if(b[i] < maxx) {
            num++ ; 
        }
        else if(b[i] > maxx){
            maxx = b[i] ; 
        }
    }
    return num  ; 
}
int main() {
    cin >>n  ;
    memset(b,-1,sizeof(b)) ;

    for(int i = 1 ; i<=n ;i++) {
        cin >> a[i] >> b[i] ; 
    }

    int res  = f() ; 
    cout << res; 
    return 0;
}