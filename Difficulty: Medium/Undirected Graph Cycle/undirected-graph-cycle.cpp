class Solution {
  public:
  
   bool dfs(int node , int parent ,auto &adj, auto &vis){
        vis[node] = 1;
        
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                if(dfs(ngbr , node , adj , vis)){
                    return true;
                }
            }else if(ngbr != parent){
                return true;
            }
        }
        
        return false;
   }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<int>vis(V , 0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0 ; i < V ; i ++){
            if(!vis[i]){
                if(dfs(i , -1 , adj , vis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};