class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int i = 0 , j = 0 , ans = -1;
        int zero_cnt = 0;
        
        while(j < n){
            if(arr[j] == 0){
                zero_cnt ++;
            }
            
            while(zero_cnt > k){
                if(arr[i] == 0){
                    zero_cnt --;
                }
                
                i++;
            }
            
            ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};
