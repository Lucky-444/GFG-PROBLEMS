class Solution {
  public:
    bool solve(int num , int d , int n){
        int sum = 0;
        int original = num;
        
        while(num){
            sum += (num % 10);
            num /= 10;
        }
        
        if(original - sum >= d){
            return true;
        }
        else{
            return false;
        }
    }
    int getCount(int n, int d) {
        // code here
        int low = 1 , high  = n ;
        
        int ans = -1;
        
        while(low <= high){ 
            int mid = (low + high) >> 1;
            
            if(solve(mid , d , n)){
                ans = mid ;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        if(ans == -1){
            return 0L;
        }
        
        return n - ans + 1;
    }
};