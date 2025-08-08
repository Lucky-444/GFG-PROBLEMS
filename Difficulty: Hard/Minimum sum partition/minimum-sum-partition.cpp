class Solution {

  public:
    vector<vector<int>> dp;
    int solve(auto &arr ,int idx, int sum , int currSum){
        if(idx >= arr.size()){
            return currSum;
        }
        
        if(dp[idx][currSum] != -1){
            return dp[idx][currSum];
        }
        // Don't pick current element
        int not_pick = solve(arr, idx + 1, sum, currSum);

        // Pick current if it doesn't exceed 'sum'
        int pick = currSum;
        if (currSum + arr[idx] <= sum) {
            pick = solve(arr, idx + 1, sum, currSum + arr[idx]);
        }
        
        return dp[idx][currSum] =  max(pick, not_pick);  // get closest to sum
    }
    int minDifference(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        int half = total / 2;

        dp.resize(arr.size() + 1, vector<int>(half + 1, -1));

        int s1 = solve(arr, 0, half, 0);  // best sum ≤ total/2
        int s2 = total - s1;

        return abs(s2 - s1);
    }
};
