class Solution {
  public:
    bool check(string s,string t,int i,int j)
    {   
        int start = 0;
        
        for(int k=i;k<=j;k++)
        {
            if(s[k] == t[start])
            {
                start++;
            }
        }   
        
        return start >= t.length();
    }
  
    string minWindow(string& str1, string& str2) {
        int i=0;
        int j=0;
        int n = str1.length();
        int ans = INT_MAX;
        int first = 0;
        int second = 0;
        
  
        
        while(j<n)
        {

            while(check(str1,str2,i,j))
            {   
                
                if(ans > (j-i+1))
                {
                    first = i;
                    second = j;
                    ans = j-i+1;
                }
                
                i++;
            }
            
            j++;
        }
        
        string ck = str1.substr(first,second-first+1);
        
        int start = 0;
        
        for(int k=0;k<=ck.length();k++)
        {
            if(ck[k] == str2[start])
            {
                start++;
            }
        }   
        
        if(start >= str2.length())
        {
            return ck;
        }
        
        return "";
    }
};
