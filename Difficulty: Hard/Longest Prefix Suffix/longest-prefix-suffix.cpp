class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
   if(s.length() == 1){
            return 0;
        }
        int i = 0, j = 1, len = s.length();
        while(j < len){
            if(s[j] == s[i]){
                i++;
            }
            else{
                j = j - i;
                i = 0;
            }
            j++;
        }
        return i;
    }
};