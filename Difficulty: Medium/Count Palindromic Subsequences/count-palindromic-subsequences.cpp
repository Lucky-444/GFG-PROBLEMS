class Solution {
  public:
    /*You are required to complete below method */
    int dp[35][35];
    int solve(string &s ,int  i, int j){
        if(i > j) return 0;
        
        if(i == j) return 1;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
            
        int ans ;
        if(s[i] != s[j]){
            ans = solve(s,  i, j -1) + 
                    solve(s , i + 1 , j) - 
                    solve(s , i + 1 , j - 1);
        }
        else{
            ans = 1 + solve(s, i + 1 , j) + solve(s , i , j - 1);
        }
        
        return dp[i][j] =  ans;
    }
    
    int countPS(string &s) {
        // Your code here
        int n = s.size();
        memset(dp , -1 ,sizeof(dp));
        return solve(s , 0 , n - 1);
    }
};