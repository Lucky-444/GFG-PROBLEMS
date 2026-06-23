class Solution {
public:
    int solve(int w, vector<int>& cost, vector<int>& dp) {

        if(w == 0)
            return 0;

        if(dp[w] != -1)
            return dp[w];

        int ans = 1e9;

        for(int i = 0; i < cost.size(); i++) {

            int wt = i + 1;

            if(cost[i] == -1 || wt > w)
                continue;

            int sub = solve(w - wt, cost, dp);

            if(sub != 1e9)
                ans = min(ans, cost[i] + sub);
        }

        return dp[w] = ans;
    }

    int minimumCost(vector<int>& cost, int w) {

        vector<int> dp(w + 1, -1);

        int ans = solve(w, cost, dp);

        return (ans == 1e9) ? -1 : ans;
    }
};