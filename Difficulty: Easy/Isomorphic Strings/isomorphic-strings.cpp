class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        unordered_map<char , int>mp;
        unordered_map<char, char> mp2;
        for(int i = 0 ; i < s1.size() ; i ++){
            if(mp.find(s1[i]) != mp.end()){
                if(mp[s1[i]] !=  s2[i]){
                    return false;
                }
            }else{
                mp[s1[i]] = s2[i];
            }
            
            if(mp2.find(s2[i]) != mp2.end()){
                if(mp2[s2[i]] != s1[i])
                    return false;
            } 
            else{
                mp2[s2[i]] = s1[i];
            }
        }
        
        return true;
    }
};