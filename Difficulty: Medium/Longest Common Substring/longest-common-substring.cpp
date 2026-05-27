class Solution {
  public:
    int n , m ;
    vector<vector<int>>dp;
    int solve(auto &s , auto &t , int i , int j){
        if(i >= n || j >= m) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
            return dp[i][j] =  1 + solve(s , t , i + 1 , j + 1);
        }
        
        return dp[i][j] = 0;
    }
    int longCommSubstr(string& s1, string& s2) {
        // code here
        n = s1.size();
        m = s2.size();
        dp.resize(n + 1, vector<int>(m + 1 , -1));
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i ++){
            for(int j =  0 ; j < m ; j ++){
                int maxi = solve(s1 , s2 , i , j);
                ans = max(ans , maxi);
            }
        }
        
        return ans == INT_MIN ? -1 : ans ; 
    }
};