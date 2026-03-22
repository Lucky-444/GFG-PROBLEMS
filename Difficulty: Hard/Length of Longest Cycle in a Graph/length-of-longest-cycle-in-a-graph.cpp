class Solution {
  public:
    virtual void dfs(int i, int t, vector<bool> &vis1, vector<bool> &vis2, vector<int> &timer, 
                     vector<vector<int>> &adj, int &tans){
      
      vis1[i]=true;
      vis2[i]=true;
      timer[i]=t;
      
      for(int ch: adj[i]){
        if(!vis1[ch]){
          dfs(ch, t+1, vis1, vis2, timer, adj, tans);
        }
        else if(vis2[ch]){
          tans=max(tans, t+1-timer[ch]);    
        }
      }
      vis2[i]=false;
      return;     
     }
    
    virtual int longestCycle(int V, vector<vector<int>>& edges) {
      vector<vector<int>> adj(V+1);
      vector<bool> vis1(V+1, false);
      vector<bool> vis2(V+1, false);
      vector<int> timer(V+1);
      
      for(vector<int> &v: edges){
        adj[v[0]].push_back(v[1]);  
      }
      
      int ans=-1;
      for(int i=0; i<=V; i++){
        if(!vis1[i]){
            int tans=-1;
            dfs(i, 0, vis1, vis2, timer, adj, tans);
            ans=max(ans, tans);
        }  
      }
      
      return ans;
    }
};
