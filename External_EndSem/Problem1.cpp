#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    // 1D array to store the maximum value for each capacity up to W
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // Traverse backwards to avoid using the same item multiple times
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int main() {
    // 1. Define the inputs
    int W = 4; // Maximum capacity of the knapsack
    vector<int> val = {1, 2, 3}; // Values of the items
    vector<int> wt = {4, 5, 1};  // Weights of the items
    
    // 2. Calculate the number of items
    int n = val.size(); 

    // 3. Call the function and store the result
    int max_val = knapSack(W, wt, val, n);

    // 4. Output the result
    cout << "Maximum value we can obtain: " << max_val << endl;

    return 0;
}
