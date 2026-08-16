class Solution {
  public:
      vector<int> arr;
      long long dp[1 << 10];
      bool vis[1 << 10];

      long long solve(int mask) {

          // Non-empty subset
          if (mask != 0) {
              bool found = false;

              // Find one selected element and remove it
              for (int i = 0; i < arr.size(); i++) {
                  if (mask & (1 << i)) {
                      found = true;

                      int prevMask = mask ^ (1 << i);

                      // If this is the only element
                      if (prevMask == 0)
                          return arr[i];

                      return arr[i] * solve(prevMask);
                  }
              }
          }

          return 1;
      }

      int minProd(vector<int>& nums) {
          arr = nums;

          long long ans = LLONG_MAX;

          int n = arr.size();

          for (int mask = 1; mask < (1 << n); mask++) {
              ans = min(ans, solve(mask));
          }

          return ans;
      }
  };