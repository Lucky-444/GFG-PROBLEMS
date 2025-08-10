class Solution {

public:
    // p[i] stores radius of palindrome centered at i in the modified string
    vector<int> p;
    string ms;

    // Constructor for manacher
    Solution(string &s) {
        ms = "@";
        for (char c : s) {
            ms += "#" + string(1, c);
        }
        ms += "#$";
        runManacher();
    }

    Solution() {} // default constructor so class can still be used without args

    // Runs Manacher's algorithm on transformed string `ms`
    void runManacher() {
        int n = ms.size();
        p.assign(n, 0);
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;
            if (i < right) {
                p[i] = min(right - i, p[mirror]);
            }

            while (ms[i + p[i] + 1] == ms[i - p[i] - 1]) {
                ++p[i];
            }

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
    }

    // Returns length of longest palindrome (odd/even) centered at original index cen
    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + (!odd);
        return p[pos];
    }

    int maxSum(string &s) {
        int n = s.size();
        vector<int> leftMark(n, 1), rightMark(n, 1);

        Solution mr(s); // run manacher

        // Fill leftMark: max odd palindrome ending at/before i
        for (int i = 0; i < n; i++) {
            int val = mr.getLongest(i, 1);
            int li = i + val / 2;
            if (li < n)
                leftMark[li] = max(leftMark[li], val);
        }

        for (int i = n - 2; i >= 0; i--) {
            leftMark[i] = max(leftMark[i], leftMark[i + 1] - 2);
        }

        for (int i = 1; i < n; i++) {
            leftMark[i] = max(leftMark[i], leftMark[i - 1]);
        }

        // Fill rightMark: max odd palindrome starting at/after i
        for (int i = n - 1; i >= 0; i--) {
            int val = mr.getLongest(i, 1);
            int ri = i - val / 2;
            if (ri >= 0)
                rightMark[ri] = max(rightMark[ri], val);
        }

        for (int i = 1; i < n; i++) {
            rightMark[i] = max(rightMark[i], rightMark[i - 1] - 2);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMark[i] = max(rightMark[i], rightMark[i + 1]);
        }

        // Combine results
        int ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            ans = max(ans, leftMark[i] + rightMark[i + 1]);
        }

        return ans;
    }
};
