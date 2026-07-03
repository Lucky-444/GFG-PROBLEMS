class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
       int n = s1.size();
        int m = s2.size();

        // pref[i][j] = LCS(s1[0..i-1], s2[0..j-1])
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s1[i - 1] == s2[j - 1])
                    pref[i][j] = pref[i - 1][j - 1] + 1;
                else
                    pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
            }
        }

        // suff[i][j] = LCS(s1[i...], s2[j...])
        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (s1[i] == s2[j])
                    suff[i][j] = suff[i + 1][j + 1] + 1;
                else
                    suff[i][j] = max(suff[i + 1][j], suff[i][j + 1]);
            }
        }

        int L = pref[n][m];
        int ans = 0;

        // Try every insertion position
        for (int pos = 0; pos <= n; pos++) {

            bool ok[26] = {false};

            // Match inserted character with every position in s2
            for (int j = 0; j < m; j++) {

                int c = s2[j] - 'a';

                if (ok[c]) continue;

                if (pref[pos][j] + 1 + suff[pos][j + 1] == L + 1) {

                    ok[c] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};

