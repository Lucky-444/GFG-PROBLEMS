class Solution {
public:
    const long long MOD = 1e9 + 7;

    int prefixStrings(int N) {

        vector<long long> inv(N + 2);

        inv[1] = 1;

        for (int i = 2; i <= N + 1; i++) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        }

        long long ans = 1;

        for (long long i = 1https://www.geeksforgeeks.org/ai-ml-and-data-science-tutorial-learn-ai-ml-and-data-science/; i <= N; i++) {

            ans = ans * (4 * i - 2) % MOD;
            ans = ans * inv[i + 1] % MOD;
        }

        return ans;
    }
};