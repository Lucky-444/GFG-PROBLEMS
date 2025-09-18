class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int cnt = 0; // tracks unmatched '('
        int ans = 0; // tracks number of ')' that need an extra '('

        for (auto c : s) {
            if (c == '(') {
                cnt++; // one more '(' to match
            } else if (c == ')') {
                if (cnt == 0) {
                    // no unmatched '(' available for this ')'
                    ans++; // we need to add a '('
                } else {
                    // match this ')' with a previous '('
                    cnt--;
                }
            }
        }

        // At the end, cnt will be the number of unmatched '('
        return ans + cnt;
    
    }
};