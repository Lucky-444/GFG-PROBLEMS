class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n = s.size();
        
        vector<int>vec(26 , -1);
        int ans = -1;
        for(int i = 0 ; i < n ;  i++){
            if(vec[s[i] - 'a'] == -1){
                vec[s[i] - 'a'] = i;
            }else{
                ans = max(ans , i - vec[s[i] - 'a'] - 1);
            }
        }
        
        return ans;
    }
};