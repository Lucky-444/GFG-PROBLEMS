class Solution {
  public:
    int gcd(int a , int b){
        if(b == 0){
            return a;
        }
        
        return gcd(b , a % b);
    }
    
    int lcm(int a , int b){
        int mul = a * b;
        int x = gcd(a , b);
        
        return mul / x;
    }
    int pairCount(int x, int y) {
        // code here
        int ans = 0;
        
        int maxi = x * y;
        
        for(int i = 1 ; i * i <= maxi ; i ++){
            if(maxi % i == 0){
                int t = maxi / i;
                
                
                if(gcd(t , i) == x && lcm(t , i) == y){
                    if(t != i){
                        ans += 2;
                    }else{
                        ans ++;
                    }
                }
            }
        }
        
        return ans;
    }
};