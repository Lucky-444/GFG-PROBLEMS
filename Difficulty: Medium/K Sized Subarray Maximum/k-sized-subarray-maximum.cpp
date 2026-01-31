class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int> mp;
        
        // first window
        for (int i = 0; i < k; i++) {
            mp[arr[i]]++;
        }
        
        vector<int> ans;
        ans.push_back(mp.rbegin()->first);  // max of first window
        
        // sliding window
        for (int i = k; i < n; i++) {
            mp[arr[i - k]]--;
            if (mp[arr[i - k]] == 0)
                mp.erase(arr[i - k]);
            
            mp[arr[i]]++;
            ans.push_back(mp.rbegin()->first);
        }
        
        return ans;
    }
};
