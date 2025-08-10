class Solution {
  public:
    int dp[10005];
    int solve(int n , int x , int y , int z){
        if(n == 0){
            return 0;
        }
        
        if(n < 0){
            return INT_MIN;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int cuts_x =  solve(n - x , x, y , z);
        int cuts_y =  solve(n - y , x, y , z);
        int cuts_z =  solve(n - z , x, y , z);
        
        int res = max({cuts_x , cuts_y , cuts_z});
            
        if(res == INT_MIN) return dp[n] = INT_MIN;
        return dp[n] =  res + 1;
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        memset(dp , -1 ,sizeof(dp));
        int ans = solve(n , x, y , z);
        return ans < 0 ? 0 : ans ;
    }
};