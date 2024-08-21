#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> c(n);
    vector<int> p(n);
    vector<int> w(n);
    vector<int> weight(m);
    set<int> mincost ;
    int max_weight= -1;
    
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i] >> w[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> weight[i];
        if (weight[i] > max_weight) {
            max_weight = weight[i];
        }
    }

    for (int i = 0; i < n; i++) {
        int total = 0;
        int count = 0;
        int sum = 0;

        for(int j = 0 ; j<m ;j++){
            if(sum+weight[j]<=w[i]){
                sum+=weight[j] ; 
            }
            else{
                count++;
                sum = weight[j] ; 
            }
        }
        if(sum!=0) {
            count++; 
        }
        total = c[i]+count*p[i] ; 
        if(w[i]>=max_weight){
            mincost.insert(total) ; 
        }
      
    }
    cout << *mincost.begin() ;
}
