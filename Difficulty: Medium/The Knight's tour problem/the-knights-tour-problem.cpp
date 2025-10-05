class Solution {
public:
    vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<vector<int>> board;
    int n;

    bool isSafe(int x, int y, int n) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }

    bool solve(int x, int y, int step) {
        if (step == n * n) return true; // all cells covered

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isSafe(nx, ny, n)) {
                board[nx][ny] = step;
                if (solve(nx, ny, step + 1)) return true;
                board[nx][ny] = -1; // backtrack
            }
        }
        return false;
    }

    vector<vector<int>> knightTour(int N) {
        n = N;
        board.resize(n, vector<int>(n, -1));
        board[0][0] = 0; //  starting point

        if (solve(0, 0, 1))
            return board;
        else
            return {{-1}};
    }
};
