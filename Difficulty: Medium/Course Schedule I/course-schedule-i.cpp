class Solution {
  public:
    bool dfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<bool>&DFSvisited){
        visited[node]=true;
        DFSvisited[node]=true;
        for(auto&nbr:adj[node]){
            if(visited[nbr]&&DFSvisited[nbr]){
                return true;
            }
            if(!visited[nbr]&&dfs(nbr,adj,visited,DFSvisited)){
                return true;
            }
        }
        DFSvisited[node]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        for(auto&vec:prerequisites){
            int x=vec[0],y=vec[1];
            adj[y].push_back(x);
        }
        vector<bool>visited(n,false);
        vector<bool>DFSvisited(n,false);
        return !dfs(0,adj,visited,DFSvisited);
        // int cnt=0;
        // for(int i=0;i<n;i++)if(!DFSvisited[i])cnt++;
        // return (cnt==n);
    }
};