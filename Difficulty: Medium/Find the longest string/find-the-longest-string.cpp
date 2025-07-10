class Solution {
public:
    string longestString(vector<string> &words) {
        sort(words.begin(), words.end());
        set<string> st;
        st.insert("");  // base case: empty string is valid
        string ans;

        for (string s : words) {
            string prefix = s.substr(0, s.length() - 1);
            if (st.count(prefix)) {
                st.insert(s);  // mark this string as valid
                
                if (s.length() > ans.length()) {
                    ans = s;
                } 
                
                else if (s.length() == ans.length()) {
                    ans = min(ans, s);
                }
            }
        }

        return ans;
    }
};
