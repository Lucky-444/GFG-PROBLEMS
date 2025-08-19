class Solution {
  public:
    int dp[205][205];
    int solve(auto &arr , int i ,int j){
        //base case
        if(i + 1 == j){
            //what is the base case see at last
            //only 2 values left 
            return 0;
        }
        
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        //partition in between i , j
        int ans = INT_MAX;  
        for(int k = i + 1 ; k < j ;  k ++){
            int mul = arr[i] * arr[k] * arr[j];
            int next = solve(arr , i  ,k ) + solve(arr , k  , j);
            
            int oprn = mul + next;
            
            ans = min(ans , oprn);
        }
        
        return dp[i][j] =  ans;
        
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        memset(dp , - 1 , sizeof(dp));
        int n = arr.size();
        return solve(arr , 0 , n - 1);
    }
};