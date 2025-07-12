// User function Template for C++

class Solution {
  public:
    int  n , m ;
    int find(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=n || j>= m){
            return 0;
        }
        
        if(i==n || j== m){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int u_dia = find(i-1,j+1,grid,dp);
        int l_dia = find(i+1,j+1,grid,dp);
        int row = find(i,j+1,grid,dp);
        
        return dp[i][j] = grid[i][j] + max({u_dia,l_dia,row});
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
         n = mat.size();
         m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int ans =  INT_MIN;
        for(int i = 0;i < n;i++){
            ans = max(ans,find(i,0,mat,dp));
        }
        
        return ans;
    }
};
