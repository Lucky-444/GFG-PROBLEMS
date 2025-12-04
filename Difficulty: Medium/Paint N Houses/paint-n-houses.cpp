// User function Template for C++

class Solution {
public:
    long long dp[100005][4];  

    long long solve(int i, int prev, int N, int r[], int g[], int b[]) {
        if(i == N) return 0;

        if(dp[i][prev] != -1)
            return dp[i][prev];

        long long ans = LLONG_MAX;

        // Paint Red (0)
        if(prev != 0)
            ans = min(ans, (long long)r[i] + solve(i + 1, 0, N, r, g, b));

        // Paint Green (1)
        if(prev != 1)
            ans = min(ans, (long long)g[i] + solve(i + 1, 1, N, r, g, b));

        // Paint Blue (2)
        if(prev != 2)
            ans = min(ans, (long long)b[i] + solve(i + 1, 2, N, r, g, b));

        return dp[i][prev] = ans;
    }

    long long int distinctColoring(int N, int r[], int g[], int b[]) {
        // initialize DP with -1
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 4; j++)
                dp[i][j] = -1;

        // Start with prev color = 3 (means no previous)
        return solve(0, 3, N, r, g, b);
    }
};
