class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_set<int>st;
        
        for(auto it : s){
            if(st.count(it)){
                st.erase(it);
            }else{
                st.insert(it);
            }
        }
        
        return st.size() <= 1;
    }
};