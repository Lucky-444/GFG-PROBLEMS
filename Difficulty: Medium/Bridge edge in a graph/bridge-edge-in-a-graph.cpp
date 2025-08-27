//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        if (vis[node]) return;
        
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        //count the connected components
        // Step 1: Build the undirected adjacency list
        vector<int> adj[V];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        // Step 2: Count initial connected components
        int cnt = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
    
        // Step 3: Remove edge (c, d) and (d, c)
        vector<int> adjList[V];
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            if ((u == c && v == d) || (u == d && v == c)) continue;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Step 4: Count connected components after removing the edge
        int newCnt = 0;
        vis = vector<int>(V, 0); // Reset and resize vis properly
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                newCnt++;
                dfs(i, adjList, vis);
            }
        }

        // If number of components increases, (c, d) is a bridge
        return newCnt > cnt;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends