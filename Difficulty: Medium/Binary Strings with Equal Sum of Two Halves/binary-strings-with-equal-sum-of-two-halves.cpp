class Solution {
  public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    int computeValue(int n) {
        // code here
        vector<long long> fact(2 * n + 1);
        vector<long long> invFact(2 * n + 1);

        fact[0] = 1;
        for (int i = 1; i <= 2 * n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[2 * n] = power(fact[2 * n], MOD - 2);

        for (int i = 2 * n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        long long ans = fact[2 * n];
        ans = ans * invFact[n] % MOD;
        ans = ans * invFact[n] % MOD;

        return ans;
    }
};