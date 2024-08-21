#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> data;
    priority_queue<pair<int, int>> maxHeap; // maxHeap for efficient retrieval of maximum frequency

    int maxFreq = 0;
    int label = -1;

    while (n--) {
        int x, y;
        cin >> x >> y;

        if (x == 1) {
            data[y]++;
            maxHeap.push({data[y], y});

            if (data[y] >= maxFreq) {
                maxFreq = data[y];
                label = y;
            }
        } else if (x == 0) {
            data[y]--;
            maxHeap.push({data[y], y});

            while (!maxHeap.empty() && data[maxHeap.top().second] != maxHeap.top().first) {
                maxHeap.pop(); // Remove outdated entries from the heap
            }
            if(data[y] == maxFreq ) label = y ;
            if (!maxHeap.empty()) {
                maxFreq = maxHeap.top().first;
                label = maxHeap.top().second;
            }
        }

        cout << label << endl;
    }

    return 0;
}
