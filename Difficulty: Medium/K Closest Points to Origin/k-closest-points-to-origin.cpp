class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
  // Max-Heap to store the k closest points
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (const auto& p : points) {
            int x = p[0], y = p[1];
            int distance = x * x + y * y; // Squared distance to avoid floating-point inaccuracies

            // Push the current point with negative distance (to make it a max-heap)
            maxHeap.push({distance, {x, y}});

            // If heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract the k closest points from the heap
        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return res;
    }
};