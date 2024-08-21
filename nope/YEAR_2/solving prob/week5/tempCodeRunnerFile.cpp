#include <bits/stdc++.h>

using namespace std;

int main() {
    int c ; cin >> c ;
    
    for(int i = 0 ; i <c;i++){
        int n; cin >> n;
        int num_sc = 0 ; 
        vector<char> a(110); 
        fill(a.begin(),a.end(),0) ; 
        for(int i = 0 ; i<n ;i++) {
            cin >> a[i] ; 
        }
        int j=0; 
        while(j<=n){
            if(a[j] == '.') {
                num_sc +=1 ; 
                j+=3;
            }
            else{
                j++;
            }
        }
        cout << "Case " <<i+1<<": " <<num_sc <<endl; 
    }
     
    return 0;
}