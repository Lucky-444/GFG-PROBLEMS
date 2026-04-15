class Solution {
  public:
  int solve(int i,int n,int k,vector<int>&dp,vector<int>&arr){
      if(i==n-1){
          return 0; // Reach The Last Stone
      }
      
      if(dp[i]!=-1){
          return dp[i];
      }
      
      int ans=INT_MAX;
      for(int j=1;j<=k;j++){
          if(i+j<n){
              int dist = abs(arr[i] - arr[i + j]);
              ans=min(ans,solve(i+j,n,k,dp,arr) + dist);
          }
      }
      return dp[i]=ans;
  }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int>dp(arr.size()+1,-1);
        int n=arr.size();
        return solve(0,n,k,dp,arr);
    }
};