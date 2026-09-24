class Solution {
public:

    struct box {
        int h, w, l;
    };

    vector<box> v;
    vector<int> dp;

    int solve(int idx) {

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 0;

        for(int j = 0; j < v.size(); j++) {

            if(v[j].w < v[idx].w &&
               v[j].l < v[idx].l) {

                ans = max(ans, solve(j));
            }
        }

        return dp[idx] = v[idx].h + ans;
    }

    int maxHeight(vector<int>& height,
                  vector<int>& width,
                  vector<int>& length) {

        int n = height.size();

        for(int i = 0; i < n; i++) {

            // height = height[i]
            v.push_back({height[i],
                         min(width[i], length[i]),
                         max(width[i], length[i])});

            // height = width[i]
            v.push_back({width[i],
                         min(height[i], length[i]),
                         max(height[i], length[i])});

            // height = length[i]
            v.push_back({length[i],
                         min(height[i], width[i]),
                         max(height[i], width[i])});
        }

        dp.assign(v.size(), -1);

        int ans = 0;

        for(int i = 0; i < v.size(); i++) {
            ans = max(ans, solve(i));
        }

        return ans;
    }
};