class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        multiset<int>st(arr.begin() ,arr.end());
        
        for(int i = 1 ; i < 1e6 ; i++){
            if(!st.count(i)){
                return i;
            }
        }
        
        return 1;
    }
};