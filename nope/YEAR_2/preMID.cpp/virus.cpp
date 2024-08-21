#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    list<int> arr;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        arr.push_back(d);
    }

    auto it = arr.begin();

    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            it = arr.begin();
        } else if (c == 2) {
            it++;
            if (it == arr.end()) it = arr.begin();
        } else if (c == 3) {
            int num;
            cin >> num;
            auto pt = it ; 
            arr.insert(pt, num);
        }
        else if (c == 4) {
            int num ; 
            cin >> num ; 
            auto pt = it ;  
            arr.insert(++pt,num);
        }
        

    }

    for (auto j : arr) {
            cout << j << " ";
    }
    return 0;
}
