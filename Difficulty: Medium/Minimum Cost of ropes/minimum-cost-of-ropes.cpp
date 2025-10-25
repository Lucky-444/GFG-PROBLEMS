class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int ,vector<int> , greater<>>pq;
        int minicost = 0;
        
        for(auto it : arr){
            pq.push(it);
        }
        
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            minicost += (x + y);
            pq.push(x + y);
        }
        
        return minicost;
    }
};