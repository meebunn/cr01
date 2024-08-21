#include <bits/stdc++.h>

using namespace std;
int n , max_h, r1, r2 ; 
 

int main() {
    int c ; cin >> c; 
    int time ; 
    for(int t = 0 ; t< c ; t++){
        cin >> n >> max_h >> r1 >>r2 ; 
        vector<int> h (n) ;  
        vector<bool> used (n) ; 
        time = 0  ; 

        for(int i = 0 ; i < n ; i++) {
            h[i] = 0 ; 
            used[i] = false ; 
        }
        
        for(int i = 0 ; i < n ; i++) {
            cin >> h[i] ; 
        }

        sort(h.begin(),h.begin()+n) ; 

        if(2*r1 <= r2){
            time = n*r1 ;
        }
        else{

            int j=n-1 ;
            
            for(int i = 0 ; i <n ;i++){

                if(used[i] == true) {
                    continue; 
                }
            
                while(j>i) {

                    if(h[i]+h[j] < max_h && j > i){
            
                        time+=r2; 
                        used[i] = true  ; 
                        used[j] = true  ;
                        j--;
                        break ; 
                    }
                    else{
                        j-- ; 
                    
                    }
                }
                if(used[i] == false){
                    time+=r1 ; 
                } 
            
            }
        }
        
        h.clear() ; 
        used.clear() ; 
        cout << "Case " << t+1 << ": " << time << endl;   
    }
    
    return 0;
}