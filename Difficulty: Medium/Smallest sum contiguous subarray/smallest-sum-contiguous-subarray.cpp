// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int ans = INT_MAX; 
        int i = 0 , j = 0 , n = a.size();
        int sum = 0;
        
        while(j  < n){
            sum += a[j];
            
            ans = min(ans , sum);
            
            if(sum > 0){
                sum = 0; //make sum to zero and start a new subaary from hee
            //start a new subarray from current position  
            }
            
            j ++;
        }
        
        return ans;
    }
};
