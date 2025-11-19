class Solution {
  public:
    int minCostPath(vector<vector<int>>& h) {
        // code here
        int n = h.size();
        int m = h[0].size();
         priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        
        dist[0][0]=1;
        
        while(!pq.empty())
        {
            int diff= pq.top().first;
            int r = pq.top().second.first;
            int c =pq.top().second.second;
            
            pq.pop();
            
            if(r==n-1 && c==m-1){
                return diff;
            }
            
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int neweffort = max(abs(h[r][c]-h[nr][nc]),diff);
                    if(neweffort < dist[nr][nc]){
                        dist[nr][nc] = neweffort;
                        
                        pq.push({neweffort,{nr,nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};
