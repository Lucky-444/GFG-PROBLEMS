class Solution {
  public:
  /**
   *  Digit '2': rem = (0 * 10 + 2) % 13 = 2
    -> Digit '9': rem = (2 * 10 + 9) % 13 = 29 % 13 = 3
    -> Digit '1': rem = (3 * 10 + 1) % 13 = 31 % 13 = 5
    -> Digit '1': rem = (5 * 10 + 1) % 13 = 51 % 13 = 12
    -> Digit '2': rem = (12 * 10 + 2) % 13 = 122 % 13 = 5
    -> Digit '8': rem = (5 * 10 + 8) % 13 = 58 % 13 = 6
    -> Digit '5': rem = (6 * 10 + 5) % 13 = 65 % 13 = 0
   * 
   * School DIvision Process
   * 
  */
    bool divby13(string &s) {
        // code here
        //just try modulous property
        //(A + B) % M = (A % + B % M)  % M;
        
        //calculating mod at each step
        int n = s. size();
        
        int res = 0;
        
        for(int i = 0 ; i < n ; i ++){
            int digit = s[i] - '0';
            
            res = (res * 10 + digit) % 13 ; 
        }
        
        return res == 0;
    }
};