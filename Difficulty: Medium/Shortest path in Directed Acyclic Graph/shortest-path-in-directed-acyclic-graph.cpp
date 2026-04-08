class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V, 0);
        
        // Step 1: Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            indegree[v]++;
        }
        
        // Step 2: Kahn's Topological Sort
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            
            for(auto &it : adj[u]) {
                int v = it.first;
                indegree[v]--;
                
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Step 3: Shortest Path using topo order
        vector<int> dist(V, 1e9);
        dist[0] = 0;   // source = 0
        
        for(int u : topo) {
            if(dist[u] != 1e9) {
                for(auto &it : adj[u]) {
                    int v = it.first;
                    int wt = it.second;
                    
                    if(dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        
        // Step 4: Handle unreachable nodes
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};