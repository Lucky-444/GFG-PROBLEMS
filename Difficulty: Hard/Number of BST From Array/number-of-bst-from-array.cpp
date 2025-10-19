class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<long long> C(n + 1, 0);
        C[0] = 1;

        // Step 1: Precompute Catalan numbers
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                C[i] += C[j] * C[i - j - 1];
            }
        }

        // Step 2: Sort a copy to determine position (rank)
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
            int left = idx;           // elements smaller than arr[i]
            int right = n - idx - 1;  // elements greater than arr[i]
            ans[i] = (int)(C[left] * C[right]);
        }

        return ans;
    }
};
