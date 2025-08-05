class Solution {
  public:
    bool isPalinSent(string &ss) {
        // code here
        string s = "";
        for(auto c : ss){
            if (isalpha(c)) {
                s.push_back(tolower(c));
            }else if(isdigit(c)){
                s.push_back(c);
            }
                
        }
        
        string rev = s;
        reverse(rev.begin() , rev.end());
        
        return s == rev;
    }
};