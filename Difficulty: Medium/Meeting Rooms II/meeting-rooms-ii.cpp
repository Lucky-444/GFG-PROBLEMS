class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        map<int, int> mp;

        int n = start.size();

        for (int i = 0; i < n; i++) {
            mp[start[i]]++;
            mp[end[i]]--;
        }

        int active = 0;
        int ans = 0;

        for (auto &[time, delta] : mp) {
            active += delta;
            ans = max(ans, active);
        }

        return ans;
    }
};
