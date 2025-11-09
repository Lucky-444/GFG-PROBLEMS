class Solution {
  public:
  
    vector<vector<vector<long long>>>dp;
    long long recur(vector<int>&prices, int idx, int cooldown, int buy) {
        if(idx>=prices.size()) {
            return 0;
        }
        
        if(dp[idx][cooldown][buy]!=-1) {
            return dp[idx][cooldown][buy];
        }
        if(cooldown!=0) {
            return dp[idx][cooldown][buy] = recur(prices,idx+1,cooldown-1,buy);
        } else {
            if(buy) {
                long long take= recur(prices,idx+1,cooldown,0)-prices[idx];
                long long didnot = recur(prices,idx+1,cooldown,buy);
                return dp[idx][cooldown][buy] = max(take,didnot);
            } else {
                long long sold=recur(prices,idx+1,1,1)+prices[idx];
                long long didnot=recur(prices,idx+1,cooldown,buy);
                return dp[idx][cooldown][buy] = max(sold,didnot);
            }
        }
    }
    int maxProfit(vector<int>& prices) {
        // Code here
        int n = prices.size();
        long long sample=-1;
        dp=vector<vector<vector<long long>>>(n+1,vector<vector<long long>>(2,vector<long long>(3,sample)));
        return recur(prices,0,0,true);
    }
};