class Solution {
public:
    int maxProfit(int x, int y, vector<int>& a, vector<int>& b) {
        
        int n = a.size();

        // maxHeap -> stores {difference , index}
        priority_queue<pair<int,int>> pq;

        for(int i = 0 ; i < n ; i++){
            pq.push({abs(a[i] - b[i]), i});
        }

        int ans = 0;

        while(!pq.empty()){

            auto [diff , idx] = pq.top();
            pq.pop();

            // Prefer machine giving more profit
            if((a[idx] >= b[idx] && x > 0) || y == 0){
                ans += a[idx];
                x--;
            }
            else{
                ans += b[idx];
                y--;
            }
        }

        return ans;
    }
};