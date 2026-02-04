class Solution {
  public:
    int maxOnes(vector<int>& nums, int k) {
        // code here
        int n = nums.size();
        
        int i = 0 , j = 0 , zero = 0;
        int ans = 0;
        
        while(j < n){
            if(nums[j] == 0){
                zero ++;
            }
            
            while(zero > k){
                if(nums[i] == 0){
                    zero --;
                }
                i ++;
            }
            
            ans = max(ans , j - i + 1);
            j ++;
        }
        
        return ans;
    }
};
