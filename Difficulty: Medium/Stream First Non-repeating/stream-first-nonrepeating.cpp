class Solution {
  public:
    string firstNonRepeating(string &s) {
        unordered_map<char, int> mp;
        queue<char> q;
        string ans = "";

        for (char ch : s) {
            mp[ch]++;
            q.push(ch);

            // remove repeating characters from front
            while (!q.empty() && mp[q.front()] > 1) {
                q.pop();
            }

            if (q.empty()) {
                ans += '#';
            } else {
                ans += q.front();
            }
        }

        return ans;
    }
};
