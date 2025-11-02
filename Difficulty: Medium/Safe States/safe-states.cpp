class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        //using TOPO sort
        //reverse the edges
        vector<int>topo;
        vector<vector<int>>adj(V);
        vector<int>indegree(V , 0);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[v].push_back(u);
            indegree[u] ++;
        }
        
        queue<int>q;
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto v : adj[node]){
                if( -- indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        sort(topo.begin() , topo.end());
        
        return topo;
    }
};