#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n = 8; // number of pairs
    vector<pair<int, int>> pairs;

    // Input the pairs
    for (int i = 0; i < n; ++i) {
        int first, second;
        cin >> first >> second;
        pairs.push_back({first, second});
    }

    // Create a mapping to represent the linked list structure
    unordered_map<int, int> next;
    for (const auto& p : pairs) {
        next[p.first] = p.second;
    }

    // Traverse the linked list starting from -1-
    int current = -1;
    while (next.find(current) != next.end()) {
        cout << "-" << current << "-";
        current = next[current];
    }

    // Print the last element in the linked list
    cout << "-" << current << "-" << endl;

    return 0;
}
