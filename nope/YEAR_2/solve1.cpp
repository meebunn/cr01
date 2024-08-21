#include <bits/stdc++.h>

using namespace std;

int main() {
    int n , k , l ; cin >> n >> k >> l ; 
    vector<int> h ; 
    for(int i = 0 ; i< n ;i++){
        int d ; cin >> d ; 
        h.push_back(d) ; 
    }
    sort(h.begin(), h.end());
    // for(auto j : h) cout << j <<" " ; 

    int max = -1 ; 
    int dis = 0 ;
    for(int i = 0 ; i<n ; i++){
        if(i+k+l<n) {
            dis = h[i+k+l]- h[i] ; 
            if(dis>max) max = dis ;  
        }
    }
    cout << max ; 
    return 0;

}