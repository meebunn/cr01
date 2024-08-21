#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
map<long long,long long> track ; 
int main() {
    int x ; cin >> x;  
    for(int i = 0 ;i < x; i++) {
        long a ; cin >> a ; 
        if(a == 1 ) {
            long long b , c ; cin >> b >> c; 
            track[b] += c ;
        }
        else if( a== 2) {
            long long b ; cin >> b; 
            cout << track[b] << endl ; 
        }
        else if (a == 3 ){
            long long b ,c ; cin >> b >> c ;
            if(track[b]-c < 0) {
                cout << track[b] << endl  ; 
                track[b]=0 ; 
            }
            else {
                cout << c << endl; 
                track[b] -= c ; 
            }
        }
    }
}