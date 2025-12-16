class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& a) {
        // Code here
       sort(a.begin(),a.end());
       vector<vector<int>>ans;
       for(auto &it:a){
           if(ans.empty() ||it[0] > ans.back()[1]){
               ans.push_back(it);
           }
           else{
               ans.back()[1]=max(ans.back()[1],it[1]);
               
           }
       }
       return ans;
    }
};