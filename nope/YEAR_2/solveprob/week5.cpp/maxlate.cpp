#include <bits/stdc++.h>

using namespace std;

int main() {
    int n ; cin >> n ; 
    vector<pair<int,int>> data(n) ; 
    for(int i = 0 ; i <n ; i++){
        cin >> data[i].first >> data[i].second ; 
    }
    sort(data.begin(),data.end()); 
    int maxtopay = 0 ; 
    int do_time = 0 ; 
    for(auto p : data ) {
        do_time+=p.second ;
        int k = do_time-p.first-10 ;
        if(k>maxtopay) maxtopay = k ; 

        
    }
    cout << maxtopay*1000 ; 
    return 0;
}