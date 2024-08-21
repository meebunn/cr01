#include<iostream> 
using namespace std ; 
int send[100100] ; 
int t[100100] ; 
int s[100100] ; 
int main(){
    int n ; cin >> n ; 
    for(int i = 1 ; i <= n ; i++) cin >> send[i] ; 
    for(int i = 1 ; i <= n ; i++) t[i] = i ; 
    //
    cout <<  "before" << endl; 
    for(int i = 1 ; i <= n ; i++) cout << t[i] << " " ;
    cout << endl; 
    for(int i = 1 ; i<=n ; i++) s[send[i]] = t[i] ;
    
    for(int i = 1 ; i <= n ; i++) t[i] = s[i];
    for(int i = 1 ; i <= n ; i++) s[i] = 0 ; 

    cout << endl<< "After 1" << endl ;
    for(int i = 1 ; i <= n ; i++) cout << t[i] << " " ; 
    for(int i = 1 ; i<=n ; i++) s[send[i]] = t[i] ;
    for(int i = 1 ; i <= n ; i++) t[i] = s[i];
    for(int i = 1 ; i <= n ; i++) s[i] = 0 ; 
    cout << endl << "After 2" << endl ; 
    for(int i = 1 ; i <= n ; i++) cout << t[i] << " " ;
}

/*
6
2
6
5
4
3
1
*/