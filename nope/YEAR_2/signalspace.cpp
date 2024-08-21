#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1 ; cin >> s1;  
    string s2 ; cin >> s2 ; 
    int j= 0 ; 
    int count = 0 ;
    for(int i = 0 ; i <s2.size() ; i++) {
        if(s2[i] == s1[j]){
            j++; 
            if(j == s1.size()) {
                j = 0 ; 
                count ++; 
            }
        }
    }
    cout << count ;
    return 0;
}