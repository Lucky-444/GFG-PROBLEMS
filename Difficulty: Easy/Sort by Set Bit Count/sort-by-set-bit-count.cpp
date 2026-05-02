class Solution {
  public:
    using P = pair<int , int>;
    int solve(int x){
        return __builtin_popcount(x);
    }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        vector<P>ans;
        
        int n = arr.size();
        
        for(int i = 0; i < n ; i++){
            int cnt = solve(arr[i]);
            ans.push_back({cnt , arr[i]});
        }
        
        // Sort by set bits in DESCENDING order
        // Use stable_sort to maintain relative order
        stable_sort(ans.begin(), ans.end(), [](const P &a, const P &b){
            return a.first > b.first;  // descending
        });

        // Extract result
        vector<int> res;
        for(auto &p : ans){
            res.push_back(p.second);
        }

        return res;
        
    }
};