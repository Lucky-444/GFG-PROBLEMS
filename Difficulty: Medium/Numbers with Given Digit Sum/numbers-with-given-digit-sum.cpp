class Solution {
public:
    int dp[10][82];

    int solve(int idx, int n, int sum) {

        if (sum < 0) return 0;

        if (idx == n)
            return (sum == 0);

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int ans = 0;

        int start = (idx == 0 ? 1 : 0);

        for (int d = start; d <= 9; d++) {
            ans += solve(idx + 1, n, sum - d);
        }

        return dp[idx][sum] = ans;
    }

    int countWays(int n, int sum) {

        if (sum > 9 * n || sum < 1)
            return -1;

        memset(dp, -1, sizeof(dp));

        int ans = solve(0, n, sum);

        return ans == 0 ? -1 : ans;
    }
};