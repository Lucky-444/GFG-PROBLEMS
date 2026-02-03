class Solution {
public:
    string s1, s2;
    vector<vector<int>> dp;
    unordered_map<string, bool> mp; // memo for visited states
    set<string> st; // unique LCS strings

    void dfs(string s, int i, int j) {
        if (i == 0 || j == 0) {
            reverse(s.begin(), s.end());
            st.insert(s);
            return;
        }

        string key = to_string(i) + "-" + to_string(j) + "-" + s;
        if (mp.count(key)) {
            return;
        }
        mp[key] = true;

        if (s1[i - 1] == s2[j - 1]) {
            dfs(s + s1[i - 1], i - 1, j - 1);
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                dfs(s, i - 1, j);
            }
            if (dp[i][j - 1] >= dp[i - 1][j]) {
                dfs(s, i, j - 1);
            }
        }
    }

    vector<string> allLCS(string &s, string &t) {
        s1 = s;
        s2 = t;
        int n = s1.size(), m = s2.size();

        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        dfs("", n, m);

        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};