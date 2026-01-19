class Solution {
  public:
    vector<int> countDistinct(vector<int> &nums, int k) {
        int n = nums.size();
    
        // Result array size = number of windows
        vector<int> ans(n - k + 1);
    
        // Hash map to store frequency of elements
        unordered_map<int, int> mp;
    
        // Step 1: Process first window of size k
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
    
        // Number of distinct elements in first window
        ans[0] = mp.size();
    
        int j = 1; // index for ans array
    
        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
    
            // Remove element going out of the window
            mp[nums[i - k]]--;
    
            // If frequency becomes zero, erase it
            if (mp[nums[i - k]] == 0) {
                mp.erase(nums[i - k]);
            }
    
            // Add new element entering the window
            mp[nums[i]]++;
    
            // Store count of distinct elements
            ans[j++] = mp.size();
        }
    
        return ans;
    }
};