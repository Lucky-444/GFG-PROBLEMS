class Solution {
  public:
    bool isBitSet(int   N) {
        // code here
       if(N==0) return 0;
        return (N & (N+1)) == 0 ? 1 : 0; 
    }
};