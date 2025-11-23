class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int ,int>mp;
        int n = arr.size() ;
        
        mp[0] = -1;
        
        int ans = 0 , sum = 0 ;
        
        for(int i = 0; i < n ; i ++){
            sum += arr[i];
            
            if(mp.count(sum)){
                ans = max(ans , i - mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        
        return ans; 
    }
};