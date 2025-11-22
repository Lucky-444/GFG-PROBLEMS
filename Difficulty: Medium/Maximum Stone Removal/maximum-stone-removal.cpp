class Solution {
  public:
  // Using DFS
    vector<vector<int>>s;
    int n ;
    void DFS(int idx, auto &vis){
        vis[idx] = 1;

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(s[idx][0] == s[i][0] || s[idx][1] == s[i][1]){
                    DFS(i , vis);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        s = stones;
        n = s.size();

        //Now start Iterating From 0 - n
        vector<int>vis(n , 0);
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                DFS(i , vis);
                cnt ++;
            }
        } 

        return  n - cnt; 
    }
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        return removeStones(stones);
    }
};