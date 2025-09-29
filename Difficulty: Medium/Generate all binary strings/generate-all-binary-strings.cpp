class Solution {
  public:
    void generate(int n, string &cur, vector<string> &res) {
        if ((int)cur.size() == n) {
            res.push_back(cur);
            return;
        }
        // Add '0' first → ascending order
        cur.push_back('0');
        generate(n, cur, res);
        cur.pop_back();

        // Then add '1'
        cur.push_back('1');
        generate(n, cur, res);
        cur.pop_back();
    }

    vector<string> binstr(int n) {
        vector<string> res;
        string cur;
        generate(n, cur, res);
        return res;
    }
};