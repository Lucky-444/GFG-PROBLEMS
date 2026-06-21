class Solution {
  public:
    string chooseSwap(string &s) {
      set<char> st(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++) {

        st.erase(s[i]);

        if (!st.empty() && *st.begin() < s[i]) {

            char a = s[i];
            char b = *st.begin();

            for (char &c : s) {
                if (c == a)
                    c = b;
                else if (c == b)
                    c = a;
            }

            return s;
        }
    }

    return s;
    }
};
