class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int m = n / 2;

        sort(arr.begin(), arr.begin() + m);
        sort(arr.begin() + m, arr.end());

        int left = 0, right = m;
        int ans = 0;

        while(left < m && right < n) {

            if(arr[left] >= 5 * arr[right]) {
                ans += (m - left);
                right++;
            }
            else {
                left++;
            }
        }

        return ans;
    }
};