// User function template for C++

class Solution {
  public:
    vector<vector<int>> ans;   // stores all SCCs
    vector<int> disc, low;     // discovery time and lowest reachable time
    int timeCounter = 0;

    // DFS function for Tarjan's Algorithm
    void DFS(int node , int timer , auto &vis , auto &st , auto &inStack, auto &adj) {
       vis[node] = 1; 

       // assign discovery time and low time
       disc[node] = low[node] = ++timeCounter;

       st.push(node);         // push into stack
       inStack[node] = 1;     // mark as present in stack

       // explore all neighbours
       for(int v : adj[node]){
           if(!vis[v]){
               // recursive DFS call
               DFS(v , timer + 1 , vis, st , inStack , adj);

               // backtrack: update low-link value
               low[node] = min(low[node] , low[v]);
           } else {
               // if neighbor is still in stack → back edge found
               if(inStack[v]){
                   low[node] = min(low[node] , disc[v]);
               }
           }
       }

       // if node is head of SCC (start of a strongly connected component)
       if(disc[node] == low[node]){
           vector<int> temp;

           // pop all nodes belonging to this SCC
           while(!st.empty() && st.top() != node){
               auto top = st.top();
               temp.push_back(top);
               st.pop();
               inStack[top] = 0;
           }

           // pop the last (head) node
           auto top = node;
           temp.push_back(top);
           inStack[top] = 0;
           st.pop();

           // sort the SCC for output
           sort(temp.begin() , temp.end());    

           ans.push_back(temp);  // add SCC to result
       }
    }

    // Function to return all Strongly Connected Components in the graph
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        disc.assign(V, 0);
        low.assign(V, 0);

        vector<int> vis(V , 0);        // visited array
        stack<int> st;                 // stack for Tarjan's algorithm
        vector<bool> inStack(V , 0);   // track nodes currently in stack

        int timer = 0;
        for(int i = 0; i < V ; i++){
            if(!vis[i]){
                 DFS(i , timer , vis , st , inStack , adj);
            }
        }

        // sort all SCCs lexicographically
        sort(ans.begin() , ans.end());
        return ans;
    }
};
