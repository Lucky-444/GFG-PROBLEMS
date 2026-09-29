class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<pair<int,int>> st;
        long long ans = 0;
        long long cnt = 0;

        for(auto x : nums) {

            while(!st.empty() && st.back().first > x) {
                cnt -= st.back().second;
                st.pop_back();
            }

            if(!st.empty() && st.back().first == x) {
                ans += cnt - st.back().second;
                st.back().second++;
            }
            else {
                ans += cnt;
                st.push_back({x, 1});
            }

            cnt++;
        }

        return ans;
    }
};