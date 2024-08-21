#include <iostream>
#include <vector>
#include <list>
using namespace std; 

int main() {
   vector<list<int>> lst(100100);  
    int n ; cin >> n; 
    for(int i = 0  ; i < n; i ++ ){
        char x ; 
        int y,z ; 
        cin >> x >> y >> z ; 

        if( x == 'N' ){
            lst[z].push_back(y) ;
        }
        if( x == 'M'){
            auto it = lst[z].end() ; 
            lst[z].splice(it,lst[y] ) ;
        }
    }
    for(int i=1 ; i <=100000 ;i++){
        for(auto j : lst[i] ){
            cout << j << endl;
        }

    }
    

}