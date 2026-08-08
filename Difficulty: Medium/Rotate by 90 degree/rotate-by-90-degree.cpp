class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        //First Reverse Each Row Then Transpose
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0 ; i < n ; i ++){
            reverse(mat[i].begin() , mat[i].end());
        }
        
        //Now DO transpose 
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j <= i ; j ++){
                swap(mat[i][j] , mat[j][i]);
            }
        }
    }
};
