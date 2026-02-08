// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int ans = INT_MAX; 
        
        int sum = 0 ;
        
        for(auto it : a){
            sum += it;
            
            ans = min(ans , sum);
            
            if(sum > 0){
                sum = 0; // if sum > 0 then we start a fresh new subarray from here
                
            }
        }
        
        return ans;    
    }
};
