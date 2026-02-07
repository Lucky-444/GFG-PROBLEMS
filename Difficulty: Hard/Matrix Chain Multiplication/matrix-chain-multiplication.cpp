class Solution {
  public:
    int dp[105][105];
    int solve(int i , int j , vector<int>&arr){
        if(i == j - 1){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k = i + 1; k <= j - 1 ; k ++){
            ans = min(ans , solve(i , k , arr) + solve(k , j , arr) + arr[i] * arr[j] * arr[k]);
        }
        
        return dp[i][j] =  ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        memset(dp , -1 , sizeof(dp));
        return solve(0 , n - 1, arr);
    }
};