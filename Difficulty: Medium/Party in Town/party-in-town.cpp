class Solution {
  public:
    int partyHouse(vector<vector<int>> &a) {
        // code here
        int n = a.size();
        
        //Making Adjacency List
        vector<vector<int>>adj(n);
        
        for(int i = 0 ; i < n ; i ++){
            for(auto it : a[i]){
                adj[i].push_back(it - 1);
            }
        }
        
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        int node = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(dist[u] > dist[node]) {
                node = u;
            }

            for(auto v : adj[u]) {
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Second BFS to find diameter
        dist.assign(n, -1);

        q.push(node);
        dist[node] = 0;

        int diameter = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            diameter = max(diameter, dist[u]);

            for(auto v : adj[u]) {
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return (diameter + 1) / 2;
    }
};