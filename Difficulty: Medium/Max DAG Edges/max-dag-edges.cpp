class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
            vector<int> indegree(V, 0);
    vector<vector<int>> adj(V);

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    // Step 1: Topological sort using Kahn’s Algorithm
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    // Step 2: Map node -> position in topological order
    vector<int> pos(V);
    for (int i = 0; i < V; i++)
        pos[topo[i]] = i;

    // Step 3: Count existing forward edges
    int existingEdges = 0;
    for (auto &e : edges)
        if (pos[e[0]] < pos[e[1]])
            existingEdges++;

    // Step 4: Total possible edges in DAG
    int totalPossible = (V * (V - 1)) / 2;

    return totalPossible - existingEdges;
    }
};
