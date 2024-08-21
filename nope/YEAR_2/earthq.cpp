#include <bits/stdc++.h>
#define infinity 10000000
using namespace std;

int main() {
    int c;  cin >> c; 
    int arr[510][510] ; 
    int dp[510][510] ; 
    cout << "kong" ; 
    cout << "kong" ; 
    cout << "kong" ; 
    cout << "kong" ; 
    cout << "kong" ; 
    for(int i = 0 ;i<c ; i++) {
        int m ; cin>> m ;
        int n;  cin >> n ;
        cout << "kong";
        for(int i = 0 ;i<m;i++){
            for(int j = 0; j<n;j++){
                cout <<"ko" ;
                cin >> arr[i][j] ; 
            }
        }

        ///dp
        for(int i = 0 ; i<m ;i++){
            for(int j = 0 ; j<n ;j++){
                int top=infinity,lt=infinity,rt=infinity ; 
                top = dp[i-1][j] +arr[i][j] ; 
         

                if( j-1>=0){
                    lt = dp[i-1][j-1] +arr[i][j] ; 
                }

                if(j+1 <n){
                    int rt = dp[i-1][j+1] +arr[i][j] ; 
                }

                int k= min({top,lt,rt}) ; 
                dp[i][j] = k;


            
            }
        }
        // cout <<"kong" ; 

        for(int i = 0 ;i<m ; i++){
            for(int j = 0 ;j<n ;j++){
                cout << dp[i][j] << " " ; 
            }
            cout << endl ; 
        }

    }
}
/*
2
8 5
1 6 7 2 3
7 9 5 2 1
1 1 8 8 6
6 5 6 3 9
9 1 4 8 6
4 2 9 7 7
2 3 2 5 8
5 8 2 4 4*/