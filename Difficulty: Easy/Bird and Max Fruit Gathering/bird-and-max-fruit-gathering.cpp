class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        //twice the arr
        
        vector<int>nums = arr;
        for(int i = 0 ; i < arr.size() ; i ++){
            nums.push_back(arr[i]);
        }
        
        //now findout the maximum m size subarray
        
        int sum = 0;
        
        for(int i = 0 ; i < m ; i ++){
            sum += nums[i];
        }
        
        int ans = sum;
        
        for(int i = m ; i < nums.size() ; i ++){
            sum -= nums[i - m];
            
            sum += nums[i];
            
            ans = max(ans , sum);
        }
        
        return ans;
        
        
    }
};