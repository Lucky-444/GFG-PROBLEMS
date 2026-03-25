class Solution {
  public:
    vector<vector<int>> dp;
    
    bool solve(int idx, int sum, vector<int>& arr, int k) {
        if (sum == k) return true;
        if (idx == arr.size() || sum > k) return false;
    
        if (dp[idx][sum] != -1) return dp[idx][sum];
    
        bool take = solve(idx + 1, sum + arr[idx], arr, k);
        bool notTake = solve(idx + 1, sum, arr, k);
    
        return dp[idx][sum] = take || notTake;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        bool flag = false;
        dp.resize(arr.size() + 1 , vector<int>(k + 1 , -1));
        return solve(0 , 0 , arr , k);
    }
};