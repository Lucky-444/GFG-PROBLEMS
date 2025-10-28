class Solution {
  public:
        /*
     * -----------------------------
     * BFS FUNCTION — Breadth First Search
     * -----------------------------
     * Purpose:
     *   - Given an adjacency list 'adj' (a graph/tree),
     *   - and a starting node 'node',
     *   - this function finds the farthest node from 'node'
     *     and returns {that_node, distance_to_that_node}.
     *
     * Idea:
     *   - BFS explores level by level, so the last discovered node
     *     at the greatest distance is the farthest node in that traversal.
     */
    pair<int, int> BFS(vector<vector<int>> &adj, int node) {
        int n = adj.size();              // total number of nodes
        vector<int> dist(n, -1);         // distance array; -1 = unvisited
        queue<int> q;                    // normal BFS queue

        dist[node] = 0;                  // start node distance = 0
        q.push(node);

        int far = node;                  // farthest node found so far = start

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Explore all neighbours of current node 'u'
            for (auto v : adj[u]) {
                if (dist[v] == -1) {     // if 'v' not visited yet
                    dist[v] = dist[u] + 1;   // distance of child = parent's + 1
                    q.push(v);

                    // If this node is farther than current farthest, update
                    if (dist[v] > dist[far]) {
                        far = v;
                    }
                }
            }
        }

        // Return the farthest node found and its distance from the source
        return {far, dist[far]};
    }


    /*
     * -----------------------------
     * DIAMETER FUNCTION
     * -----------------------------
     * Purpose:
     *   - Given the edges of a tree, find its diameter.
     *   - Diameter = longest distance (number of edges) between any two nodes.
     *
     * Idea:
     *   1️⃣ Pick any random node (say 0) and run BFS → gives you farthestNode1.
     *   2️⃣ Run BFS again starting from farthestNode1 → gives you farthestNode2.
     *   3️⃣ The distance between these two nodes is the tree’s diameter.
     *
     *   This works because:
     *     - The longest path in a tree will always have its endpoints as
     *       leaves that are farthest apart.
     */
    int diameter(vector<vector<int>> &edges) {
        // Edge case: empty tree (no edges)
        if (edges.empty()) return 0;

        int n = edges.size() + 1;            // tree with 'n' nodes has (n-1) edges
        vector<vector<int>> adj(n);          // adjacency list

        // Build the undirected graph
        for (auto &it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // STEP 1: Run BFS from node 0 to find farthestNode
        auto [farthestNode1, distance] = BFS(adj, 0);

        // STEP 2: Run BFS again from farthestNode to find the diameter distance
        auto [farthestNode2, diameter] = BFS(adj, farthestNode1);

        // STEP 3: Return the diameter (length of the longest path)
        return diameter;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        //first try 0th node to farthest node
        //then try from that farthest to farthest node to gindout the diameter
        return diameter(edges);
    }
};
