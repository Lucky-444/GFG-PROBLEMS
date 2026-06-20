class Solution {
  public:
    int powerMod(int a , int b){
        int res = 1;
        
        a %= 10;
        
        while(b){
            if(b & 1){
                res = (res * a) % 10;
            }
            
            a = (a * a) % 10;
            
            b >>= 1;
        }
        
        return res;
    }
    int getLastDigit(string& a, string& b) {
        // code here
        
        //   a^(xy)
        // = a^(10*x + y)
        // = (a^x)^10 * a^y
        
        if (b == "0") {
            return 1;
        }

        int base = a.back() - '0';

        int result = 1;

        for (char ch : b) {

            int digit = ch - '0';

            // result = (a^x)^10
            result = powerMod(result, 10);

            // result *= a^digit
            result = (result * powerMod(base, digit)) % 10;
        }

        return result;

    }
};