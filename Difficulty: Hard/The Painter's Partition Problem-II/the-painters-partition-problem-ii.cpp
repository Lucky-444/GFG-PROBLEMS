class Solution {
  public:

    // Function to check if we can divide boards among k painters
    // such that maximum time taken by a painter does not exceed 'mid'
    bool solve(int mid, vector<int>& arr, int k) {
        
        int curr = 0;   // current painter's total assigned work
        int cnt = 1;    // start with first painter
        
        for (auto it : arr) {
            
            // If adding current board does not exceed 'mid'
            if (curr + it <= mid) {
                curr += it;
            } 
            else {
                // Assign new painter
                curr = it;
                cnt++;
            }
        }
        
        // If painters required <= k, it is valid
        return cnt <= k;
    }

    int minTime(vector<int>& arr, int k) {
        
        // Minimum possible time = largest board
        int low = *max_element(arr.begin(), arr.end());
        
        // Maximum possible time = sum of all boards
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        
        // Binary Search on Answer
        while (low <= high) {
            
            int mid = low + (high - low) / 2;  // avoid overflow
            
            if (solve(mid, arr, k)) {
                ans = mid;        // possible answer
                high = mid - 1;   // try to minimize further
            } 
            else {
                low = mid + 1;    // increase time
            }
        }
        
        return ans;
    }
};
