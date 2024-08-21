#include <bits/stdc++.h>

using namespace std;
int n; 
int a[100100] ; 
int m[100100] ; 

int main() {
    cin >> n; 
    memset(m,0,sizeof(m)) ; 

    for(int i = 0 ; i<n ; i++){
        cin >> a[i] ; 
    }
    
    for(int i = 0 ; i< n ;i++) {
        int s= 0  ; 
        for(int j=i+1 ; j< n; j++){
            if(a[j] > a[i]){
                m[i]++ ; 
            }
        }
    }
    long long nf = 0 ; 
    for(int i = 0 ; i< n ;i++) {
        for(int j=i+1 ; j< n; j++){
            if(a[i] > a[j]){
                nf+= m[j] ; 
            }
        }
    }
    
    cout << nf ;
}

// 6
// 10
// 7
// 12
// 5
// 8
// 9
