class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        unordered_map<long long, int> mp;
        
        long long sum = 0;
        
        // Important: prefix sum 0 at index -1
        mp[0] = -1;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            // check if subarray exists
            if (mp.find(sum - target) != mp.end()) {
                int start = mp[sum - target] + 1;
                int end = i;
                
                return {start + 1, end + 1}; // 1-based indexing
            }
            
            // store only first occurrence (important for leftmost)
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return {-1};
    }
};