#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> arr (200000) ; 
    vector<int> len (200000) ; 
    vector<int> from(20000) ; 
    vector<int> seq(20000) ; 

    int n ; cin >> n ;

    for(int i = 0 ; i <n ; i++ ){
        int data  ; cin >> data ; 
        arr[i+1] = data ;  
    } 

    for(int i = 1 ; i <=n ; i++) {
        int maxd = 1 ;
        int idx = 0 ;
        bool c = false ; 
        for(int j = i-1 ; j>0 ;j--){
            if(arr[j] < arr[i] && len[j]>=maxd){
                maxd = len[j] ; 
                idx = j ; 
                c = true ; 
            }
        }
        if(c == true){
            len[i] = maxd+1; 
            from[i] = idx ;
        }
        else{
            len[i] =1 ;
            from[i] = 0 ; 
        }
    }
    // for(int i = 0;  i<n ; i++){
    //     cout << arr[i+1] << " " ;  
    // }
    // cout << endl ; 

    // for(int i = 0 ; i <n ; i++) {
    //     cout << len[i+1] << " " ;  
    // }

    // cout << endl ;

    // for(int i = 0 ; i <n ; i++) {
    //     cout << from[i+1] << " " ;  
    // }
    int max_i = -1; 
    int end ;  
    for(int i = 1 ; i<=n ; i++){
        if(max_i < len[i]){
            
            max_i = len[i] ;
            end = i  ; 
        }
    }
    // cout << endl ;
    
    for(int i = 0 ; i<max_i ; i++){
        seq[i] = arr[end] ; 
        end = from[end] ; 
    }
    cout << max_i << endl ; 
    for(int i =  max_i-1 ; i>=0 ; i--) cout << seq[i] << " " ; 

    return 0;
}