

// Function to find the maximum possible amount of money we can win.
class Solution {
  public:
   int dp[1001][1001];
    int f(vector<int>&a ,int s, int e){
        if(s > e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int sum1 = a[s] , sum2 = a[e];
        
        sum1 += min(f(a,s + 2,e) ,f(a, s + 1 , e - 1));//in this we manage for both players
        sum2 += min(f(a, s + 1, e - 1 ), f(a, s, e - 2));
        
        return  dp[s][e] = max(sum1, sum2);
        
    }
    int maximumAmount(vector<int> &arr) {
        // Your code here
        memset(dp,-1,sizeof(dp));
        return f(arr , 0 , arr.size() - 1) ;
    }
};