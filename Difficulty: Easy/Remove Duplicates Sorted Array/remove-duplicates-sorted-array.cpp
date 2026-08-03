class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        vector<int>ans;
        
        ans.push_back(arr[0]);
        
        for(int i = 1 ; i < arr.size() ; i ++){
            if(arr[i] == ans.back()) continue; 
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};