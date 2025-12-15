class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        //check subsequence or not
        s1 = s1 + s1; //ro
        int i = 0 , j = 0 ; 
        int n = s1.size() , m = s2.size();
        
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                j ++;
            }
            
            i ++;
        }
        
        return j == m;
    }
};