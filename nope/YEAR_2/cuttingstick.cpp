#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to calculate the minimum cost of cutting the stick
int cuttingCost(int n, vector<int>& prices) {
    // Create a vector to store the minimum cost for each length
    vector<int> dp(n + 1, 0);

    // Loop through all possible lengths
    for (int i = 1; i <= n; ++i) {
        int minCost = INT_MAX;
        // Try all possible cuts and find the minimum cost
        for (int j = 1; j <= i; ++j) {
            minCost = min(minCost, prices[j] + dp[i - j]);
        }
        dp[i] = minCost;
    }

    return dp[n]; // Return the minimum cost for the given length
}

int main() {
    // Length of the stick
    int stickLength = 100;
    // Prices for each length
    vector<int> prices = {25, 50, 75};

    // Calculate the minimum cost
    int minCost = cuttingCost(stickLength, prices);
    
    // Output the minimum cost
    cout << "Minimum cost to cut the stick into pieces: " << minCost << endl;

    // Output the minimum cost for each length (optional)
    cout << "Minimum cost for each length:" << endl;
    for (int i = 1; i <= stickLength; ++i) {
        cout << "Length " << i << ": " << cuttingCost(i, prices) << endl;
    }

    return 0;
}
