class Solution {
public:
    int ans = 0;
    int target;
    
    void solve(vector<int>& arr, int i, int sum, int remaining) {
        // pruning
        if (abs(target - sum) > remaining) return;
        
        if (i == arr.size()) {
            if (sum == target) ans++;
            return;
        }
        
        // choose +
        solve(arr, i + 1, sum + arr[i], remaining - arr[i]);
        
        // choose -
        solve(arr, i + 1, sum - arr[i], remaining - arr[i]);
    }
    
    int totalWays(vector<int>& arr, int target_) {
        target = target_;
        
        int total = 0;
        for (int x : arr) total += x;
        
        solve(arr, 0, 0, total);
        
        return ans;
    }
};