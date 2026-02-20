class Solution {
  public:
    int hIndex(vector<int>& c) {
        // code here
         sort(c.begin(),c.end());
         int i=c.size();
         int j=0;
         while(i>c[j]){
             j++;
             i--;
             
         }
         return i;
    }
};