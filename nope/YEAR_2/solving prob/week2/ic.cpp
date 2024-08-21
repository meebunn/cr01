#include<iostream>
#include <list>
#include <string>
using namespace std; 

int main(){
    list<int> l ;
    int r,i ; cin >> r ;
    for(i=0;i<r;i++){
        string str;
        int n ; 
        cin >> str ; 
        if(str == "ri") {
            cin >> n; l.push_back(n) ;
        }
        else if (str == "li"){
            cin >> n ;l.push_front(n) ;
        }
        else if (str == "rr"){
            if(!l.empty()){
                int swp = l.back() ; 
                l.pop_back(); 
                l.push_front(swp) ;
            }
        }
        else if( str == "lr"){
            if(!l.empty()){
                int swp = l.front() ; 
                l.pop_front();
                l.push_back(swp);
            }
        }

    }
    for(auto i=l.begin() ; i!=l.end(); i++){
        cout << *i << endl; 
    }
   
}