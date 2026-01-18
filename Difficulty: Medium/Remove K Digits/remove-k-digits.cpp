class Solution {
  public:
    string removeKdig(string &s, int k) {
        // using monotonic stack
        string temp = "";
        
        for(int i = 0; i < s.size(); i++){
            while(!temp.empty() && temp.back() > s[i] && k > 0){
                temp.pop_back();
                k--;
            }
            
            // avoid leading zeros
            if(!temp.empty() || s[i] != '0'){
                temp.push_back(s[i]);
            }
        }
        
        // remove remaining digits if k > 0
        while(k > 0 && !temp.empty()){
            temp.pop_back();
            k--;
        }
        
        // if all digits removed
        if(temp.empty()){
            return "0";
        }
        
        return temp;
    }
};
