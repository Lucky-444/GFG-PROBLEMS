#include <bits/stdc++.h>
using namespace std;

int check(int a[], int mid, int n) {
    // Count how many pairs have difference <= mid
    int cnt = 0;
    int j = 0; // right pointer

    for (int i = 0; i < n; i++) {
        // expand j while valid
        while (j < n && a[j] - a[i] <= mid) {
            j++;
        }
        // number of valid pairs with i = (j - i - 1)
        cnt += (j - i - 1);
    }

    return cnt;
}

int kthDiff(int a[], int n, int k) {
    // Problem: find k-th smallest absolute difference
    // Thought: Use binary search on possible distance values

    // Step 1: Sort array
    sort(a, a + n);

    int low = 0;             // smallest possible difference
    int high = a[n-1] - a[0]; // largest possible difference
    int ans = -1;

    // Step 2: Binary search over difference values
    while (low <= high) {
        int mid = (low + high) >> 1;

        // check how many pairs <= mid
        if (check(a, mid, n) >= k) {
            ans = mid;        // mid might be the answer
            high = mid - 1;   // try smaller distances
        } else {
            low = mid + 1;    // need larger distance
        }
    }

    return ans;
}

