class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int target = n / 3;
        vector<int>ans;
        map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        
        for(auto it : mp){
            int val = it.first;
            int cnt = it.second;
            
            if(cnt > target){
                ans.push_back(val);
            }
        }
        
        
        return ans;
    }
};