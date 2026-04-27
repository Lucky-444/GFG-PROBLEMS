class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
           unordered_map<char, int> freq;
      int i=0, j=0;
      
      int maxFreq=0, ans=0;
      
      for(char ch: s){
          freq[ch]++;
          maxFreq = max(maxFreq, freq[ch]);
          
          if((maxFreq + k) < (j-i+1)){
              freq[s[i]]--;
              i++;
          }
          
          if((maxFreq + k) >= (j-i+1)){
              ans = max(ans, j-i+1);
          }
           
          j++;
      }
      
      return ans;
    }
};