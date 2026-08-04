class Solution {
  public:
    using ll = long long;
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        ll ans = INT_MIN ;
        // Step 1: prefix sum
        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];
    
        // Step 2: initial window of size K
        ll maxSum = prefix[k] - prefix[0];
        ll currSum = maxSum;
    
        // Step 3: Kadane-style extension
        for (int i = k; i < n; i++) {
            // Either extend previous subarray
            currSum = max(currSum + arr[i],
                          prefix[i + 1] - prefix[i + 1 - k]);
    
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};