class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        
        //This is a fixed size sliding window qn 
        //first calculate k size window sum 
        
        int sum = 0;
        
        for(int i = 0 ; i < k ; i ++){
            sum += arr[i];
        }
        
        int ans = sum ;
        
        for(int i = k ; i < arr.size() ; i ++){
            sum -= arr[i - k];
            sum += arr[i];
            
            ans = max(ans ,sum);
        }
        
        return ans;
    }
};