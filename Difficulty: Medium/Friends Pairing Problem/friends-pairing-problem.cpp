class Solution {
  public:
  /*
    f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1) n-th person remains single, so only 1 way so  we recur 
   for remaining i.e f(n - 1)   
   or you can say 1*f(n-1)
2) n-th person pairs up with any of the remaining n - 1 persons. 
   So apart from the 2 people forming a pair for remaining n-2 persons we We get (n - 1) * f(n - 2) ways

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)
  
  */
    int countFriendsPairings(int n) {
        // code here
        if(n <= 2){
            return n;
        }
        
        return countFriendsPairings(n - 1) + countFriendsPairings(n - 2) * (n - 1);
    }
};
