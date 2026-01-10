#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        unordered_map<char, vector<int>> pos;
        
        for (int i = 0; i < n; i++)
            pos[s1[i]].push_back(i);
        
        string ans = "";
        int minLen = INT_MAX;

        // try all starting indices of first character of s2 in s1
        for (int start : pos[s2[0]]) {
            int prev = start;
            bool valid = true;
            
            // find positions for the rest of s2
            for (int j = 1; j < m; j++) {
                auto it = upper_bound(pos[s2[j]].begin(), pos[s2[j]].end(), prev);
                if (it == pos[s2[j]].end()) {
                    valid = false;
                    break;
                }
                prev = *it;
            }
            
            if (valid) {
                int len = prev - start + 1;
                if (len < minLen) {
                    minLen = len;
                    ans = s1.substr(start, len);
                }
            }
        }
        
        return ans;
    }
};
