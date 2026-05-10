class Solution {
public:

    bool isPalindrome(string &s) {
        int i = 0, j = s.size() - 1;

        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    bool palindromePair(vector<string> &arr) {
        
        int n = arr.size();

        // Store reverse strings in hashmap
        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++) {
            string rev = arr[i];
            reverse(rev.begin(), rev.end());

            mp[rev] = i;
        }

        for(int i = 0; i < n; i++) {

            string s = arr[i];
            int len = s.size();

            // Split string into prefix and suffix
            for(int k = 0; k <= len; k++) {

                string left = s.substr(0, k);
                string right = s.substr(k);

                // Case 1:
                // If left part is palindrome,
                // then find reverse(right)
                if(isPalindrome(left)) {

                    if(mp.count(right) && mp[right] != i) {
                        return true;
                    }
                }

                // Case 2:
                // If right part is palindrome,
                // then find reverse(left)
                // k != len avoids duplicate checking
                if(k != len && isPalindrome(right)) {

                    if(mp.count(left) && mp[left] != i) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};