class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        while(r>l)
        r = r&(r-1);
        return r&l;   
    }
};
