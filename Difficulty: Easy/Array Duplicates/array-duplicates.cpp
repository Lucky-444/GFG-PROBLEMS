class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int , int>mp; 
        
        vector<int>ans; 
        
        for(auto it : arr){
           mp[it] ++;
        }
        
        for(auto [val , cnt] : mp){
            if(cnt >= 2){
                ans.push_back(val);
            }
        }
        
        
        
        return ans;
    }
};