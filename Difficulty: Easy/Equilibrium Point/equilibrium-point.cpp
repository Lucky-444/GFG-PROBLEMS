class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int total_sum = accumulate(arr.begin() , arr.end() , 0);
        
        int sum = 0;
        
        for(int i = 0 ; i < arr.size() ; i ++){
          
            
            int rem = total_sum - sum;
            
            if(sum == rem){
                return i;
            }
        }
        
        return -1;
        
    }
};