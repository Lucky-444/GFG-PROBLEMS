class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        //Just Traverse From Last to forst 
        int n = prices.size();
        int ans = 0 , val = 0;
        for(int i = n - 1 ; i >= 0 ; i --){
            val = max(val , prices[i]);
            
            ans = max(ans , val - prices[i]);
        }
        
        return ans;
    }
};
