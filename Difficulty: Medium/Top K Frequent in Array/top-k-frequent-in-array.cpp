class Solution {
  public:
    vector<int> topKFreq(vector<int> &nums, int k) {
        // Code here
         vector<int>v;
        int n=nums.size();
        vector<pair<int, int>>u;
        unordered_map<int, int>m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(auto it : m){
            u.push_back({it.second, it.first});
        }
        sort(u.begin(), u.end());
        int len=u.size();
        for(int j=len-1; j>len-1-k; j--){
            v.push_back(u[j].second);
        }
        return v;
    }
};
