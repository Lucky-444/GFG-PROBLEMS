class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            int row = n-1;      // start at bottom-left
            int col = 0;
            int count = 0;
            
            while (row >= 0 && col < n) {
                if (mat[row][col] <= mid) {
                    count += row+1;
                    col++;
                }
                else {
                    row--;
                }
            }
            if (count < k) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        return low; 
    }
};
