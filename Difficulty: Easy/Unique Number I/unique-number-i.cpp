class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int xr = 0;
        
        for(auto it : arr){
            xr ^= it;
        }
        
        return xr;
    }
};