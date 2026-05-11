class SegmentTree {
public:
    vector<long long> seg;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    long long lcm(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }

    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = lcm(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    long long query(int idx, int low, int high, int l, int r) {
        // No overlap
        if (r < low || high < l)
            return 1;

        // Complete overlap
        if (l <= low && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;

        long long left = query(2 * idx + 1, low, mid, l, r);
        long long right = query(2 * idx + 2, mid + 1, high, l, r);

        return lcm(left, right);
    }
};

class Solution {
public:
    vector<long long> RangeLCMQuery(vector<int>& arr,
                                     vector<vector<int>>& queries) {

        SegmentTree st(arr);

        vector<long long> ans;

        for (auto &q : queries) {

            // Update Query
            if (q[0] == 1) {
                int index = q[1];
                int value = q[2];

                st.update(0, 0, arr.size() - 1, index, value);
            }

            // Range LCM Query
            else {
                int l = q[1];
                int r = q[2];

                ans.push_back(
                    st.query(0, 0, arr.size() - 1, l, r)
                );
            }
        }

        return ans;
    }
};