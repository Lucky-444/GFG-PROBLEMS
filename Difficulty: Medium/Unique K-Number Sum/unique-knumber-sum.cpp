class Solution {
  public:
    vector<vector<int>>ans;
    void solve(int start , int n , int k , vector<int>&temp){
        if(n == 0 && k == 0){
            ans.push_back(temp);
            return  ;
        }
        
        if(n < 0 || k < 0){
            return ;
        }
        
        for(int i = start ; i <= 9 ; i ++){
            temp.push_back(i);
            
            solve(i + 1 , n - i  , k - 1  , temp);
            
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<int> temp;
        solve(1, n, k, temp);
        return ans;
    }
};