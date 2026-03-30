
class Solution {
public:
    long long solve(int i, int buy, vector<int>& arr, int k, vector<vector<long long>>& dp) {
        if (i == arr.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        long long profit = 0;

        if (buy) {
            // Option 1: Buy
            long long take = -arr[i] + solve(i + 1, 0, arr, k, dp);
            // Option 2: Skip
            long long skip = solve(i + 1, 1, arr, k, dp);

            profit = max(take, skip);
        } else {
            // Option 1: Sell
            long long sell = arr[i] - k + solve(i + 1, 1, arr, k, dp);
            // Option 2: Skip
            long long skip = solve(i + 1, 0, arr, k, dp);

            profit = max(sell, skip);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return solve(0, 1, arr, k, dp);
    }
};