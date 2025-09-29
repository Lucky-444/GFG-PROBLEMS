class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
         int n = arr.size();

        // Step 1: prefix sums
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        deque<int> dq;  // stores indices of prefix sums
        long long res = LLONG_MIN;

        for (int r = a; r <= n; r++) {
            // Add prefix[r - a] into deque (valid candidate for left boundary)
            while (!dq.empty() && prefix[dq.back()] >= prefix[r - a]) {
                dq.pop_back();
            }
            dq.push_back(r - a);

            // Remove invalid indices (smaller than r - b)
            while (!dq.empty() && dq.front() < r - b) {
                dq.pop_front();
            }

            // Best candidate for left boundary is at dq.front()
            res = max(res, prefix[r] - prefix[dq.front()]);
        }

        return res;
        
        
    }
};