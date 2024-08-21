#include <iostream>
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
    int lastLabel = -1;

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

            lastLabel = label;  // Update lastLabel after processing the command
        } else if (x == 0) {
            data[y]--;
            maxHeap.push({data[y], y});

            while (!maxHeap.empty() && data[maxHeap.top().second] != maxHeap.top().first) {
                maxHeap.pop(); // Remove outdated entries from the heap
            }

            if (!maxHeap.empty()) {
                maxFreq = maxHeap.top().first;
                label = maxHeap.top().second;
            }

            if (data[y] >= maxFreq && y < label) {  // Update label if frequency is equal and y is smaller
                maxFreq = data[y];
                label = y;
            }

            lastLabel = label;  // Update lastLabel after processing the command
        }

        cout << lastLabel << endl;
    }

    return 0;
}
