#include<iostream>
#include <list>
#include <string>
using namespace std; 

int main(){
    list<int> l ;
    int n,i ; cin >> n;
    for(i=0 ; i<n ; i++){
        char com ;
        int num ;  
        cin >> com >> num;

        if(com == 'I') l.push_front(num) ; 
        else if ( com == 'A') l.push_back(num);
        else{
            if(num<=l.size()){
                auto j = l.begin(); 
                advance(j,num-1) ;
                l.erase(j);
            }
        }
    }

    for(auto i=l.begin() ; i!=l.end(); i++){
        cout << *i << endl; 
    }

}