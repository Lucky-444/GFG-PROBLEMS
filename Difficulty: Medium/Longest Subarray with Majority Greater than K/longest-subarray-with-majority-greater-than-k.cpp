class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        //Approach
        
        vector<int>diff(arr.size());
        
        for(int i = 0 ; i < arr.size() ; i ++){
            diff[i] = arr[i] > k ? 1 : -1 ; 
        }
        
        unordered_map<int , int>mp;
        // mp[0] = -1;
            
        int sum = 0;
        int maxLen = 0;
        for(int i = 0 ; i < arr.size() ; i ++){
            sum += diff[i];
            
            if(sum > 0){
                maxLen = i + 1;
            }
            else{
                if(mp.find(sum - 1) != mp.end()){
                    maxLen = max(maxLen , i - mp[sum - 1]);
                }
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        
        return maxLen ;
    }
};   