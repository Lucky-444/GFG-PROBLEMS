class Solution {
public:
    int solve(int n, int idx, vector<int>& sq, vector<vector<int>>& dp) {
        if (n == 0) return 0;
        if (idx >= sq.size() || n < 0) return 1e9;

        if (dp[idx][n] != -1) return dp[idx][n];

        // pick current square
        int pick = 1 + solve(n - sq[idx], idx, sq, dp);

        // skip current square
        int not_pick = solve(n, idx + 1, sq, dp);

        return dp[idx][n] = min(pick, not_pick);
    }

    int minSquares(int n) {
        vector<int> sq;
        for (int i = 1; i * i <= n; i++) {
            sq.push_back(i * i);
        }

        vector<vector<int>> dp(sq.size(), vector<int>(n + 1, -1));
        return solve(n, 0, sq, dp);
    }
};
