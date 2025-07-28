class Solution {
public:
    vector<int> asciirange(string& s) {
        int n = s.size();
        unordered_map<char, pair<int, int>> mp;  // {first_index, last_index}

        for (int i = 0; i < n; ++i) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]].first = i;
            }
            mp[s[i]].second = i;
        }

        // Build prefix sum vector
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + s[i];  // ASCII value
        }

        vector<int> ans;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (mp.find(c) != mp.end()) {
                int l = mp[c].first;
                int r = mp[c].second;
                
                
                if (l != r) { // only if character occurs more than once
                    int range_sum = prefix[r] - prefix[l + 1];
                    int val = range_sum ;
                    if (val > 0)
                        ans.push_back(val);
                }
            }
        }

        return ans;
    }
};
