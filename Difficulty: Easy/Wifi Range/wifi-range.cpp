class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.size();
        int last = -1;
        
        for (int i = 0; i < n; i++) {

            // If current room is not covered
            if (i > last) {

                bool found = false;

                // Find a router that can cover room i
                for (int j = max(0, i - x); 
                     j <= min(n - 1, i + x); j++) {

                    if (s[j] == '1') {
                        last = j + x;   // farthest coverage
                        found = true;
                    }
                }

                if (!found)
                    return false;
            }
        }

        return true;
    }
};