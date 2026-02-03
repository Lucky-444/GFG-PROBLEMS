class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        //max Val in Left
        int maxi = 0;
        for(auto it : left){
            maxi = max(maxi , it);
        }
        
        int mini  = n ; 
        
        for(auto it : right){
            mini = min(mini , it);
        }
        
        return max(n - mini , maxi);
    }
};