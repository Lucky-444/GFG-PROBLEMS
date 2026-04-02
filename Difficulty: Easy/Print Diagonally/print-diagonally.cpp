class Solution {
public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> res;
        for (int k = 0; k <= n + m - 2; k++) {
            for (auto &x : mp[k]) {
                res.push_back(x);
            }
        }

        return res;
    }
};