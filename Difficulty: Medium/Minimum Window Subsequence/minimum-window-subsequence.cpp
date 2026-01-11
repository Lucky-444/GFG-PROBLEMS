class Solution {
  public:
    bool check_subequence(string &s1 , string &s2 , int i , int j){
        int start = 0;
        
        for(int k = i ; k <= j ; k ++){
            if(s1[k] == s2[start]){
                start ++;
            }
        }
        
        return start >= s2.size();
    }
    string minWindow(string& s1, string& s2) {
        // Code here
        //Qn said minimum window subsequence
        int n = s1.size();
        int first = 0 , second = 0 ;
        
        int i = 0 , j = 0 , ans = INT_MAX ;
        
        
        while(j < n){
            
            while(check_subequence(s1 , s2 ,i,  j)){
                if(ans > j - i + 1){
                    //if smaller length
                    first = i ;
                    second = j ;
                    ans = j - i + 1;
                }
                
                i ++;
            }
            
            j ++; 
        }
        
        //last check after traversal
        string s = s1.substr(first , second - first + 1);
        
        int l = 0 ;
        for(int k = 0 ; k <= s.length() ; k ++){
            if(s[k] == s2[l]){
                l ++;
            }
        }
        
        if(l >= s2.size()){
            return s ; 
        }
        
        return "";
        
    }
};
