
class Solution {
  public:
   typedef pair<int, int> pp;
int manhattan(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

    int minCost(vector<vector<int>>& house) {
        // code here
        int n = house.size();
         vector<int> vis(n, 0);
        
        priority_queue<pp, vector<pp>, greater<pp>>pq;
        
        pq.push({0,0});
        // vis[0] = 1;
        
        int ans = 0;
        
        while(!pq.empty()){
            auto it  =  pq.top();
            pq.pop();
            
            auto dist = it.first;
            auto node = it.second;
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            
            ans += dist;
            
            for(int v = 0 ;v <n ;v++){
                if(!vis[v]){
                    
                    int d = manhattan(house[node] ,house[v]);
                    
                     pq.push({d, v});
                }
                
            }
         }
         
         
         return ans ;
    }
};

