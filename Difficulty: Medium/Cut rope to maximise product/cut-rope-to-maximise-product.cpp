class Solution {
  public:
    int dp[60];
    int solve(int n){
        if(n == 0 || n == 1){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int ans = 0;
        
        for(int i = 1 ; i < n ; i ++){
            //take direct Product
            int directProduct = i * (n - i);
            
            int recursiveBreak = i * (solve(n - i));
            
            ans = max({ans , directProduct , recursiveBreak});
        }
        
        return dp[n] = ans;
    }
    int maxProduct(int n) {
        // code here
        memset(dp , -1 , sizeof(dp));
        return solve(n);
    }
};