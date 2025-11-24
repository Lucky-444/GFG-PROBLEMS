class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        //Problem Related to contribution Technique
        
        //how many Times The subarrays includes This arr[i]
        //means the contribution of arr[i]
        //for left boundary : i + 1 times
        //for right Boundary : n - i Times 
        
        //now calculate freq if it is 1 then add this to my ans
        
        int ans = 0 ;
        int n = arr.size();
        //Odd × Odd = Odd
        // (Anything × Even = Even)
        //left half  + right half cancel 
        // If n is even -> answer is always 0
        if(n % 2 == 0) return 0;
        
        for(int i = 0 ; i < arr.size() ; i ++){
            int left = i + 1; 
            int right = (n - i);
            //freq_i is odd only if both (i+1) and (n-i) are odd.
            if((left * right) & 1){
                ans ^= arr[i];
            }
        }
        
        return ans ;
    }
};