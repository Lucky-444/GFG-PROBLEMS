class Solution {
  public:
    int n , m, l;
    bool dfs(int x,int y,int idx,vector<vector<char>>& mat, string& s){
        if(idx >= l){
            return 1;
        }
        
        if(x < 0 || y<0 || x >= n || y >= m || mat[x][y] != s[idx]){
            return false;
        }
        
        char temp = mat[x][y] ;
        mat[x][y] = '#';
        
        int dx[4] = {-1,0,1,0};
        int dy[4] ={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nx =  dx[i] + x;
            int ny = dy[i] + y;
            
            if(dfs(nx,ny,idx+1,mat,s)){
                return true;
            }
        }
        mat[x][y] = temp;
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        n = mat.size();
        m = mat[0].size();
        
        l= word.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                  if(dfs(i,j,0,mat,word)){
                      return true;
                  }
                }
            }
        }
        
        return false;
    }
};