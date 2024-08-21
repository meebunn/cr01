#include <iostream>
#include <vector>

using namespace std;
int n, z, d, e;
int car = 0 , s = -1 , count = 0 ;
int a[100100] ; 

int main() {

    cin >> n >> z >> d >> e;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    for (int i = 0; i < n; i++) {
        if(a[i] <= car+d) s= i ; 
        if(car+d+e >= z) break  ; 
        
    }
}