#include <bits/stdc++.h>

using namespace std;

int main() {
    string str ,t  ; 
    cin >> t ; 
    cin >> str  ;
    int n=0 ; 
    int s=0  ; 
    for(int i = 0 ; i <str.length()-1 ; i++){
        if(t[s]== str[i]){

            s++ ; 
            if(s == t.length()) {
                n++ ; 
                s= 0 ; 
            }
        }
    }

    cout << n ; 
    return 0;
}