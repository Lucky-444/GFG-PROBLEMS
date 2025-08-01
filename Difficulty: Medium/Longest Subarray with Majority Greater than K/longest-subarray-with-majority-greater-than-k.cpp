class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        //make validation of array
        /***
         * vector<int>diff(n , -1);
         * if(arr[i] > k) -> diff[i] = 1;
        */
        int n = arr.size();
        vector<int>diff(n , -1);
        
        for(int i = 0;  i < n ; i++){
            if(arr[i] > k){
                diff[i] = 1;
            }
        }
        
        unordered_map<int ,int>mp;
       
        
        //now take the prefix sum
        int prefix_sum = 0 , maxLen = 0;
        
        for(int i = 0; i < n ; i++){
            prefix_sum += diff[i];
            
            if(prefix_sum > 0){
                //if prefix sum > 0 
                //then we have found a larger subarray with length i + 1
                maxLen = i + 1;
            }
            else{
                if(mp.find(prefix_sum - 1) != mp.end()){
                    maxLen = max(maxLen , i - mp[prefix_sum - 1]);
                }
            }
            
            if(mp.find(prefix_sum) == mp.end()){
                mp[prefix_sum] = i;
            }
        }
        
        return maxLen;
        
    }
};