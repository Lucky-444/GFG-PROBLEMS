class Solution {
  public:
    int chocolatePickup(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        function<int(int, int, int)> solve = [&](int r1, int c1, int c2) -> int {
            int r2 = r1 + c1 - c2;  // both have taken same number of steps

            if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
                mat[r1][c1] == -1 || mat[r2][c2] == -1) {
                return -1e9;  // invalid
            }

            // reached destination
            if (r1 == n - 1 && c1 == n - 1) return mat[r1][c1];

            if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];

            int choco = 0;
            if (r1 == r2 && c1 == c2)
                choco += mat[r1][c1];  // same cell, collect once
            else
                choco += mat[r1][c1] + mat[r2][c2];

            int best = max({
                solve(r1 + 1, c1, c2 + 1),  // down, right
                solve(r1, c1 + 1, c2),      // right, down
                solve(r1 + 1, c1, c2),      // down, down
                solve(r1, c1 + 1, c2 + 1)   // right, right
            });

            choco += best;
            return dp[r1][c1][c2] = choco;
        };

        int res = max(0, solve(0, 0, 0));
        return res;
    }
};
