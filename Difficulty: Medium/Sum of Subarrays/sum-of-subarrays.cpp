class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        // Contribution Technique:
        // Instead of generating all subarrays, we directly compute
        // how many times each element will appear in all subarrays.
        // 
        // Idea:
        //  - For an element at index i (0-based), 
        //    Number of choices for start = (i + 1)
        //    Number of choices for end   = (n - i)
        //    Total subarrays containing arr[i] = (i + 1) * (n - i)
        //
        // Contribution of arr[i] = arr[i] * (i + 1) * (n - i)
        // 
        // We sum up contributions for all i to get the total sum of all subarrays.
        
        long long totalSum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            long long count = (long long)(i + 1) * (n - i); // total subarrays containing arr[i]
            totalSum += (long long)arr[i] * count;          // add contribution
        }
        
        return (int)totalSum;
    }
};
