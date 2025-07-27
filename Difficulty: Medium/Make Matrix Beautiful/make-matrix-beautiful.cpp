class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int>row(m + 1, 0) ,col(n + 1, 0);
        
        int maxSum = -1e8;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
                
                maxSum = max({maxSum , row[i], col[j]});
            }
        }
        
// To make matrix beautiful, we need to make all row and column sums equal to maxSum
        int oprn = 0;
        for(int i = 0 ; i < m ; i++){
            oprn += (maxSum - row[i]);
        }
        
        return oprn;
    }
};