

class Solution {
  public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n) {
        // Complete the function
        long long int ans = 0;

        // Check each bit position
        for(int bit = 0; bit < 32; bit++) {
            long long int  cnt1 = 0;

            // Count how many numbers have this bit set
            for(int i = 0; i < n; i++) {
                if(arr[i] & (1 << bit))
                    cnt1++;
            }

            long long int cnt0 = n - cnt1;

            // Contribution of this bit
            ans += cnt1 * cnt0 * (1LL << bit);
        }

        return ans;
    }
};