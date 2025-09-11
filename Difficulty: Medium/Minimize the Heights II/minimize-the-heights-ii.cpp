class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;  // If only one tower, no difference possible

        // Step 1: Sort the array so we can handle towers in increasing order
        sort(arr.begin(), arr.end());

        // Initial difference without any modification
        int ans = arr[n - 1] - arr[0];

        // Step 2: Assume we increase the smallest by k
        // and decrease the largest by k
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        // Step 3: Try splitting the array at every index i
        // Towers [0..i] → increased by k
        // Towers [i+1..n-1] → decreased by k
        for (int i = 0; i < n - 1; i++) {
            // Possible minimum height after modification
            int minH = min(smallest, arr[i + 1] - k);

            // Possible maximum height after modification
            int maxH = max(largest, arr[i] + k);

            // If height becomes negative, skip this case
            if (minH < 0) continue;

            // Update answer with minimized difference
            ans = min(ans, maxH - minH);
        }

        return ans;  // Final minimized difference
    }
};
