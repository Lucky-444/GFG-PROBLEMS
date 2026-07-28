class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
         vector<vector<pair<int,int>>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        deque<int> dq;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        dq.push_back(src);

        while(!dq.empty()){

            int node = dq.front();
            dq.pop_front();

            for(auto &[next, wt] : adj[node]){

                if(dist[node] + wt < dist[next]){

                    dist[next] = dist[node] + wt;

                    if(wt == 1)
                        dq.push_front(next);   // Your idea
                    else
                        dq.push_back(next);    // Your idea
                }
            }
        }

        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};