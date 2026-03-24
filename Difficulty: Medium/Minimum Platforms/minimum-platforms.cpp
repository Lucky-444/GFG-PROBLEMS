class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        vector<pair<int,int>> trains;
        for(int i = 0; i < n; i++) {
            trains.push_back({arr[i], dep[i]});
        }
        
        sort(trains.begin(), trains.end()); // sort by arrival
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        
        pq.push(trains[0].second);
        
        for(int i = 1; i < n; i++) {
            if(trains[i].first > pq.top()) {
                pq.pop(); // reuse platform
            }
            pq.push(trains[i].second);
        }
        
        return pq.size();
    }
};