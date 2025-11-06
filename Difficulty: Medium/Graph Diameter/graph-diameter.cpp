class Solution {
  public:
    // using DFS
    int maxDist = -1;
    int farthestNode = -1;
    void DFS(auto &adj , int node ,int parent , int dist){
        if(dist > maxDist){
            maxDist = dist ; 
            farthestNode = node ; 
        }
        
        for(auto v : adj[node]){
            if(v == parent){
                continue ;
            }
            
            DFS(adj , v, node , dist + 1);
        }
        
    }    

    int diameter(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(n);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        //start DFS from 0th node and Findout the farthest Node
        DFS(adj , 0 , - 1 ,0);
        int start = farthestNode ; 
        //now startDfs From that Farthest Node to Findout the another farthest Node
        DFS(adj , start , -1 , 0);
        
        
        return maxDist ; 
    }
};
