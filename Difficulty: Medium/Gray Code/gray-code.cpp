class Solution {
  public:
    vector<string> solve(int n) {
        if (n == 1) {
            return {"0", "1"};
        }
        
        vector<string> prev = solve(n - 1);
        vector<string> res;
        
        // add '0' prefix
        for (auto &s : prev) {
            res.push_back("0" + s);
        }
        
        // add '1' prefix in reverse order
        for (int i = prev.size() - 1; i >= 0; i--) {
            res.push_back("1" + prev[i]);
        }
        
        return res;
    }

    vector<string> graycode(int n) {
        if (n == 0) return {"0"};
        return solve(n);
    }
};