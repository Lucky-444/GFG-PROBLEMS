class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        // code here
        string s = "";
        
        while(n){
            int rem = n % 2;
            s += to_string(rem);
            n /= 2;
        }
        
        reverse(s.begin() , s.end());
        int maxi = -1;
        int cnt = 0;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == '1'){
                cnt ++;
            }else{
                maxi = max(cnt , maxi);
                cnt = 0;
            }
        }
        //If the binary string ends with '1', you never update maxi after the loop.
        maxi = max(cnt , maxi);
        return maxi;
    }
};
