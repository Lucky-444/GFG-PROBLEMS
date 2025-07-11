class Solution {
  public:
  /*        input          output     observation
        for n = 1 ------->    0         0 * 2 + 0 = 0
        for n = 2 ------->    1         0 * 2 + 1 = 1
        for n = 3 ------->    3         1 * 2 + 1 = 3
        for n = 4 ------->    8         3 * 2 + 2 = 8
        for n = 5 ------->    19        8 * 2 + 3 = 19
        for n = 6 ------->    43        19 * 2 + 5 = 43
        
        observation is fibonacci seq(0 ,1 , 1, 2, 3, 5 ...) with multiplication of 2 with 
        previous Number
  
  */
    int countConsec(int n) {
        // code here
        
        if(n == 2) return 1 ;
        
        int res = 1 , firstNum = 0  , secondNum = 1 ;
        
        for(int i = 3 ; i <= n ; i++){
            int thirdNum = firstNum + secondNum;
            res  = res * 2 + thirdNum;
            
            firstNum = secondNum;
            secondNum = thirdNum;
        }
        
        return res;
        
    }
};