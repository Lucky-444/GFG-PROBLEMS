class Solution {
  public:
    int countSubarray(vector<int>& arr) {
        // code here
        //make array all 0's to -1's
        
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        int sum = 0 , cnt = 0 ;
        unordered_map<int ,int>mp;
        
        mp[0] = 1;
        
        for(int i = 0; i < arr.size() ; i++){
            sum += arr[i];
            
           // if this prefix sum seen before, it means there exists a subarray with sum 0
            if(mp.find(sum) != mp.end()) {
                cnt += mp[sum];
            }
            
            mp[sum] ++;
        }
        
        return cnt;
    }
};