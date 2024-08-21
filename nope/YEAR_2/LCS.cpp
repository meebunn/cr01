#include <bits/stdc++.h>
#define inf 19000000
using namespace std;
 
int main() {
    ////max 200cc 
    vector<char> a1 (200) ;
    vector<char> a2 (200) ; 
    int solve[220][220] ; 
    string s1 ; cin >> s1 ; 
    string s2 ; cin >> s2 ;     
    
    for(int i = 1 ; i<=s1.size() ;i++){
        a1[i] = s1[i-1] ;  
    }
    for(int i = 1 ; i<=s1.size() ; i++) {
        a2[i] = s2[i-1] ; 
    }

    for(int i= 0 ; i<a2.size() ; i++){
        for(int j = 0 ; j < a1.size() ; j++){
            int left,top,lt ; 
            if(i == 0 && j == 0) {
                solve[i][j] = 0 ; 
                continue;
            }
            if(a2[i] == a1[j] ? lt = solve[i-1][j-1] : lt = inf ) ; 
            if(j-1<0 ? top = inf : top = 1+solve[i,j-1]) ; 
            
            

        }
    }
    

    return 0;
}

