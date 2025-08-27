// User function template for C++

class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.

 void dfs(int node, vector<int>& visited, vector<int>adj[],stack<int>& st) {
        visited[node] = 1;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,adj,st);
            }
        }
        st.push(node);
    }
     void revdfs(int node, vector<int>& visited, vector<int>adj[], vector<int>& res) {
        visited[node] = 1;
        res.push_back(node);
        for(auto it: adj[node]) {
            if(!visited[it]) {
                revdfs(it,visited,adj,res);
            }
        }
        
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
       vector<int>visited(V,0);
       stack<int>st;
       for(int i=0;i<V;i++) {
           if(!visited[i]) {
               dfs(i,visited,adj,st);
           }
       }
       
       vector<int>transpose[V];
       for(int i=0;i<V;i++) {
           visited[i] = 0;
           for(auto it: adj[i]) {
               transpose[it].push_back(i);
           }
       }
       
       vector<int>res;
       vector<vector<int>>ans;
       while(!st.empty()) {
           int top = st.top();
           st.pop();
           if(!visited[top]) {
               revdfs(top,visited,transpose,res);
                sort(res.begin(),res.end());
                ans.push_back(res);
           }
           res.clear();
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};