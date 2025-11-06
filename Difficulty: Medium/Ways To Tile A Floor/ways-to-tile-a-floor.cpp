class Solution {
  public:
    int solve(int n){
        if(n == 1){
            return 1;
        }
        
        if(n == 2){
            return 2;
        }
        
        if(n == 3){
            return 3; 
        }
        
        return solve(n - 1) + solve(n - 2);
    }
    int numberOfWays(int n) {
        // code here
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2; // a=T(1), b=T(2)
        for (int i = 3; i <= n; ++i) {
            int c = a + b; // T(i) = T(i-1) + T(i-2)
            a = b;
            b = c;
        }
        return b;
        
        //return solve(n);
    }
};