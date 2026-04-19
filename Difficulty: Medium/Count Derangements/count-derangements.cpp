class Solution {
  public:
   int fun(vector<int>& dp,int n){
      if(n<=3){
          return n-1;
      }
      if(dp[n]!=-1) return dp[n];
      if(n%2==0){
          return dp[n]=(n*fun(dp,n-1))+1;
      }
      return dp[n]=(n*fun(dp,n-1))-1;
  }
    int countDer(int n) {
        vector<int> dp(n+1,-1);
        int ans=fun(dp,n);
        return ans;
    }
    int derangeCount(int n) {
        // code here
        return countDer(n);
    }
};