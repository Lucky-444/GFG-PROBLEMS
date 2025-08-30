class Solution {
  public:
    // Function to find a continuous subarray with the given sum
    vector<int> subarraySum(vector<int>& nums, int targetSum) {
        int n = nums.size();
        int currentSum = 0;
        int start = 0;
    
        // Use a sliding window approach
        for (int end = 0; end < n; end++) {
            currentSum += nums[end];
    
            // Shrink the window from the left until the current sum is less than or equal to the target sum
            while (currentSum > targetSum && start <= end) {
                currentSum -= nums[start];
                start++;
            }
    
            // If the current sum is equal to the target sum, return the indices of the subarray
            if (currentSum == targetSum) {
                return {start + 1, end + 1}; // Return 1-based indices as per the problem statement (convention)
            }
        }
    
        // If no such subarray exists, return {-1}
        return {-1};
    }

};