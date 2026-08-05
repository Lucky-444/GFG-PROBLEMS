class Solution {
  public:
    int solve(vector<int>&nums , int k){
        int n = nums.size();
        int i = 0, j = 0 , ans = 0 , sum = 0;
        
        while(j < n){
            sum += nums[j];
            
            while(sum > k){
                sum -= nums[i];
                i ++;
            }
            
            ans += (j - i + 1);
            j ++;
        }
        
        return ans;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        // Count(sum ≤ r) - Count(sum < l)
        // Count(sum ≤ r) - Count(sum <= l - 1);
        
        return solve(arr , r) - solve(arr , l - 1);
    }
};