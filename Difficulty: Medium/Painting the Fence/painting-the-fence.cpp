
class Solution {
  public:
    int mod = 1e9 + 7;
    int add(int a  ,int b ){
        return (a % mod + b %mod) % mod;
    }
    
    int mul(int a , int b){
        return (a % mod * b % mod) % mod;
    }
    
    vector<int>dp;
    
    int solve(int n ,int k){
        if(n == 1) return k;
        
        if(n == 2) return k  + (k * ( k- 1));
        
        if(dp[n] != -1 ) return dp[n];
        
         dp[n] = mul(k - 1, add(solve(n - 1, k), solve(n - 2, k)));
        
        return dp[n];
    }
    int countWays(int n, int k) {
        // code here
        dp.resize(n + 1, -1);
        return solve(n , k);
        
    }
};

