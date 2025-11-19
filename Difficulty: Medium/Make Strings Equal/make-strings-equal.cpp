class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        
        int n = s.size();
        if (t.size() != n) return -1;

        const long long INF = 1e15;

        // 26 x 26 matrix
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // cost of transforming c -> c = 0
        for(int i = 0; i < 26; i++) dist[i][i] = 0;

        // apply given transformations
        for(int i = 0; i < transform.size(); i++){
            int x = transform[i][0] - 'a';
            int y = transform[i][1] - 'a';
            dist[x][y] = min(dist[x][y], (long long)cost[i]);
        }

        // Floyd–Warshall
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        long long ans = 0;

        // Match characters one by one
        for(int i = 0; i < n; i++){
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            long long best = INF;

            // Try converting both to a common character c
            for(int c = 0; c < 26; c++){
                if (dist[a][c] == INF || dist[b][c] == INF) continue;

                best = min(best, dist[a][c] + dist[b][c]);
            }

            if (best == INF) return -1;
            ans += best;
        }

        return ans;
    }
};
