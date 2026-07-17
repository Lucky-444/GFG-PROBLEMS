class Solution {
  public:
    stack<int>st;
    int cnt = 0;
    void DFSS(int node, vector<vector<int>> &adj, vector<int> &vis) {

        vis[node] = 1;

        for(auto &it : adj[node]) {
            if(!vis[it]) {
                DFSS(it, adj, vis);
            }
        }
    }
    void DFS(int node , auto &adj , auto &vis){
        vis[node]=1;
	     
        for(auto  &it:adj[node]){
            if(!vis[it]){
                DFS(it,adj,vis);
            }
        }
	    st.push(node);
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        //First DO TOPO sort
        //REVERSE All Edges
        //Using TOPO ORDER CALL DFS and Store SCC
        vector<vector<int>>adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        //Step:-1 TOPO SORT
        int n = V;
        vector<int>vis(V,0);
        
        for(int i = 0 ; i < n ; i ++){
            if(!vis[i]){
                DFS(i , adj , vis);
            }
        }
        
        //Step:-2 Reverse The Edges
        vector<vector<int>>adjRev(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adjRev[v].push_back(u);
        }
        
        
        //Step:-3 According to Topo sort CAll DFS and Count SCC
        vis.assign(V,0);

        int ans = 0;

        while(!st.empty()) {

            int node = st.top();
            st.pop();

            if(!vis[node]) {

                DFSS(node, adjRev, vis);
                ans++;
            }
        }

        return ans;
        
        return ans;
    }
};