class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> left(n, vector<bool>(m, false));
        vector<vector<bool>> right(n, vector<bool>(m, false));
        vector<vector<bool>> up(n, vector<bool>(m, false));
        vector<vector<bool>> down(n, vector<bool>(m, false));

        // Left
        for (int i = 0; i < n; i++) {
            bool seen = false;
            for (int j = 0; j < m; j++) {
                left[i][j] = seen;
                if (mat[i][j] == 1) seen = true;
            }
        }

        // Right
        for (int i = 0; i < n; i++) {
            bool seen = false;
            for (int j = m - 1; j >= 0; j--) {
                right[i][j] = seen;
                if (mat[i][j] == 1) seen = true;
            }
        }

        // Up
        for (int j = 0; j < m; j++) {
            bool seen = false;
            for (int i = 0; i < n; i++) {
                up[i][j] = seen;
                if (mat[i][j] == 1) seen = true;
            }
        }

        // Down
        for (int j = 0; j < m; j++) {
            bool seen = false;
            for (int i = n - 1; i >= 0; i--) {
                down[i][j] = seen;
                if (mat[i][j] == 1) seen = true;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans += left[i][j];
                    ans += right[i][j];
                    ans += up[i][j];
                    ans += down[i][j];
                }
            }
        }

        return ans;
    }
};