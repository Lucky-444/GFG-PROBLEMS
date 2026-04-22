class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i ++){
            sum += arr[i];
        }
        int prefix = 0;
        for(int i = 0 ; i < arr.size() ; i ++){
            prefix += arr[i];
            int left = sum - prefix;
            
            if(left == prefix){
                return true;
            }
        }
        
        return false;
    }
};
