class Solution {
  public:
    int totalElements(vector<int> &s) {
        // code here
        // code here
        int n = s.size();
        unordered_map<long long,long long>mp;
        
        long long  i = 0 , j = 0  , ans = -1;
        
        while(j < n){
            mp[s[j]]++;
            
            if(mp.size() > 2){
                mp[s[i]]--;
                
                if(mp[s[i]] == 0) mp.erase(s[i]);
                
                i++;
            }
            //atmost 2 means max to max 2 distinct hoga
            //usse jyada nhi hoga
            //use kaam 0....1.....2 distinct hoga to chalega
            // so dont use if(mp.size() == 2) becoz in qn given that
            //max to max 2 hoga
            
                ans = max(ans , j - i + 1);
           
            
            j++;
        }
        
        return ans;
    }
};