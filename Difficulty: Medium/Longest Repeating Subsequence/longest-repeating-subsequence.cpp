class Solution {
  public:
    int dp[1001][1001];
    int n;
    int solve(int i , int j , string &s1 , string &s2){
        if(i >= n || j >= n){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i != j && s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i + 1 , j + 1 , s1 , s2);
        }
        
        return dp[i][j] = max(solve(i + 1 , j , s1 , s2) , solve(i , j + 1, s1 , s2));
    }
    int longestRepSubseq(string &s) {
        // Code here
        n = s.size();
        
        memset(dp , -1 , sizeof(dp));
        
        string s2 = s;
        
        int x = solve(0 , 0 , s , s2);
        
        return x;
    }
};