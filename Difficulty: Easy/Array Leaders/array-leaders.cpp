class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffix(n);
        
        suffix[n - 1] = arr[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], arr[i]);
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (arr[i] == suffix[i]) {
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};