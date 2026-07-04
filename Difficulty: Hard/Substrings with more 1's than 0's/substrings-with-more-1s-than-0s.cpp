class Solution {
  public:
    int countSubstring(string& s) {
        // Code Here
        int n = s.size();

        // Prefix sums
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] == '1' ? 1 : -1);
        }

        // Coordinate Compression
        vector<int> v = pref;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int m = v.size();
        vector<int> bit(m + 1, 0);

        auto update = [&](int idx) {
            while (idx <= m) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        };

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
            ans += query(idx - 1);   // previous prefix sums < current
            update(idx);             // insert current prefix sum
        }

        return ans;
    }
};