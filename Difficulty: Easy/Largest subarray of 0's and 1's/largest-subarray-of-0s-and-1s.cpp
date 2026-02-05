class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        //Hashmap and Prefix Sum
        int n = arr.size();
        //First thought is make 0 to -1;
        for(int i = 0 ; i < arr.size() ; i ++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        
        int sum = 0 , ans = 0;
        unordered_map<int , int>mp;
        mp[0] = -1;
        
        for(int i = 0 ; i < n ; i ++){
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