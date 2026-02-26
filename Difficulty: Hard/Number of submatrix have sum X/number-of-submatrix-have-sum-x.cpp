class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size();
    int m = mat[0].size();
    
    // Step 1: Build prefix matrix
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = mat[i - 1][j - 1]
                        + pref[i - 1][j]
                        + pref[i][j - 1]
                        - pref[i - 1][j - 1];
        }
    }
    
    int count = 0;
    
    // Step 2: Try all possible square submatrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            for (int size = 1; i + size <= n && j + size <= m; size++) {
                
                int r1 = i, c1 = j;
                int r2 = i + size - 1;
                int c2 = j + size - 1;
                
                int sum = pref[r2 + 1][c2 + 1]
                        - pref[r1][c2 + 1]
                        - pref[r2 + 1][c1]
                        + pref[r1][c1];
                
                if (sum == x)
                    count++;
            }
        }
    }
    
    return count;
    }
};