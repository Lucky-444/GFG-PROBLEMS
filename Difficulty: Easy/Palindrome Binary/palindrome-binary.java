// User function Template for Java

class Solution {
    static long isPallindrome(long N) {
        String s=Long.toBinaryString(N);
        String sb=new StringBuilder(s).reverse().toString();
        return s.equals(sb)?1:0;
    }
}