class Solution {
  public:

    // -----------------------------
    // 🌱 Function: catalanNumber(n)
    // -----------------------------
    // Computes the nth Catalan number using the
    // direct combinatorial formula:
    //
    //     C_n = (1 / (n + 1)) * (2n choose n)
    //
    // Instead of computing factorials (which can overflow),
    // we use a multiplicative approach to compute nCr efficiently:
    //
    //     (2n choose n) = Π (2n - i) / (i + 1), for i = 0 to n-1
    //
    // Then divide the result by (n + 1) to get the Catalan number.
    //
    // Example:
    //   n = 3
    //   C_3 = (1/4) * (6 choose 3) = (1/4) * 20 = 5
    //
    // Catalan sequence begins as:
    //   n: 0 1 2 3  4   5   6
    //  Cn: 1 1 2 5 14  42 132
    //
    long long catalanNumber(int n) {
        if (n == 0 || n == 1) return 1;  // Base cases: C0 = 1, C1 = 1

        long long res = 1;
        // Compute (2n choose n)
        for (int i = 0; i < n; i++) {
            // multiply by (2n - i)
            // then divide by (i + 1)
            // this avoids factorial overflow and keeps integers small
            res = res * (2 * n - i) / (i + 1);
        }

        // Divide by (n + 1) to get Catalan number
        return res / (n + 1);
    }

    // ----------------------------------------
    // 🌳 Function: countBSTs(vector<int>& arr)
    // ----------------------------------------
    // Given an array of *distinct* integers (arr[]),
    // we must return a vector where each element tells
    // how many **unique BSTs** can be formed when that
    // specific element is chosen as the root.
    //
    // 🧩 Concept:
    // In a Binary Search Tree (BST):
    //   - All elements smaller than the root go to the left subtree
    //   - All elements greater than the root go to the right subtree
    //
    // Suppose:
    //   left = number of nodes smaller than the root
    //   right = number of nodes greater than the root
    //
    // Then, total BSTs with this root = C_left * C_right
    // (since left and right subtrees are independent)
    //
    // Example:
    //   arr = [1, 2, 3, 4]
    //   If root = 2 → left=1, right=2
    //   Answer = C_1 * C_2 = 1 * 2 = 2
    //
    // Approach:
    //   1️⃣ Precompute all Catalan numbers up to n.
    //   2️⃣ Sort a copy of arr to find how many elements
    //       are smaller or greater than each arr[i].
    //   3️⃣ For each arr[i]:
    //         left  = count of elements smaller than arr[i]
    //         right = count of elements greater than arr[i]
    //       result = C[left] * C[right]
    //
    // Time Complexity:
    //   Catalan computation: O(n)
    //   Sorting + lookups: O(n log n)
    // ----------------------------------------
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Precompute Catalan numbers up to n
        vector<long long> C(n + 1);
        for (int i = 0; i <= n; i++)
            C[i] = catalanNumber(i);

        // Step 2: Sort a copy of arr to determine each element's
        // position (rank) in the sorted order.
        // This tells us how many are smaller or greater.
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        // Step 3: For each element, calculate left and right subtree sizes
        // and use C[left] * C[right]
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            // Find index (rank) of arr[i] in the sorted array
            int idx = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();

            int left = idx;           // number of elements smaller than arr[i]
            int right = n - idx - 1;  // number of elements greater than arr[i]

            // Compute number of unique BSTs possible with arr[i] as root
            ans[i] = (int)(C[left] * C[right]);
        }

        return ans;  // final answer vector
    }
};
