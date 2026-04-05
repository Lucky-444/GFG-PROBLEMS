// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(n , 1e8);
        dist[src] = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }
};
