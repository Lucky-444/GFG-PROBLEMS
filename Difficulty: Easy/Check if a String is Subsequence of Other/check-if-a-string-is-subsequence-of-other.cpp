class Solution {
  public: 
    bool solve(string &s , string &t){
        int  i = 0 , n = s.size() , m = t.size();
        int j = 0;
        
       while(i < n && j < m){
            if(s[i] == t[j]){
                i++; // move both when characters match
            }
            j++; // always move in t
        }
        return i == n; // if we matched all of s
    }
    bool isSubSeq(string& s1, string& s2) {
        // code here
        return solve(s1 , s2);
    }
};