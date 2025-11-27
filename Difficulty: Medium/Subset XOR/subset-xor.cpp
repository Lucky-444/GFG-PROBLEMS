class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        // XOR of 1..n using n%4 trick
        int X;
        if (n % 4 == 0) X = n;
        else if (n % 4 == 1) X = 1;
        else if (n % 4 == 2) X = n + 1;
        else X = 0;

        vector<int> ans;

        // If XOR(1..n) == n -> all numbers
        if (X == n) {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 1);
            return ans;
        }

        // Otherwise remove exactly one number
        int k = X ^ n;

        for (int i = 1; i <= n; i++) {
            if (i != k) ans.push_back(i);
        }

        return ans;
    }
};
