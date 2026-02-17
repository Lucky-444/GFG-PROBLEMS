using ll = long long;

/*
 Fenwick Tree storing frequencies of values
*/
class fenwickTree {
    int n;
    vector<ll> bit;

public:
    fenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void Update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll Query(int idx) {
        ll sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    ll inversionCount(vector<int> &arr) {

        int n = arr.size();
        int maxVal = 1e4;

        fenwickTree ft(maxVal);
        ll ans = 0;

        /*
         LEFT → RIGHT traversal
         Fenwick contains elements to the LEFT of current index
        */
        for (int i = 0; i < n; i++) {

            /*
             Query(maxVal)  → total elements seen so far
             Query(arr[i])  → elements ≤ arr[i]
             
             Elements greater than arr[i]:
             = total_seen - smaller_or_equal
            */
            ll totalSeen = ft.Query(maxVal);
            ll smallerOrEqual = ft.Query(arr[i]);

            ans += (totalSeen - smallerOrEqual);

            // Mark current value as seen
            ft.Update(arr[i], 1);
        }

        return ans;
    }
};
