class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size(); 
        int i = 0 , j = 0 , sum = 0 ;
        
        unordered_map<int ,int>mp ;
        
        int ans = INT_MIN ; 
        
        while(j < n){
            sum += arr[j]; 
            
            while(j - i + 1 > k){
                sum -= arr[i];
                i ++;
            }
            
            if(j - i + 1 == k){
                ans = max(ans , sum);
            }
            
            j ++;
        }
        
        return ans;
    }
};