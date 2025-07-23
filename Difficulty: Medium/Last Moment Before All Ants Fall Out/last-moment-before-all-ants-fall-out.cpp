class Solution {
  public:
  /**
   * Plank length = n.

Ants move left from positions in left[].

They fall off in t = pos.

Ants move right from positions in right[].

They fall off in t = n - pos.

Ignore the collisions (they just pass through).
  */
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        //jo left se jaa raha hai ho jarur right se takraega
        //jo left se chal kar aa raha hai ho agar at position bahut dur hai then he will be at last fall 
        //if there is no right takraega
        int maxVal = 0;
        for(auto it : left){
            maxVal = max(maxVal ,it);
        }
        
        
        //now right se jo paas hai uska minimum nikalo
        int minVal = n;
        for(auto it : right){
            minVal = min(minVal , it);
        }
        
        return max(n - minVal , maxVal);
    }
};