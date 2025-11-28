class Solution {
  public:
    int countSetBits(int n) {
    long long ans = 0;

    for (long long i = 0; (1LL << i) <= n; i++) {
        long long block = 1LL << (i + 1);
        long long half = 1LL << i;

        long long fullCycles = (n + 1) / block;
        long long remainder = (n + 1) % block;

        ans += fullCycles * half + max(0LL, remainder - half);
    }
    return ans;
    }
};
