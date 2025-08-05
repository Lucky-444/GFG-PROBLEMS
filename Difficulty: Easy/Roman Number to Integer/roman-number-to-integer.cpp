class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = 0;
        if(s.length()==1){
            return mp[s[0]];
        }
        else{
            for(int i=0;i<s.length()-1;i++){
                if(mp[s[i]] < mp[s[i+1]])
                ans -= mp[s[i]];
                else ans +=mp[s[i]];
            }
        }
        return ans + mp[s[s.length()-1]];
    }
};