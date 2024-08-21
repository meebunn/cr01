#include <bits/stdc++.h>

using namespace std;

bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int r, l ;
    cin >> r >> l ; 
    int pre=-10 , cur=-10  ; 
    int num= 0 ; 
    bool f1 =true ; 
    bool vst[200200] ; 
    /// [3, 5 , 7 , 9] //
    // pre = 3 cur = 5  pre = 7 ; 
    for(int i = r ; i <= l ; i++) {
        if(is_prime(i) && f1){
            pre =  i ;
            if(pre-cur == 2){
                // cout << pre << " " << cur ; 
                num++ ; 
            }
            // cout <<endl; 
            f1 = false ; 
        }
        else if(is_prime(i) && !f1) {
            cur = i ; 
            if(cur-pre == 2 ) {
                // cout << pre <<" "<<  cur ; 
                num++ ; 
            }
            // cout << endl ; 
            f1 = true ; 
        }
    }
    cout << num ; 
    return 0;
}