class Solution {
  public:
          const int MOD = 1e9 + 7;
    int fun(vector<int> &arr,int target,int i,int n,vector<vector<int>> &dp)
    {
        //base case
        if(target==0)
        {
            return 1;
        }
        
        if(target <  0){
            return 0;
        }
        //edge case
        if(i>=n){
            return 0;
        }
        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }
        
        int take=0;
        take= fun(arr,target-arr[i],i+1,n,dp)%MOD;
    
        int nottake=fun(arr,target,i+1,n,dp)%MOD;
        return dp[i][target]=(take+nottake)%MOD;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total=total+arr[i];
        }
        if((d+total)%2!=0)//if partition is odd
        {
            return 0;
        }
        
        
        sort(arr.begin(),arr.end());
        int target=(d+total)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return fun(arr,target,0,n,dp);
        // Code here
    }
};