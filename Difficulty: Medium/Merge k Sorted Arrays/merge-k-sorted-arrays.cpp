class Solution {
  public:
    using P = pair<int , pair<int ,int>>; 
    vector<int> mergeArrays(vector<vector<int>> &arr) {
        // Code here
        int n = arr.size();
        int m = arr[0].size();
        
        priority_queue<P , vector<P> , greater<P>>pq; 
        vector<int>ans;
        
        for(int i = 0 ; i < n ; i ++){
            pq.push({ arr[i][0], { i, 0 } });
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int val = top.first;
            int i = top.second.first;
            int j = top.second.second; 
            
            ans.push_back(val);
            
            if(j + 1 < m){
                pq.push({arr[i][j + 1] ,{i , j + 1}});
            }
        }
        
        return ans;
        
    }
};