class Solution {
  public:
    vector<vector<int>>ans;
    vector<vector<int>>vis;
    
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    int n , m;
    int solve(vector<vector<char>> &mat, string &word , int idx , int x , int y , int dir){
        if (idx == word.size())
            return true;

        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;

        if (vis[x][y])
            return false;

        if (mat[x][y] != word[idx])
            return false;

        vis[x][y] = 1;

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(solve(mat , word , idx + 1 , nx , ny , dir)){
            vis[x][y] = 0;
            return true;
        }
        
        vis[x][y] = 0;

        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        
        n = mat.size();
        m = mat[0].size();
        vis.assign(n, vector<int>(m, 0));

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                
                if(mat[i][j] == word[0]){
                    //Start Exploring on 8 direction
                    for(int d = 0 ; d < 8 ; d ++){
                        //Now do Backtrack Check for every Direction 
                        if(solve(mat,word, 0 , i , j , d)){
                            ans.push_back({i , j});
                            
                            //Why Break Becoz 
                            //From this Position i got one correct Answer 
                            //So that we take break here
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};