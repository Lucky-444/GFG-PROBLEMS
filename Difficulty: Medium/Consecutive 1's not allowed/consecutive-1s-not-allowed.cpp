class Solution {
  public:
    int countStrings(int n) {
        if (n == 1) return 2;
    
        vector<int> dp(n + 1);
        dp[1] = 2; // "0", "1"
        dp[2] = 3; // "00", "01", "10"
    
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
    
        return dp[n];
    }
};