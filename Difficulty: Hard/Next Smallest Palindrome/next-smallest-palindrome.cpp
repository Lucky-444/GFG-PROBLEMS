class Solution {
  public:
    vector<int> nextPalindrome(vector<int> &a) {
        int n = a.size();
        
        // Case 1: all digits are 9
        bool all9 = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != 9) {
                all9 = false;
                break;
            }
        }
        
        if (all9) {
            vector<int> ans(n + 1, 0);
            ans[0] = ans[n] = 1;
            return ans;
        }
        
        vector<int> ans = a;
        
        // Step 1: mirror left to right
        for (int i = 0; i < n / 2; i++) {
            ans[n - 1 - i] = ans[i];
        }
        
        // Step 2: if already greater
        if (ans > a) return ans;
        
        // Step 3: add 1 to middle
        int carry = 1;
        int mid = n / 2;
        
        if (n % 2 == 1) {
            ans[mid] += carry;
            carry = ans[mid] / 10;
            ans[mid] %= 10;
            mid--;
        } else {
            mid--;
        }
        
        while (mid >= 0 && carry) {
            ans[mid] += carry;
            carry = ans[mid] / 10;
            ans[mid] %= 10;
            ans[n - 1 - mid] = ans[mid];
            mid--;
        }
        
        // Mirror again
        for (int i = 0; i < n / 2; i++) {
            ans[n - 1 - i] = ans[i];
        }
        
        return ans;
    }
};