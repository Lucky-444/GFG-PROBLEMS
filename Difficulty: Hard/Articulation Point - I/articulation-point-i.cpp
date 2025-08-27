// User function Template for C++

class Solution {
    private:
    int timer;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int> &dis, vector<int> &low,
             vector<int> &vis, vector<int> &Apoints, vector<bool> &isArticulation) {
        vis[node] = 1;
        dis[node] = low[node] = timer++;
        int child = 0;
        
        for (const auto &it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                child++;
                dfs(it, node, adj, dis, low, vis, Apoints, isArticulation);
                low[node] = min(low[node], low[it]);
                
                if (low[it] >= dis[node] && parent != -1 && !isArticulation[node]) {
                    Apoints.push_back(node);
                    isArticulation[node] = true;
                }
            } else {
                low[node] = min(low[node], dis[it]);
            }
        }

        if (parent == -1 && child > 1 && !isArticulation[node]) {
            Apoints.push_back(node);
            isArticulation[node] = true;
        }
    }

    public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        timer = 0;
        vector<int> dis(V, 0), low(V, 0), vis(V, 0);
        
        vector<int> Apoints;
        vector<bool> isArticulation(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, dis, low, vis, Apoints, isArticulation);
            }
        }
        
        if (Apoints.empty()) {
            return {-1};
        }

        sort(Apoints.begin(), Apoints.end()); 
        return Apoints;
    }
};