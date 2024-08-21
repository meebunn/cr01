#include <iostream>
#include <map>
#include <algorithm>  

using namespace std;

int main() {
    int n;
    cin >> n;

    map<long long, long long> data;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        data[x]++;
    
        auto maxF = max_element(
            data.begin(),
            data.end(),
            [](auto &lhs, auto &rhs) {
                return lhs.second <= rhs.second;
            }
        );

        if (maxF != data.end()) cout << maxF->first << endl ; 
    

    }
}