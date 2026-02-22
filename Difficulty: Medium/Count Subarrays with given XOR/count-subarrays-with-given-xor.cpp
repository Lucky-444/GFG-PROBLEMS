class Solution {
  public:
    long subarrayXor(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        
        mp[0] = 1;   // Important initialization
        
        int xr = 0;
        long cnt = 0;
        
        for(int i = 0; i < n; i++){
            xr ^= nums[i];
            
            int target = xr ^ k;
            
            if(mp.find(target) != mp.end()){
                cnt += mp[target];
            }
            
            mp[xr]++;
        }
        
        return cnt;
    }
};