#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<int,int>> deadline;
    vector<int> pre ;
    vector<int> solve; 
    vector<int> answer_set ; 
    int n; 
    cin >> n; 
    for(int i = 0 ; i<n ;i++){
        int s, t, w; 
        cin >> s >> t >> w; 
        deadline.push_back(make_pair(s, t)); 
        pre.push_back(w) ;
        solve.push_back(w);         
    } 

    for(int i = 1 ; i <n ; i++){
        for(int j = 0 ; j<i ; j++){
            //update w
            if(deadline[j].second <= deadline[i].first){
                if(solve[j]+pre[i] > solve[i]) {
                    solve[i] = solve[j] + pre[i] ; 
                }
            }
        }
    }
    //// print ///
    
    int maxx = -1 ;
    int index_max ; 
    for(int i = 0 ; i <n ;i++){
        if(solve[i]>maxx) {
            maxx = solve[i] ;
            index_max = i ; 
        }
    }
    int s = deadline[index_max].first ;
    answer_set.push_back(index_max+1) ; 
    // cout << s << " " << index_max ;
    for(int i = index_max-1 ; i>=0 ; i--){
        if(deadline[i].second <= s){
            answer_set.push_back(i+1) ; 
            s = deadline[i].first ; 
        }
    }

   cout << maxx << endl;
   cout << answer_set.size() << endl; 
   for(auto i :answer_set) cout << i <<" ";



    return 0;
}
