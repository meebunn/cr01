#include <iostream>
#include <set>
#include <algorithm>  
#include <cstdlib>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    set<int> set1;

    for (int i = 0; i < x; i++) {
        int data;
        cin >> data;
        set1.insert(data);
    }

    // 10 12 20 25 35
    for(int i = 0 ; i < y ; i++){

        int r , l ; 
        int target  ;  cin >> target; 
        auto it = set1.upper_bound(target) ;
        r= *it ; 
        l = *(--it) ; 
        if(abs(r-target) < abs(l-target)) cout << r << endl ; 
        else cout << l << endl; 
    }
}
