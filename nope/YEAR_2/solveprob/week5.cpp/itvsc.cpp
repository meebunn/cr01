#include <bits/stdc++.h>

using namespace std;

int main() {
    int n ; cin >> n ;
    vector<pair<int,int>> data(n) ; 
    for(int i = 0 ; i < n ; i++){
        cin >> data[i].second >> data[i].first ; 
    }
    sort(data.begin(),data.end()) ; 
    
    // for(auto p : data) {
    //     cout << p.first << " " << p.second << "," ; 
    // }
    int num = 1 ; 
    int time = data[0].first ; 
    for(auto p : data) {
        if(p.second >= time) {
            time = p.first ;
            num++ ; 
        }
    }
    cout << endl << num ; 
    return 0;
}