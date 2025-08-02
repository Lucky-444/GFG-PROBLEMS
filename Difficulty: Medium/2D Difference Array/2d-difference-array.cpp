class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>diff(n + 2 , vector<int>(m + 2 , 0));
        
        for(auto it : opr){
            int v = it[0];
            int r1 = it[1];
            int c1 = it[2];
            int r2 = it[3];
            int c2 = it[4];
            
            diff[r1][c1] += v;
            diff[r1][c2 + 1] -= v;
            diff[r2 + 1][c1] -= v;
            diff[r2 + 1][c2 + 1] += v;
        }
        
              // Compute prefix sum on the diff array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) diff[i][j] += diff[i - 1][j];
                if (j > 0) diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];
            }
        }

        // Add updates to original matrix
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = mat[i][j] + diff[i][j];
            }
        }

        return res;
        
    }
};