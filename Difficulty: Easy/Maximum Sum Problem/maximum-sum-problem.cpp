class Solution {
  public:
    int maxSum(int n) {
        // code here.
         if(int(n/2) + int(n/3) + int(n/4)<=n)
                return n;
            return maxSum(int(n/2))+maxSum(int(n/3))+maxSum(int(n/4));
    }
};