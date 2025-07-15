class Solution {
  public:
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