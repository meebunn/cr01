#include <iostream>
#include <list>

using namespace std; 
int arr[100] ; 
int main(){
    int cmd;
    list<int> lst ;  
    for(int i = 0 ; i <= 55 ; i++) {
        cin >> arr[i] ;
        if(arr[i] == 0 ) break ; 
    }
    for(int j = 0; j <=60 ; j++){
        cmd = arr[j] ; 
        if(cmd == 0) break;  
        for( int i =1  ; i <=cmd ; i++) {
            lst.push_back(i) ;

        }
        lst.reverse() ;
         
        cout << "Discarded cards:" ;
        while(lst.size() >= 2) {

            int tt = lst.back() ; 
            lst.pop_back() ;
            cout << " " << tt;
            if(lst.size() >= 2) cout << ","; 

            int swp = lst.back() ; 
            lst.pop_back() ; 
            lst.push_front(swp) ; 

        }
        cout << endl;
        cout << "Remaining card: " << lst.front() << endl; 
        lst.clear() ;

    }
}