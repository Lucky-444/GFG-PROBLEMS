class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        // (a + b) % k == 0
        // ==> (a % k + b % k) % k == 0
        // ==> remA + remB == 0;
        
    
        
        unordered_map<int , int>mp;

        int ans = 0;
        for(auto it : arr){
            int rem = (it % k);
            
            int complement = (k - rem) % k;
            
            ans += mp[complement];
            
            mp[rem] ++;
        }
        
        return ans;
        
    }
};