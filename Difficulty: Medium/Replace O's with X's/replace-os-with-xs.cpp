class Solution {
  public:
     int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int n ,m;
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int idx,int idy){
        
       vis[idx][idy] = 1 ;
        
        for(int i=0;i<4;i++)
        {
            int nx = idx + dx[i];
            int ny = idy + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 'O' && !vis[nx][ny]){
                
                dfs(grid,vis,nx,ny);
            }
        }
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0 ;i<n;i++){
           
                if(mat[i][0] == 'O' && !vis[i][0]){
                    dfs(mat,vis,i,0);
                }
                if(mat[i][m-1] == 'O' && !vis[i][m-1]){
                    dfs(mat,vis,i,m-1);
                }
           
        }
        for(int j = 0;j<m;j++){
            if(mat[0][j] == 'O' && !vis[0][j]){
                dfs(mat,vis,0,j);
            }
            
            if(mat[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(mat,vis,n-1,j);
            }
        }
        
        for(int i= 0 ;i<n;i++){
            for(int j = 0; j<m;j++){
                if(mat[i][j] == 'O' && !vis[i][j]){
                    mat[i][j] = 'X';
                }
            }
        }
        
        
        
        
    }
};