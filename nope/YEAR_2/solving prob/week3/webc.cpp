#include <iostream>
#include <list>
#include <unordered_set>
using namespace std; 

list<int> cache;

int main() {
    int x, y;
    cin >> x >> y; 
    int miss = 0; 

    unordered_set<int> cacheSet;

    for (int i = 0; i < y; i++) {
        int r; 
        cin >> r; 

        if (cacheSet.find(r) == cacheSet.end()) {
            miss++;
        } else {
            continue;
        }

        if (cache.size() < x) {
            cache.push_back(r);
            cacheSet.insert(r);
        } else {
            int front = cache.front();
            cache.pop_front();
            cacheSet.erase(front);

            cache.push_back(r);
            cacheSet.insert(r);
        }
    }

    cout << miss << endl; 
    return 0;
}