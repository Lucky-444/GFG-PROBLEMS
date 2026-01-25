class Solution {
  public:
    vector<vector<int>>ans;
    void solve(auto &arr , int idx){
        int n = arr.size();
        if(idx == n){
            ans.push_back(arr);
            return ;
        }
        
        for(int i = idx ; i < n ; i ++){
            swap(arr[idx] , arr[i]);
            solve(arr , idx + 1);
            swap(arr[idx] , arr[i]);
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        solve(arr , 0);
        
        return ans;
    }
};