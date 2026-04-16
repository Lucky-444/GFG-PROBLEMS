class Solution {
  public:
    int myAtoi(string &s) {
        int i = 0, n = s.size();

        // 1. skip spaces
        while (i < n && s[i] == ' ') i++;

        // 2. check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. read digits
        long long num = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. check overflow BEFORE adding
            if (num > (LLONG_MAX / 10)) break;

            num = num * 10 + digit;

            // clamp to 32-bit range
            if (sign * num > INT_MAX) return INT_MAX;
            if (sign * num < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * num);
    }
};