class Solution {
public:
    int n;
    unordered_map<int, bool> dp;

    bool solve(vector<int>& arr, int k, int currSum, int targetSum, int mask) {
        if (k == 0) return mask == (1 << n) - 1; // all elements used

        if (currSum == targetSum) {
            // One subset formed, look for next
            return solve(arr, k - 1, 0, targetSum, mask);
        }

        if (dp.count(mask)) return dp[mask];

        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)) && currSum + arr[i] <= targetSum) {
                if (solve(arr, k, currSum + arr[i], targetSum, mask | (1 << i))) {
                    return dp[mask] = true;
                }
            }
        }

        return dp[mask] = false;
    }

    bool isKPartitionPossible(vector<int> &arr, int k) {
        n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum % k != 0) return false;
        int targetSum = totalSum / k;

        return solve(arr, k, 0, targetSum, 0);
    }
};
