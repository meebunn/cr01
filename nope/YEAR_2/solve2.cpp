#include <bits/stdc++.h>

using namespace std;

int main() {
    int n , m ; cin >> n >> m ; 
    vector<int> boat_w  ; 
    vector<int> want(m) ; 
    int count= 0 ;
    for(int i = 0 ; i<n ; i++) {
        int d ; cin >> d ; 
        boat_w.push_back(d) ; 
    }
    for(int i = 0 ;i<m ; i++){
        cin >> want[i] ; 
    } 
    sort(boat_w.begin(),boat_w.end());
    for(int i = 0; i<m ; i++){
        auto it = lower_bound(boat_w.begin(),boat_w.end(),want[i]); 
        if(it != boat_w.end() && want[i]!= 0 ){
            count ++; 
            // cout << "num use" << want[i] << endl ; 
            // cout << "that i want " << *it <<endl ; 
            boat_w.erase(it) ; 
            // cout << "AFTER DELETE" << endl;
            // cout << endl;
        }
        else{
            break; 
        }
    }

    cout << count ; 
}