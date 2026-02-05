// Function to return maximum XOR subset in set[]

class Solution {
  public:
    int maxSubsetXOR(int arr[], int n) {
        // Your code here
        //You solve it using a bitwise linear basis (Gaussian elimination on bits).
        /*
            To maximize XOR:

            Higher bits matter more
            
            We try to keep numbers that contribute new high bits
            
            Remove redundancy using XOR (similar to Gaussian elimination)
        
        */
        vector<int>vec(31 , 0);
        
        for(int i = 0 ; i < n ; i ++){
            int curr = arr[i];
            
            for(int i = 31 ; i >= 0 ; i --){
                if(!(curr & (1 << i))){
                    continue; 
                }
                
                if(!vec[i]){
                    vec[i] = curr;
                    break;
                }
                
                curr ^= vec[i];
            }
        }
        
        int ans = 0;
        
        for(int i = 31 ; i >= 0 ; i --){
            ans = max(ans , ans ^ vec[i]);
        }
        
        return ans;
        
    }
};