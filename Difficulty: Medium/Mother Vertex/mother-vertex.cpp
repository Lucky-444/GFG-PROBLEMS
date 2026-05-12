class Solution {
public:
    
    void dfs(int node , vector<int> adj[] , vector<int> &vis){
        vis[node] = 1;

        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it , adj , vis);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V , 0);

        int candidate = -1;

        // Step 1: Find candidate
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , adj , vis);
                candidate = i;
            }
        }

        // Step 2: Verify candidate
        fill(vis.begin() , vis.end() , 0);

        dfs(candidate , adj , vis);

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                return -1;
            }
        }

        return candidate;
    }
};