class Solution {
  public:
    //New Approach 
    /*  All primes greater than 3 can be written as 6k - 1 or 6k + 1.
        First handle n <= 3.
        Remove multiples of 2 and 3.
        Then check divisors 5, 7, 11, 13, 17, 19, ... by testing i and i + 2 where i increases by 6.
    */
    bool isPrime(int n) {
        // code here
        if(n <= 1) return false;
        if(n <= 3) return true;

        if(n % 2 == 0 || n % 3 == 0)
            return false;
        
        //5, 11, 17, 23, 29, ...
        //These are all numbers of the form 6k − 1.
        for(int i = 5; 1LL * i * i <= n; i += 6) {
            //i + 2 Gives
            // 7, 13, 19, 25, 31, ...
            // These are all numbers of the form 6k + 1.
            //So check n % i and n % (i + 2) == 0
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        
        /*
            6k + 0  -> divisible by 6
            6k + 1  -> possible prime
            6k + 2  -> divisible by 2
            6k + 3  -> divisible by 3
            6k + 4  -> divisible by 2
            6k + 5  -> same as 6k - 1 -> possible prime
            
            6k+1 and 6k+5 (= 6(k+1)-1)
        */

        return true;
    }
};
