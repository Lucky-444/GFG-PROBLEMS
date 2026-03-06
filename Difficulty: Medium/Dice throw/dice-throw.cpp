class Solution {
  public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int solve(int n, int k, int x) {
        if (n == 0 && x == 0){
            return 1;
        }

        if(n == 0) return 0;
            
        if (x < 0)
            return 0; 

        if (dp[n][x] != -1)
            return dp[n][x]; // Return memoized result

       long long ans = 0;
        for (int v = 1; v <= k; v++) {
            if(x - v  < 0) continue;
            ans += solve(n - 1, k, x - v) % mod ;
        }

        return dp[n][x] = ans % mod; // Store result in dp table
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target);
    }
    int noOfWays(int m, int n, int x) {
        // code here
        
        return numRollsToTarget(n , m ,x);
    }
};