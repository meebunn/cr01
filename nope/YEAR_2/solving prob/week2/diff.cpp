#include <iostream>
#include <set>
using namespace std; 
int arr[110] ; 

int main() {
    set<int> set1 ; 
    int n ; cin >> n ; 
    for(int i = 0  ; i <n ; i ++ ){
        cin >> arr[i] ;
    }

    int s=0 ;

    for(int i = 0 ; i < n ; i++){
        s=arr[i];
        set1.insert(s); 
        for(int j = 0 ; j<n ; j++){
            if(j > i ){
                s += arr[j] ;
                set1.insert(s) ;
            }
        }
        s = 0 ;
    }
    cout << set1.size(); 
}