class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        // code here
        // dp[r] = true means there exists a NON-EMPTY subset
        // whose sum gives remainder 'r' when divided by k.
        vector<bool> dp(k, false);

        // Process every element one by one.
        for (int x : arr) {

            // Create a copy of the previous DP.
            // We update this copy so that the current element
            // is used only once in this iteration.
            vector<bool> ndp(dp);

            // Case 1:
            // Start a brand new subset containing only x.
            // Its remainder will be x % k.
            ndp[x % k] = true;

            // Case 2:
            // Add x to every previously possible subset.
            for (int r = 0; r < k; r++) {

                // If a subset with remainder r already exists...
                if (dp[r]) {

                    // ...then after adding x, the new remainder becomes:
                    // (old remainder + x) % k
                    ndp[(r + x) % k] = true;
                }
            }

            // Save the updated DP for the next iteration.
            dp = ndp;

            // If remainder 0 is possible,
            // then some non-empty subset sum is divisible by k.
            if (dp[0])
                return true;
        }

        // No subset with remainder 0 was found.
        return false;
    }
};