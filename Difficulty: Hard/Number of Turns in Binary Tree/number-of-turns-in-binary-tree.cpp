class Solution {
  public:
    int bfs(unordered_map<int,vector<vector<int>>>&adj, int s, int e){

        queue<vector<int>> q;
        for(auto it:adj[s]){
            int v=it[0], d=it[1];
            q.push({v,d,0});
        }

        unordered_map<int, array<bool, 2>> vis;
        for (auto &it : adj[s]) {
            vis[it[0]][it[1]] = true;
        }

        while(!q.empty()){
            auto ele=q.front(); q.pop();
            int u=ele[0], dir=ele[1], turn=ele[2];

            if(u==e)return turn;

            for(auto it:adj[u]){
                int v=it[0], d=it[1];

                if(vis[it[0]][it[1]]) continue;
                if(dir!=d){
                    q.push({v,d,turn+1});
                    vis[it[0]][it[1]] = true;
                }else{
                    q.push({v,dir,turn});
                    vis[it[0]][it[1]] = true;
                }
            }
        }
        return -1;
    }

    int numberOfTurns(Node* root, int p, int q1) {
        // code here
        unordered_map<int,vector<vector<int>>> adj;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            auto ele=q.front(); q.pop();
            int u=ele->data;

            if(ele->left){
                q.push(ele->left);
                int v=ele->left->data;

                adj[u].push_back({v,0});
                adj[v].push_back({u,0});
            }

            if(ele->right){
                q.push(ele->right);
                int v=ele->right->data;

                adj[u].push_back({v,1});
                adj[v].push_back({u,1});
            }
        }

        int ans=bfs(adj,p,q1);
        return ans==0?-1:ans;
    }
};