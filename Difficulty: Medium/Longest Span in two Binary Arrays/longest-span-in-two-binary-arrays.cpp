class Solution {
  public:
    int equalSumSpan(vector<int> &arr1, vector<int> &arr2) {
        // code here
        unordered_map<int,int>mp;
        mp[0] = -1;
        int maxLen =0;
        int n = arr1.size();
        int sum1 = 0, sum2 = 0;
        
        for(int i = 0;i<n;i++){
            sum1 += arr1[i];
            sum2 += arr2[i];
            int diff = sum1 - sum2;
           // If this difference has been seen before, calculate subarray length
            if (mp.find(diff) != mp.end()) {
                maxLen = max(maxLen, i - mp[diff]);
            } 
        else {
            mp[diff] = i; // Store first occurrence of this difference
        }
        
        }
        
        return maxLen; 
    }
};