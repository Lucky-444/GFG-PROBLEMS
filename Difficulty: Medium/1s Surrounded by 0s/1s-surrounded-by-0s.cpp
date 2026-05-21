class Solution {
  public:
      int n,m;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&grid){
        vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int nr=x+dx[i];
            int nc=y+dy[i];
            
            if(nr >= 0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,vis,grid);
            }
        }
        
        
    }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
       n=grid.size();
        m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    
                    if(!vis[i][j] && grid[i][j]==1){
                        dfs(i,j,vis,grid);
                    }
                }
                
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1 ){
                    cnt++;
                }
            }
        }
        
        return cnt; 
    }
};