class Solution {
  public:
    int dp[16][(1 << 16) + 5];
    int solve(int idx, int mask , auto &c){
        int n = c.size();
        

        if(mask == (1 << n) - 1){
            //all are visited
            if(idx == 0){
                return 0;
            }else{
                return INT_MAX; 
            }
        }
        
        if(dp[idx][mask] != -1){
            return dp[idx][mask]; 
        }
        
        
        int  ans = INT_MAX ; 
        
        for(int j = 0 ; j < n ; j ++){
            if(mask & (1 << j)) continue ; 
            
            int temp = solve(j , (mask | (1 << j)) , c);
            
            if(temp != INT_MAX){
                ans = min(ans , temp + c[idx][j]) ; 
            }
            
        }
        
        return dp[idx][mask] =  ans ;
    }
    int tsp(vector<vector<int>>& cost) {
        // code here
        memset(dp , -1 ,sizeof(dp));
        return solve(0 , 0 , cost);
    }
};