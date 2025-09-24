class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        int len = log2(n);
        
        vector<string>ans;
        
        for(int i = 1; i <= n ; i++){
            string s ;
            s = bitset<32>(i).to_string();
            s = s.substr(s.find('1'));
            ans.push_back(s);
        }
        
        return ans;
        
    }
};