class Solution {
  public:
    bool solve(int num , int n , int d){
        
        int orig = num;   // Store original number
        
        int sum = 0 ;     // Variable to store sum of digits
        
        // Calculate sum of digits
        while(num){
            sum += (num % 10);   // Add last digit
            num /= 10;           // Remove last digit  ✅ (Corrected here)
        }
        
        // Check required condition
        return (orig - sum >= d);
    }
    int getCount(int n, int d) {
        // We need to find the smallest number
        // such that number - sum_of_digits >= d
        
        int ans = -1;
        int low = 1 , high = n ; 
        
        // Binary Search
        while(low <= high){
            
            int mid = (low + high) >> 1;   // Avoid overflow
            
            if(solve(mid , n , d)){
                ans = mid;         // Store possible answer
                high = mid - 1;    // Try to find smaller valid number
            }else{
                low = mid + 1;     // Move right
            }
        }
        
        // If no valid number found, return 0
        return ans == -1 ? 0 :n -  ans + 1 ;
    }
};