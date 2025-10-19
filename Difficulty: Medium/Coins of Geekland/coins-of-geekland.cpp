class Solution {

  public:
    int Maximum_Sum(vector<vector<int>> &mat, int N, int K) {
        // Your code goes here
        //first Built the Prefix Matrix
        vector<vector<int>>prefix(N , vector<int>(N , 0));
        
        for(int i = 0; i < N ; i ++){
            for(int j = 0 ; j < N ; j ++){
                prefix[i][j] = mat[i][j];
                if(i > 0){
                    prefix[i][j] += prefix[i - 1][j]; // add top cell
                }
                
                if(j > 0){
                    prefix[i][j] += prefix[i][j - 1]; // add left cell
                }
                
                if(i > 0 && j > 0){
                    prefix[i][j] -= prefix[i - 1][j - 1]; // remove overlap
                }
            }
        }
        
        int maxSum = INT_MIN;
         for (int i = 0; i <= N - K; i++) {
            for (int j = 0; j <= N - K; j++) {

                int x2 = i + K - 1; // bottom row of KxK block
                int y2 = j + K - 1; // right col of KxK block

                int total = prefix[x2][y2];

                // subtract area above the submatrix
                if (i > 0)
                    total -= prefix[i - 1][y2];

                // subtract area left of the submatrix
                if (j > 0)
                    total -= prefix[x2][j - 1];

                // add back overlap (top-left area)
                if (i > 0 && j > 0)
                    total += prefix[i - 1][j - 1];

                maxSum = max(maxSum, total);
            }
        }

        return maxSum;
        
    }
};