class Solution {
  public:
    int n , m;
    vector<vector<int>>dp;
    int solve(int  i , int  j , auto &a , auto &b){
        if (j == m)
            return 0;

        if (i == n)
            return -1e9;

        if (n - i < m - j)
            return -1e9;
            
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int prodTake = a[i] * b[j] + solve(i + 1 , j + 1 , a , b);
        int prodSkip = 0 + solve(i + 1 , j , a , b);
        
        return dp[i][j] = max(prodTake , prodSkip);
        
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        n = a.size();
        m = b.size();
        dp.resize(n + 1 ,  vector<int>(m + 1 , -1));
        
        
        return solve(0 , 0 , a , b);
    }
};
