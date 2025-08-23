class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        return __builtin_popcount(n);
    }
};