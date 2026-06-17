class Solution {
public:
    int solve(int idx, int target,
              vector<int>& arr,
              vector<vector<int>>& dp) {

        if(idx == arr.size())
            return target == 0;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        int skip = solve(idx + 1, target, arr, dp);

        int take = 0;
        if(arr[idx] <= target)
            take = solve(idx + 1,
                         target - arr[idx],
                         arr, dp);

        return dp[idx][target] = take + skip;
    }

    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(0, target, arr, dp);
    }
};