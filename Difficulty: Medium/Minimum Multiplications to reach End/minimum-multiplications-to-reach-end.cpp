class Solution {
  public:
    const int mod = 1e9 + 7;

    int minSteps(vector<int>& arr, int start, int end) {

        vector<int> dist(1000, 1e9);

        queue<pair<int,int>> q;

        q.push({start, 0});
        dist[start] = 0;

        while(!q.empty()) {

            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(node == end)
                return steps;

            for(auto it : arr) {

                int num = (node * it) % 1000;

                if(steps + 1 < dist[num]) {

                    dist[num] = steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }

        return -1;
    }
};

