class Solution {
  public:
    using ll = long long;
    int dp[60];
    int solve(int n){
        if(n == 1){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int res = 0;
        
        for(int i = 1 ; i <= n / 2 ; i ++){
            res = max({res , i * (n - i) , i * (solve(n - i))});
        }
        
        return dp[n] = res;
    }
    int maxProduct(int n) {
        // code here
        if (n == 2 || n == 3) return n -1;
        memset(dp , -1 , sizeof(dp));
        return solve(n);
    }
};