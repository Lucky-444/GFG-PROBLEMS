class Solution {
public:

    // Check whether adding x to the current window
    // will create 3 distinct indices satisfying a + b = c
    bool isInvalid(vector<int>& freq, int x) {

        for(int a = 1; a <= 500; a++) {

            if(freq[a] == 0)
                continue;

            // CASE 1:
            // x is the SUM:
            // a + b = x
            //
            // If 'a' already exists, then b must be x-a.
            int b = x - a;

            if(b >= 1 && b <= 500) {

                if(a == b) {
                    // a + a = x
                    // Need two DIFFERENT indices having value a.
                    if(freq[a] >= 2)
                        return true;
                }
                else {
                    // We already have an 'a'.
                    // If 'b' also exists, we have 3 distinct indices:
                    // a, b, x
                    if(freq[b] > 0)
                        return true;
                }
            }


            // CASE 2:
            // x is one of the two numbers:
            // a + x = b
            //
            // b must be a + x.
            int b2 = a + x;

            if(b2 <= 500) {

                // 'a' exists and 'b2' exists,
                // so a + x = b2.
                //
                // Their indices are distinct because x
                // is the NEW element being added.
                if(freq[b2] > 0)
                    return true;
            }
        }

        return false;
    }


    int maxSubarray(vector<int>& nums) {

        int n = nums.size();

        // freq[v] = number of times value v
        // occurs in the current window [l ... r-1].
        vector<int> freq(501, 0);

        int l = 0;
        int ans = 0;

        for(int r = 0; r < n; r++) {

            int x = nums[r];

            // Before adding x, check whether x
            // creates an invalid triple with the current window.
            //
            // If invalid, remove elements from the left
            // until adding x becomes safe.
            while(l < r && isInvalid(freq, x)) {

                freq[nums[l]]--;
                l++;
            }

            // Now x can safely be added.
            freq[x]++;

            // Current window [l ... r] is valid.
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};