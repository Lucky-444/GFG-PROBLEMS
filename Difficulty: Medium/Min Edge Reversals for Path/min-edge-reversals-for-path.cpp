class Solution {
  public:
    using P = pair<int , int>;
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        //Push Adjacency List With Weights For Like 
        vector<vector<P>>adj(n + 1);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back({v , 0});
            adj[v].push_back({u , 1});
            
        }
        
        priority_queue<P , vector<P> , greater<P>>pq;
        pq.push({0 , src});
        vector<int> dist(n + 1, INT_MAX); // Distance array initialized to infinity
        dist[src] = 0;
        
        while(!pq.empty()){
            auto [d , node] = pq.top();
            pq.pop();
            
            
            for(auto [ngbr , wt] : adj[node]){
                if(dist[ngbr] > dist[node] + wt){
                    dist[ngbr] = dist[node] + wt;
                    pq.push({dist[ngbr] , ngbr});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};