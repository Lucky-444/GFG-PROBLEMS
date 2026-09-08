class Solution {
  public:
    int digit_sum(int n){
        int sum = 0;
        
        while(n){
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        
        return sum;
    }
    int findMax(int n) {
        // code Here
        
        //Calculate The runing Digit Sum while removing the Current Digit By -1
        long long ans = n;
        int best = digit_sum(n);

        string s = to_string(n);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue;

            string t = s;

            t[i]--;

            for (int j = i + 1; j < s.size(); j++) {
                t[j] = '9';
            }

            long long x = stoll(t);
            int sum = digit_sum(x);

            if (sum > best || (sum == best && x > ans)) {
                best = sum;
                ans = x;
            }
        }
        return ans;
    }
};
