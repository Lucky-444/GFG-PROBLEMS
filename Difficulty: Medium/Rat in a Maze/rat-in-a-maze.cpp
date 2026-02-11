class Solution {
  public:
    vector<int> dx = {1, 0, 0, -1};   // D, L, R, U
    vector<int> dy = {0, -1, 1, 0};
    
    int n, m;
    vector<string> ans;
    vector<vector<int>> vis;
    
    void solve(int i, int j, vector<vector<int>>& maze, string &move) {
        
        // Base case: reached destination
        if(i == n - 1 && j == m - 1) {
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && nj >= 0 && ni < n && nj < m 
               && !vis[ni][nj] && maze[ni][nj] == 1) {
                   
                vis[ni][nj] = 1;
                move.push_back(dir[k]);
                
                solve(ni, nj, maze, move);
                
                move.pop_back();      // backtrack
                vis[ni][nj] = 0;      // unmark
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        n = maze.size();
        m = maze[0].size();
        
        vis.assign(n, vector<int>(m, 0));
        ans.clear();
        
        if(maze[0][0] == 0) return ans;
        
        string temp = "";
        
        vis[0][0] = 1;     
        solve(0, 0, maze, temp);
        
        return ans;
    }
};
