class Solution {
  public:
    bool armstrongNumber(int n) {
        int original = n;
        // code here
        int sum = 0;
        
        while(n){
            int rem = (n % 10);
            sum += (rem * rem * rem);
            n /= 10;
        }
        
        return sum == original;
    }
};