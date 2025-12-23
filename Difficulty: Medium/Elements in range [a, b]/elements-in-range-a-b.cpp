#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
SEGMENT TREE CLASS
---------------------------------------------------------
This segment tree is built on ARRAY INDICES, not values.

Each leaf node represents exactly ONE index in the array.
So every leaf stores value = 1.

Each internal node stores:
→ sum of elements in its range
→ i.e., how many indices exist in that range
---------------------------------------------------------
*/
class SegmentTree {
private:
    vector<int> seg;   // segment tree array
    int n;             // size of array

    /*
    -----------------------------------------------------
    BUILD FUNCTION
    idx → current tree node index
    l   → left boundary of segment
    r   → right boundary of segment
    -----------------------------------------------------
    */
    void build(int idx, int l, int r) {

        // BASE CASE: Leaf node
        // This represents ONE index in the array
        if (l == r) {
            seg[idx] = 1;   // exactly 1 element exists here
            return;
        }

        // Divide range into two halves
        int mid = (l + r) / 2;

        // Build left child → [l, mid]
        build(2 * idx, l, mid);

        // Build right child → [mid+1, r]
        build(2 * idx + 1, mid + 1, r);

        // Combine results
        // Total elements in this range
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    /*
    -----------------------------------------------------
    QUERY FUNCTION
    Returns count of elements in range [ql, qr]
    -----------------------------------------------------
    */
    int query(int idx, int l, int r, int ql, int qr) {

        // Case 1: No overlap
        if (qr < l || ql > r)
            return 0;

        // Case 2: Complete overlap
        if (ql <= l && r <= qr)
            return seg[idx];

        // Case 3: Partial overlap
        int mid = (l + r) / 2;

        return query(2 * idx, l, mid, ql, qr)
             + query(2 * idx + 1, mid + 1, r, ql, qr);
    }

public:
    /*
    -----------------------------------------------------
    CONSTRUCTOR
    -----------------------------------------------------
    */
    SegmentTree(int n) {
        this->n = n;

        // 4*n is safe size for segment tree
        seg.resize(4 * n);

        // Build tree for index range [0, n-1]
        build(1, 0, n - 1);
    }

    /*
    -----------------------------------------------------
    PUBLIC QUERY FUNCTION
    -----------------------------------------------------
    */
    int rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

/*
---------------------------------------------------------
SOLUTION CLASS
---------------------------------------------------------
*/
class Solution {
public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {

        int n = arr.size();

        // STEP 1: Sort the array
        // Needed for binary search
        sort(arr.begin(), arr.end());

        /*
        Example after sorting:
        arr = [1, 2, 4, 5, 8]
        idx =  0  1  2  3  4
        */

        // STEP 2: Build Segment Tree on indices
        SegmentTree st(n);

        vector<int> result;

        // STEP 3: Process each query
        for (auto &q : queries) {

            int a = q[0];   // lower bound value
            int b = q[1];   // upper bound value

            // Find first index where arr[i] >= a
            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();

            // Find last index where arr[i] <= b
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin() - 1;

            // Query how many indices exist in [left, right]
            int count = st.rangeQuery(left, right);

            result.push_back(count);
        }

        return result;
    }
};
