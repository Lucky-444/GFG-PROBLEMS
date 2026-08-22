class Solution {
public:
    int numberOfCells(int r, int c, int u, int d,
                      vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // Starting cell is blocked
        if (mat[r][c] == '#')
            return 0;

        // dist[i][j] = minimum upward moves needed
        // to reach cell (i, j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        deque<pair<int, int>> dq;

        dist[r][c] = 0;
        dq.push_front({r, c});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                // Outside the maze
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                // Obstacle
                if (mat[nx][ny] == '#')
                    continue;

                // Moving UP costs 1
                int cost = (nx < x);

                int newUp = dist[x][y] + cost;

                if (newUp >= dist[nx][ny])
                    continue;

                // We cannot use more than u upward moves
                if (newUp > u)
                    continue;

                // From:
                // nx = r - up + down
                //
                // down = nx - r + up
                int newDown = newUp + (nx - r);

                // Downward limit exceeded
                if (newDown > d)
                    continue;

                // Down can never be negative
                if (newDown < 0)
                    continue;

                dist[nx][ny] = newUp;

                // 0 cost -> front
                // 1 cost -> back
                if (cost == 0)
                    dq.push_front({nx, ny});
                else
                    dq.push_back({nx, ny});
            }
        }

        // Count all cells that can be reached
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (dist[i][j] == INT_MAX)
                    continue;

                int up = dist[i][j];

                // down = up + (i-r)
                int down = up + (i - r);

                if (up <= u && down <= d)
                    ans++;
            }
        }

        return ans;
    }
};