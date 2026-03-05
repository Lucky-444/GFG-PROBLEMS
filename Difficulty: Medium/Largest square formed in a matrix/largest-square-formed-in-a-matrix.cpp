class Solution {
  public:
    vector<vector<int>> dp;

    int solve(vector<vector<int>> &mat , int r, int c){
        int n = mat.size();
        int m = mat[0].size();

        if(r >= n || c >= m) return 0;
        if(mat[r][c] == 0) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        int down = solve(mat , r + 1 , c);
        int diagonal = solve(mat , r + 1 , c + 1);
        int right = solve(mat , r , c + 1);

        return dp[r][c] = min({down , diagonal , right}) + 1;
    }

    int maxSquare(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        dp.assign(n , vector<int>(m , -1));

        int res = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 1){
                    int ans = solve(mat , i , j);
                    res = max(ans , res);
                }
            }
        }

        return res;
    }
};