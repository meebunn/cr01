#include <bits/stdc++.h>

using namespace std;

int main() {
    int r,c,b,t;
    int a[20] ; 
    cin >> r >> c >> b >> t;  
    memset(a , 0 , sizeof(a)) ; 

    for(int i = 0 ; i< r ; i++) {
        for(int j= 0  ; j< c ;j++){
            int d;  
            cin >> d; 
            a[i] += d ; 
        }
    }
    int unit = b/t ; 
    int sum = 0  ; 
    for(int i = 0 ; i<r ; i++) {

        if(a[i] == 0 ) continue ; 

        sum += ceil((float)a[i]/unit) ; 
        
    }
    cout << sum ; 
    
    return 0;
}