class Solution {
  public:
    //BACKTRACK With Optimization
    void solve(int idx ,int num , int n, vector<int>&ans){
        if(idx == n){
            ans.push_back(num);
            return ;
        }
        
        int rem = num % 10;
        
        for(int d = rem + 1 ; d <= 9 ; d ++){
            solve(idx + 1 , (num * 10 + d) , n , ans);
        }
        
        return;
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int> ans;
        if(n==1)
        ans.push_back(0);
      
        solve(0, 0, n, ans);
          
        return ans;
    }
};