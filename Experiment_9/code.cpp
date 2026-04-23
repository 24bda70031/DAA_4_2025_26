class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // code here
         int n = arr.size();
        int sum = 0;
        
        for (int x : arr) sum += x;

        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        int best = 0;
        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                best = j;
                break;
            }
        }

        return sum - 2 * best;
    }
};
