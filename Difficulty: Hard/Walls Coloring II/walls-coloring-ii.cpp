class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;

        int k = costs[0].size();
        if(k == 0) return -1;
        if(k == 1 && n > 1) return -1; // impossible

        vector<int> dp(k, 0), newdp(k);

        // Initialize dp for first wall
        for(int c = 0; c < k; c++) {
            dp[c] = costs[0][c];
        }

        for(int i = 1; i < n; i++) {
            // Find smallest and 2nd smallest from previous row
            int min1 = INT_MAX, min2 = INT_MAX;
            int color_min1 = -1;

            for(int c = 0; c < k; c++) {
                if(dp[c] < min1) {
                    min2 = min1;
                    min1 = dp[c];
                    color_min1 = c;
                }
                else if(dp[c] < min2) {
                    min2 = dp[c];
                }
            }

            // Compute new dp for row i
            for(int c = 0; c < k; c++) {
                if(c == color_min1)
                    newdp[c] = costs[i][c] + min2;
                else
                    newdp[c] = costs[i][c] + min1;
            }

            dp = newdp;
        }

        // final answer
        int ans = *min_element(dp.begin(), dp.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
