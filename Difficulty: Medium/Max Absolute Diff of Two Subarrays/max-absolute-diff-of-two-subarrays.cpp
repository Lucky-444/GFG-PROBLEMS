class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n < 2) return 0;
    
        // Arrays to store max and min subarray sums from left to right
        vector<int> leftMax(n), leftMin(n);
        // Arrays to store max and min subarray sums from right to left
        vector<int> rightMax(n), rightMin(n);
    
        // Fill left arrays (Forward Kadane)
        int currentMax = arr[0], maxSoFar = arr[0];
        int currentMin = arr[0], minSoFar = arr[0];
        leftMax[0] = maxSoFar;
        leftMin[0] = minSoFar;
    
        for (int i = 1; i < n; i++) {
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSoFar = max(maxSoFar, currentMax);
            leftMax[i] = maxSoFar;
    
            currentMin = min(arr[i], currentMin + arr[i]);
            minSoFar = min(minSoFar, currentMin);
            leftMin[i] = minSoFar;
        }
    
        // Fill right arrays (Backward Kadane)
        currentMax = arr[n - 1]; maxSoFar = arr[n - 1];
        currentMin = arr[n - 1]; minSoFar = arr[n - 1];
        rightMax[n - 1] = maxSoFar;
        rightMin[n - 1] = minSoFar;
    
        for (int i = n - 2; i >= 0; i--) {
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSoFar = max(maxSoFar, currentMax);
            rightMax[i] = maxSoFar;
    
            currentMin = min(arr[i], currentMin + arr[i]);
            minSoFar = min(minSoFar, currentMin);
            rightMin[i] = minSoFar;
        }
    
        // Find the maximum absolute difference
        int maxDiff = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            int case1 = abs(leftMax[i] - rightMin[i + 1]);
            int case2 = abs(leftMin[i] - rightMax[i + 1]);
            maxDiff = max({maxDiff, case1, case2});
        }
    
        return maxDiff;
    }
};