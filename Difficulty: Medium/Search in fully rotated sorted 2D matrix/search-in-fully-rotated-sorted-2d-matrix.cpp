class Solution {
  public:
    bool searchMatrix(vector<vector<int>>&mat, int x) {
        // code here
           // code here
        for(int i=0;i<mat.size();i++){       // i row search
            for(int j=0;j<mat[0].size();j++){     // j row search
                if(mat[i][j]==x){
                    return true;
                }
            }
        }
        return false;
    }
};
