class Solution {
public:

    struct BIT {
        vector<int> bit;

        BIT(int n) {
            bit.resize(n + 1, 0);
        }

        void update(int i, int val) {
            while(i < bit.size()) {
                bit[i] = max(bit[i], val);
                i += i & -i;
            }
        }

        int query(int i) {
            int ans = 0;

            while(i > 0) {
                ans = max(ans, bit[i]);
                i -= i & -i;
            }

            return ans;
        }
    };

    int maxStackHeight(vector<int> &R, vector<int> &H) {

        int n = R.size();

        vector<pair<int,int>> discs;

        for(int i = 0; i < n; i++) {
            discs.push_back({R[i], H[i]});
        }

        // Radius increasing
        // Height decreasing for same radius
        sort(discs.begin(), discs.end(), [](auto &a, auto &b) {
            if(a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        });

        // Coordinate compression of heights
        vector<int> vals;

        for(auto &p : discs)
            vals.push_back(p.second);

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size());

        int ans = 0;

        for(auto &[r, h] : discs) {

            int idx = lower_bound(vals.begin(), vals.end(), h)
                      - vals.begin() + 1;

            // Previous height must be strictly smaller
            int best = bit.query(idx - 1);

            int curr = best + h;

            bit.update(idx, curr);

            ans = max(ans, curr);
        }

        return ans;
    }
};