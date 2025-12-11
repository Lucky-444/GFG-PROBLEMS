class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // code here
        // code here
        int n = matrix.size();
         for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        return matrix;
    }
};