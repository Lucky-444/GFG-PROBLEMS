class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int ,int>mp;
        int n = arr.size();
        mp[0] = -1;
        
        int ans = 0 ;
        
        int rem = 0 ,  sum = 0;
        
        for(int i = 0 ; i < n ; i ++){
            sum += arr[i];
            
            rem = sum - k ;
            
            if(mp.count(rem)){
                ans = max(ans , i - mp[rem]);
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        return ans ;
    }
};