

class Solution {
  public:
    map<char , int>mp ;
    vector<string>ans; 
    void generate(int curr , int len , char odd, string temp){
        if(curr == len){
            string rev = temp ; 
            reverse(rev.begin() , rev.end()) ; 
            string res = temp ; 
            if(odd != '\0'){
                res += odd; 
            }
            
            res += rev; 
            ans.push_back(res);
            
            return ; 
        }
        
        for (auto &it : mp) {
            if (it.second > 0) {
                it.second--;
                generate(curr + 1, len, odd, temp + it.first);
                //backtracking
                it.second++;
            }
        }
    }
    vector<string> all_plaindromes(string s) {
        // Code here
        mp.clear();
        ans.clear();
        for(auto it : s){
            mp[it] ++ ; 
        }    
        
        int odd = 0 ;
        char mid = '\0';
        int len = 0 ;
        
        for(auto &[ch , freq] : mp){
            if(freq % 2 == 1){
                odd ++ ; 
                mid = ch ;
            }
            
            if(odd > 1){
                return  {} ; 
            }
            
            freq /= 2;
            len += freq;
        }
        
        generate(0, len, mid, "");
        
        sort(ans.begin() , ans.end()); 
        
        return ans;
        
    }
};
