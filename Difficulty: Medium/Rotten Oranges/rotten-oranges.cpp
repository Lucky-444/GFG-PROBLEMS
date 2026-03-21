
class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // Code here
                      // Code here
               // Code here
      int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int fresh_orange = 0;
    int rows = mat.size();
    int cols = mat[0].size();
    
    queue<pair<int, int>> q;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 2) {
                q.push({i, j});
            } else if (mat[i][j] == 1) {
                fresh_orange++;
            }
        }
    }
    
    if (fresh_orange == 0) return 0;  // No fresh oranges to rot.
    
    int minutes = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            
            for (int i = 0; i < 4; i++) {
                int nr = x + dx[i];
                int nc = y + dy[i];
                
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && mat[nr][nc] == 1) {
                    q.push({nr, nc});
                    mat[nr][nc] = 2;
                    fresh_orange--;
                }
            }
        }
        minutes++;
    }
    
    return fresh_orange == 0 ? minutes - 1  : -1;;
    }
};

