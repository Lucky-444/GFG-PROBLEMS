class Solution {
public:
    int dp[12][12];
    int n, m;

    int solve(int pos, int last) {
        // If we have filled all positions
        if (pos == n)
            return 1;

        if (dp[pos][last] != -1)
            return dp[pos][last];

        int ways = 0;

        // Try every possible next value
        for (int next = 1; next <= m; next++) {
            if (last % next == 0 || next % last == 0) {
                ways += solve(pos + 1, next);
            }
        }

        return dp[pos][last] = ways;
    }

    int count(int N, int M) {
        n = N;
        m = M;

        memset(dp, -1, sizeof(dp));

        int ans = 0;

        // Choose every possible first element
        for (int first = 1; first <= m; first++) {
            ans += solve(1, first);
        }

        return ans;
    }
};