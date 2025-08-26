class Solution {
  public:
    int countTriangles(vector<int>& nums) {
        // code here
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int c = 0;
        
        if(n < 3){
            return 0;
        }
        
        int ans = 0;
        
        for(int i = n - 1 ; i >= 0 ; i--){
            int target = nums[i];
            
            int l = 0 , r = i - 1;
            
            while(l < r){
                int sum = nums[l] + nums[r];
                
                if(sum > target){
                    ans += (r - l);
                    r--;
                }else{
                    l++;
                }
            }
        }
        
        return ans;
        
    }
};
