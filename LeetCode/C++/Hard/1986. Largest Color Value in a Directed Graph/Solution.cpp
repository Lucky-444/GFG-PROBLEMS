class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //first thought is topological sort gives us longest route
        //and in case any cycle is present there then return -1;
        int n = colors.size();
        vector<int>indegree(n , 0);
        int ans = 0;
        vector<vector<int>>adj(n);

        for(auto it : edges){
            int u =  it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        //now apply TOPO sort
        //start node is that node then color value of that is 1
        vector<vector<int>>dp(n  , vector<int>(26  ,0)); // to store node and color
        queue<int>q;
        for(int i = 0; i < n ; i ++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int cnt = 0;
        //now pop out
        while(!q.empty()){
            int u = q.front();
            q.pop();

            cnt ++;
            ans = max(ans , dp[u][colors[u] - 'a']);

            for(auto &v : adj[u]){
                char ch = colors[v];

                //now check all 26 colors 
                //which one is matching with the neighbour color
                //if not matching then u ka color length hi v ka color length hoga

                for(int i = 0; i < 26 ; i ++){
                    dp[v][i] = max(dp[v][i]  , dp[u][i] + (ch - 'a' == i));
                }

                if(-- indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(cnt < n){
            return -1; //graph mai cycle present hai
        }

        return ans;
    }
};