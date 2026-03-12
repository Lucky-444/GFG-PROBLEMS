class Solution {
  public:
    
    bool isValid(string s){
        if(s.size() > 1 && s[0] == '0') return false; // leading zero
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void solve(string &s, int index, int parts, string path, vector<string> &ans){
        
        if(parts == 4 && index == s.size()){
            path.pop_back();          // remove last '.'
            ans.push_back(path);
            return;
        }
        
        if(parts >= 4) return;

        for(int len = 1; len <= 3; len++){
            
            if(index + len > s.size()) break;
            
            string temp = s.substr(index, len);
            
            if(isValid(temp)){
                solve(s, index + len, parts + 1, path + temp + ".", ans);
            }
        }
    }
    vector<string> generateIp(string &s) {
        // code here
         vector<string> ans;
        
        if(s.size() < 4 || s.size() > 12) return ans;
        
        solve(s, 0, 0, "", ans);
        
        return ans;
    }
};