class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        // code here
          int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    q.push({i, j});
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, +1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    if (dist[nr][nc] == -1) {
                        dist[nr][nc] = dist[row][col] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return dist;
    }
};