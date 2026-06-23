class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
          int r=0;
          int c=0;
          int currDir=0;
          vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
          
          while(r>=0 && c>=0 && r<mat.size() && c<mat[0].size()){
              if(mat[r][c] == 1){
                  currDir = (currDir + 1) % 4;
                  mat[r][c] = 0;
              }
              r+=dir[currDir].first;
              c+=dir[currDir].second;
          }
          
          r -= dir[currDir].first;
          c -= dir[currDir].second;
          
          return {r,c};
    }
};