class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int dp0 = arr[0]; //No Deletion
        int dp1 = 0; //One Deletion
        int ans = arr[0];
        
        for(int i = 1 ; i < arr.size() ; i ++){
            int newDp1 = max(dp1 + arr[i] , dp0) ;//Max Subarray Till NOw With Deletion
            //If i Do One Deletion then we does not consider current Element 
            //So we take Maximum Till Now 
            //so DP0
            //if we have already performed a deletion then extend That only
            int newDp0 = max(dp0 + arr[i] , arr[i]) ; // This Is Normal kadane Algorithm
            //Extend Current or Create started a New Subarray
            
            dp0 = newDp0;
            dp1 = newDp1;
            
            ans = max({ans , dp0 , dp1});
        }
        
        return ans;
    }
};