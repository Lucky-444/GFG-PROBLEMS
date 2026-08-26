class Solution {
  public:
    bool isNegativeWeightCycle(int n, vector<vector<int>>& edges) {
        // code here
        //Lopp Till n - 1 Times 
           vector<int> dist(n, 0);
    
           // Relax n times
           for (int i = 0; i < n; i++) {
    
               bool changed = false;
    
               for (auto &e : edges) {
                   int u = e[0];
                   int v = e[1];
                   int wt = e[2];
    
                   if (dist[u] + wt < dist[v]) {
                       dist[v] = dist[u] + wt;
                       changed = true;
    
                       // If relaxation is possible on nth iteration,
                       // negative cycle exists
                       if (i == n - 1)
                           return true;
                   }
               }
    
               // No update => no negative cycle
               if (!changed)
                   break;
           }
    
           return false;
    }
};