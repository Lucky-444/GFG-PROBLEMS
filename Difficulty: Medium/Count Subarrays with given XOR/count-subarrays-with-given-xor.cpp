class Solution {
  public:
    long subarrayXor(vector<int> &nums, int k) {
        // code here
        int n=nums.size();
        unordered_map<int,int>mp;
        int xr=0, cnt=0;
        for(int i=0;i<n;i++){
            xr=xr ^ nums[i];
            if(xr == k) cnt++;
            
            int target=xr ^ k;
            if(mp.find(target)!= mp.end()){
                cnt+=mp[target];
            }
            
            mp[xr]++;
        }
        
        return cnt;
    }
};