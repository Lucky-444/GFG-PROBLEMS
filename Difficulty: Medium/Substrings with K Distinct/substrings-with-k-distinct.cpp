class Solution {
  public:
    int solve(string s , int k){
        int n = s.size();
        int i = 0 , j = 0 , ans = 0;
        int freq[26] = {0};
        int distinct = 0;

        
        while(j < n){
            if(freq[s[j] - 'a'] == 0){
                distinct ++ ;
            }
            freq[s[j] - 'a']++;
            while(distinct > k){
                freq[s[i] - 'a'] -- ;
                if(freq[s[i] -'a'] == 0){
                    distinct -- ;
                }
                
                i ++ ;
            }
            
            ans += (j - i + 1);
            j ++; 
        }
        
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here
        return solve(s , k) - solve(s , k - 1);
    }
};