class Solution {
  public:
   vector<string> result;

    void backtrack(string &s, int idx, long long currEval, long long lastOperand, string expr, int target) {
        // If we reached the end of string
        if (idx == s.size()) {
            if (currEval == target) {
                result.push_back(expr);
            }
            return;
        }

        long long num = 0;
        string currNumStr = "";
        
        // Try all possible splits
        for (int i = idx; i < s.size(); i++) {
            // build current number
            num = num * 10 + (s[i] - '0');
            currNumStr.push_back(s[i]);

            // Skip numbers with leading zero
            if (currNumStr.size() > 1 && currNumStr[0] == '0') break;

            if (idx == 0) {
                // First number → start expression
                backtrack(s, i + 1, num, num, currNumStr, target);
            } else {
                // Add '+'
                backtrack(s, i + 1, currEval + num, num, expr + "+" + currNumStr, target);

                // Add '-'
                backtrack(s, i + 1, currEval - num, -num, expr + "-" + currNumStr, target);

                // Add '*'
                backtrack(s, i + 1, currEval - lastOperand + lastOperand * num,
                          lastOperand * num, expr + "*" + currNumStr, target);
            }
        }
    }
    vector<string> findExpr(string &s, int target) {
        // code here
        result.clear();
        backtrack(s, 0, 0, 0, "", target);
        sort(result.begin(), result.end()); // lexicographically smallest order
        return result;
    }
};