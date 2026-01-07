class Solution {
  public:
    int solve(vector<int>&arr , int k){
        int i = 0 , j = 0 , n = arr.size();
        int cnt = 0; 
        int ans = 0 ;
        
        while(j < n){
            cnt += (arr[j] & 1);
            
            while(cnt > k){
               
                cnt -= (arr[i] & 1);
                i ++;
            }
            
            ans += (j - i + 1);
                
            j ++;
        }
        
        return ans; 
    }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        //for exactlyK = atmost(k) - atmost(k - 1);
        
        return solve(arr , k) - solve(arr , k - 1);
    }
    
};