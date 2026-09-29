class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> dp(n, 1e9);

        int left = 0;
        int sum = 0;
        int ans = 1e9;
        int mn = 1e9;

        for(int right = 0; right < n; right++) {
            sum += arr[right];

            while(sum > target) {
                sum -= arr[left];
                left++;
            }

            if(sum == target) {
                int len = right - left + 1;

                // previous subarray must end before left
                if(left > 0 && dp[left - 1] != 1e9) {
                    ans = min(ans, len + dp[left - 1]);
                }

                mn = min(mn, len);
            }

            dp[right] = mn;
        }

        return ans == 1e9 ? -1 : ans;
    }
};