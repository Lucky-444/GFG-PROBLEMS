class Solution {
  public:
    void helper(int left,int right,int &ans){
        if(left == 0 && right ==0){
            ans++;
        }
        if(left>right) return;
        if(left > 0){
            helper(left-1,right,ans);
        }
        if(right>0){
            helper(left,right-1,ans);
        }
    }
    int findWays(int n) {
        // code here
        if((n%2)!=0) return 0;
        int ans = 0;
        helper(n/2,n/2,ans);
        return ans;
        
    }
};