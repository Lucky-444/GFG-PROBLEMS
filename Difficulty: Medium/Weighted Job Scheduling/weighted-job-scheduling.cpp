class Solution {
  public:
    vector<vector<int>> jobs;
    vector<long long> dp;
    
    // Binary search to find the next non-conflicting job starting from 'index'
    int nextNonConflict(int index) {
        int low = index + 1, high = jobs.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid][0] >= jobs[index][1]) {
                if (mid - 1 > index && jobs[mid - 1][0] >= jobs[index][1])
                    high = mid - 1;
                else
                    return mid;
            } else {
                low = mid + 1;
            }
        }
        return jobs.size(); // no valid next job
    }
    
    // Recursive function with memoization starting from index 0
    long long solve(int index) {
        if (index >= jobs.size()) return 0;  // base case
        if (dp[index] != -1) return dp[index];
    
        // Pick current job
        long long incl = jobs[index][2];
        int nextIdx = nextNonConflict(index);
        incl += solve(nextIdx);
    
        // Skip current job
        long long excl = solve(index + 1);
    
        return dp[index] = max(incl, excl);
    }
    
    long long jobSchedulingMemo(vector<vector<int>>& inputJobs) {
        jobs = inputJobs;
        int n = jobs.size();
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];  // sort by start time for forward recursion
        });
        dp.assign(n, -1);
        return solve(0);  // start from index 0
    }
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        
        return jobSchedulingMemo(jobs);
    }
};
