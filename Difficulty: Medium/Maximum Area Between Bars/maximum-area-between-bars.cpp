class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
      int s=0, e=height.size()-1;
      
      int ans=0;
      
      while(s<e){
        ans=max(ans, min(height[s], height[e])*(e-s-1));
        if(height[s] < height[e]) s++;
        else e--;
      }
      
      return ans;
    }
};