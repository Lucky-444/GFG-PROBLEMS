class Solution {
public:
    
    // returns row index of maximum element in a column
    int maxRow(vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][col] > mat[idx][col]) {
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int row = maxRow(mat, mid);

            int left  = (mid - 1 >= 0) ? mat[row][mid - 1] : INT_MIN;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : INT_MIN;

            if (mat[row][mid] >= left && mat[row][mid] >= right) {
                return {row, mid};
            }

            if (right > mat[row][mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};
