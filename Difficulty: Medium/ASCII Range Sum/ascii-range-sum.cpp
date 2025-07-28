class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n = s.size();
        unordered_map<char,int> first,last;
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum += s[i];
            if(first.find(s[i]) == first.end())
            {
                first[s[i]] = sum;
            }
            else
            {
                last[s[i]] = sum;
            }
        }
        
        vector<int> ans;
        for(char c = 'a';c<='z';c++)
        {
            if(last.find(c) != last.end())
            {
                int tem = (last[c] - first[c] - c);
                if(tem>0)
                ans.push_back(tem);
            }
        }
        return ans;
    }
};