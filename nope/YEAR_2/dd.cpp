#include <bits/stdc++.h>
#define inf 10000000
using namespace std;

int main() {
    //max 200cc 
    vector<char> a1(201); 
    vector<char> a2(201); 
    int solve[220][220];

    string s1; 
    cin >> s1; 
    string s2; 
    cin >> s2;     
    
    for(int i = 1 ; i <= s1.size() ; i++){ 
        a1[i] = s1[i-1];  
    }
    for(int i = 1 ; i <= s2.size() ; i++) { 
        a2[i] = s2[i-1]; 
    }

    for(int i = 0 ; i <= s2.size() ; i++){
        for(int j = 0 ; j <= s1.size() ; j++){
            int left = inf, top = inf, lt = inf; 

            if(i == 0 && j == 0) {
                solve[i][j] = 0; 
                continue;
            }
            //=
            if(a2[i] == a1[j]) {
                solve[i][j] = solve[i-1][j-1];
                continue;
            }

            //!=
            if(j - 1 >= 0) top = 1 + solve[i][j-1];
            if(i - 1 >= 0) left = 1 + solve[i-1][j];
            
            if(left <= top) {
                solve[i][j] = left; 
            } else {
                solve[i][j] = top; 
            }
        }
    }

    for(int i = 0 ; i <= s2.size() ; i++){
        for(int j = 0 ; j <= s1.size() ; j++){
            cout << solve[i][j] << " ";
        }
        cout << endl;
    }
    /// i  row , j colum 
    int i=s2.size() ; 
    int j=s1.size() ; 
    vector<char> res ;
    while(i!=0 && j!=0){
        if(a2[i] == a1[j]){
            res.push_back(a1[j]) ; 
            i--;
            j--;
        }
        else if(solve[i][j-1]<solve[i-1][j]){
            j-- ; 
        }
        else{
            i-- ; 
        }
    }
    cout << res.size() << endl;
    for(int i = res.size()-1 ; i>=0 ; i--){
        cout << res[i] ; 
    }
    return 0;
}