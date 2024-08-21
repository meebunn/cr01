#include <iostream>
#include <vector>
#include <list>

#define MAXX 1000000

using namespace std;

typedef struct data {
    list<int> arr[MAXX];
} data_t;

int main() {
    data_t data;
    int n, i;
    cin >> n;

    for (i = 0; i < n; i++) {
        char x;
        int y, z;
        cin >> x >> y >> z;

        if (x == 'N') {
            data.arr[z].push_back(y);
        }
    }

    // Print all elements stored in the list at index 0
    cout << "Elements in the list at index 0: ";
    for (const int& element : data.arr[0]) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}