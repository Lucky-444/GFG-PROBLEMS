class Solution {
  public:
    vector<int> Zfunc(string &s){
        int n = s.size();
        
        vector<int> z(n);
        int l = 0, r = 0;
        
        for(int i=1;i<n;i++){
            if(i < r)
                z[i] = min(z[i - l], r - i);//len check till r, as we've explored s till r
            
            while(i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++;//increase z[i] as long as it matches w/ pre
            
            if(i + z[i] > r){
                l = i;
                r = i + z[i];
            }
        }
        
        return z;
    }

    int countDistinctSubstring(string s){
        int n = s.size();
        int count = 0;
        
        for(int i=0;i<s.size();i++){
            string rS = s.substr(0, i + 1);
            
            reverse(rS.begin(), rS.end());
            
            vector<int> z = Zfunc(rS);
            
            count += ((i + 1) - *max_element(z.begin(), z.end()));
        }
        
        return count + 1;
    }
    int countSubs(string& s) {
        // code here
        return countDistinctSubstring(s) - 1;
        
    }
};