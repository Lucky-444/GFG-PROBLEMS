class Solution {
public:
    int largestArea(int n, int m, vector<vector<int>>& arr) {

        vector<int> rows, cols;

        // Store blocked rows and columns
        for (auto &cell : arr) {
            rows.push_back(cell[0]);
            cols.push_back(cell[1]);
        }

        // Add virtual boundaries
        rows.push_back(0);
        rows.push_back(n + 1);

        cols.push_back(0);
        cols.push_back(m + 1);

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRows = 0, maxCols = 0;

        // Find largest consecutive unblocked rows
        for (int i = 1; i < rows.size(); i++) {
            maxRows = max(maxRows, rows[i] - rows[i - 1] - 1);
        }

        // Find largest consecutive unblocked columns
        for (int i = 1; i < cols.size(); i++) {
            maxCols = max(maxCols, cols[i] - cols[i - 1] - 1);
        }

        return maxRows * maxCols;
    }
};