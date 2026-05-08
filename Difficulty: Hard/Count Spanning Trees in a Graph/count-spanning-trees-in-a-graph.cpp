class Solution {
  public:
      long long determinant(vector<vector<double>> mat, int n) {

    double det = 1;

    for (int i = 0; i < n; i++) {

        int pivot = i;

        while (pivot < n && abs(mat[pivot][i]) < 1e-9) {
            pivot++;
        }

        if (pivot == n)
            return 0;

        // Row swap
        if (pivot != i) {
            swap(mat[pivot], mat[i]);
            det *= -1;
        }

        // Eliminate below
        for (int j = i + 1; j < n; j++) {

            double factor = mat[j][i] / mat[i][i];

            for (int k = i; k < n; k++) {

                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    // Multiply diagonals AFTER elimination
    for (int i = 0; i < n; i++) {
        det *= mat[i][i];
    }

    return round(det);
}

    int countSpanningTrees(int n, vector<vector<int>>& edges) {

        // Step 1: Adjacency Matrix
        vector<vector<int>> A(n, vector<int>(n, 0));

        // Step 2: Degree Matrix
        vector<vector<int>> D(n, vector<int>(n, 0));

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            A[u][v] = 1;
            A[v][u] = 1;

            D[u][u]++;
            D[v][v]++;
        }

        // Step 3: Laplacian Matrix
        vector<vector<int>> L(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                L[i][j] = D[i][j] - A[i][j];
            }
        }

        // Step 4: Remove last row and column
        vector<vector<double>> cofactor(n - 1,
                                        vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {

                cofactor[i][j] = L[i][j];
            }
        }

        // Step 5: Determinant
        return determinant(cofactor, n - 1);
    }
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // code here
        return countSpanningTrees(n , edges);
    }
};