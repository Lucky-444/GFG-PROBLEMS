// User function template for C++

class Solution {
  public:
    vector<int> maxSubMatrixSumQueries(vector<int> mat[], int n, int m,
                                       vector<pair<int, int>> &queries, int q) {
        // code here
        vector<vector<int>>prefix(n + 1 , vector<int>(m + 1 , 0)) ;
        
        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j <= m ; j++){
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j]+ prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        
        vector<int> res;

        for(auto it : queries){
            int r = it.first; 
            int c = it.second;
            
            int ans = INT_MIN;

            for(int i = 0 ; i + r <= n ; i++){
                for(int j = 0 ; j + c <= m ; j++){
                    int sumRect = prefix[i + r][j + c] 
                                - prefix[i + r][j] 
                                - prefix[i][j + c] 
                                + prefix[i][j];


                    ans = max(ans,  sumRect);
                }
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};