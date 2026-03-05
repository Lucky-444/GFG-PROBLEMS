// User function Template for C++

class Solution {
  public:
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>dp(n , vector<int>(m , 0));
        int res = 0 ;
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(mat[i][j] == 1){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }
                    
                    else dp[i][j] = 1 + min({dp[i - 1][j] , dp[i][j - 1] , dp[i - 1][j - 1]});
                    
                    res = max(res , dp[i][j]);
                }
            }
        }
        
        return res;
    }
};