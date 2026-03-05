class Solution {
  public:
    string minWindow(string &s1, string &s2) {
        // code here
        int n = s1.length(), m = s2.length() ;
        
        unordered_map<char,int> mp;
        int dist = 0;
        for(auto ch : s2){ 
            mp[ch]++;
           
        } 
        
        dist = mp.size();
        
        unordered_map<char,int> charcnts; 
        int st = 0 ;
        int size = n;
        int start = -1 , end = -1;
        int matchCount =0;
        for(int ed = 0; ed < n; ed++) 
        {
            charcnts[s1[ed]]++ ;
            
            if(mp[s1[ed]] == charcnts[s1[ed]]) matchCount++ ;
            
            if(matchCount == dist) {
                while((charcnts[s1[st]] > mp[s1[st]])) 
                {
                    charcnts[s1[st]]--;
                    st++;
                }
                if((ed - st + 1) < size) 
                {
                    size = ed - st + 1; 
                    start = st ;
                    end = ed ;
                }
            }
        }
        return (start == -1) ? "" : s1.substr(start,size) ;
    }
};