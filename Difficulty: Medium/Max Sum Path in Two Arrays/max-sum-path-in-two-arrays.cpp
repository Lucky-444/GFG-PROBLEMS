class Solution {
  public:
    const int MOD = 1e9 + 7;
    int n1, n2;

    // Maps to store last occurrence index of each element in nums1 and nums2
    unordered_map<int, int> idx1, idx2;

    // DP table: dp[index][type], where type = 0 (nums1) or 1 (nums2)
    vector<vector<long long>> dp;

    // Recursive helper function with memoization
    long long helper(vector<int>& nums1, vector<int>& nums2, int index, int type) {
        // Base case: if index is out of bounds for the current array
        if ((type == 0 && index >= n1) || (type == 1 && index >= n2)) 
            return 0;

        // Return cached result if already computed
        if (dp[index][type] != -1) 
            return dp[index][type];

        // Current value depending on type
        int currentVal = (type == 0) ? nums1[index] : nums2[index];

        // Step 1: Continue in the same array
        long long maxSum = currentVal + helper(nums1, nums2, index + 1, type);

        // Step 2: Try switching to the other array at the same value (if exists)
        if (type == 0 && idx2.count(currentVal)) {
            maxSum = max(maxSum, currentVal + helper(nums1, nums2, idx2[currentVal] + 1, 1));
        } 
        else if (type == 1 && idx1.count(currentVal)) {
            maxSum = max(maxSum, currentVal + helper(nums1, nums2, idx1[currentVal] + 1, 0));
        }

        // Memoize and return
        return dp[index][type] = maxSum;
    }

    int maxPathSum(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();

        // Build index maps for quick jump across arrays
        for (int i = 0; i < n1; i++) 
            idx1[nums1[i]] = i;
        for (int i = 0; i < n2; i++) 
            idx2[nums2[i]] = i;

        // Initialize DP table with -1
        dp.assign(max(n1, n2), vector<long long>(2, -1));

        // Try both starting from nums1 and nums2
        long long result = max(
            helper(nums1, nums2, 0, 0),
            helper(nums1, nums2, 0, 1)
        );

        return result % MOD;
    }
};