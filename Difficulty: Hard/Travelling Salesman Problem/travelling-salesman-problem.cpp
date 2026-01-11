class Solution {
  public:
    /*
        dp[idx][mask]

        idx  -> current city where the salesman is standing
        mask -> bitmask representing which cities have been visited so far

        dp[idx][mask] stores the MINIMUM cost to:
        - start from city `idx`
        - having already visited the cities represented by `mask`
        - and finally visit all cities and return back to city 0
    */
    int dp[16][(1 << 16) + 5];

    /*
        solve(cost, mask, idx)

        mask -> bitmask of visited cities
                if mask & (1 << j) != 0, city j is already visited

        idx  -> current city

        Returns:
        Minimum cost to visit all remaining cities (not in mask)
        and finally return to city 0
    */
    int solve(auto &cost , int mask , int idx){
        int n = cost.size();

        /*
            Base Case:
            If all cities are visited (mask == 111...111)

            Now we must return back to city 0.
            - If we are already at city 0 → cost = 1 (valid tour)
            - Otherwise → invalid path, return INT_MAX
        */
        if(mask == (1 << n) - 1){
            return idx == 0 ? 0 : INT_MAX;
        }

        // If this state is already computed, reuse it
        if(dp[idx][mask] != -1){
            return dp[idx][mask];
        }

        int ans = INT_MAX;

        /*
            Try to go to every city `j` which is NOT visited yet
        */
        for(int j = 0 ; j < n ; j ++){
            // Skip already visited cities
            if(mask & (1 << j)){
                continue; 
            }

            // Mark city j as visited
            int newMask = mask | (1 << j);

            // Recursively solve from city j
            int temp = solve(cost , newMask , j);

            /*
                If path is valid:
                Add the cost from current city (idx) to next city (j)
            */
            if(temp != INT_MAX){
                ans = min(ans, temp + cost[idx][j]);
            }
        }

        // Store result in dp table and return
        return dp[idx][mask] = ans; 
    }

    int tsp(vector<vector<int>>& cost) {
        // Initialize dp array with -1 (uncomputed states)
        memset(dp , -1 , sizeof(dp));

        /*
            Start TSP:
            - Start from city 0
            - Initially only city 0 is visited → mask = 0
        */
        return solve(cost , 0 , 0);
    }
};
