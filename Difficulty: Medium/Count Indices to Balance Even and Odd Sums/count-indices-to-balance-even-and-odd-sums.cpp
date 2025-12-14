class Solution {
  public:
    int cntWays(vector<int>& nums) {
        // code here
        //calculate the prefix sum of odd and even
        int n = nums.size();
        vector<int>odd(n + 1 , 0 ) , even(n + 1 , 0);
        for(int i = 0 ; i < n ; i++){
            odd[i + 1] = odd[i];
            even[i + 1] = even[i];

            if(i & 1){
                odd[i + 1] += nums[i];
            }
            else{
                even[i + 1] += nums[i];
            }
        }


        //now find the relation
        //if i delete one index then on its right 
        // the even prfix sum becomes odd 
        // and the odd prefix sum becomes even
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            int oddLeft = odd[i];
            int evenLeft = even[i];

            //if i remove this element then
            //is it satisfy the condition or not check

            int evenRight = odd[n] - odd[i + 1];
            int oddRight = even[n] - even[i + 1];

            if(oddLeft + oddRight == evenLeft + evenRight){
                cnt++;
            }
        }

        return cnt;
    }
};