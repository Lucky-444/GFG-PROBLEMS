class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin() , arr.end());
        int i = 0 , j = 0 , n = arr.size();
        
        //sliding Window Template
        int ans = 0 ;
        while(j < n){
            while(arr[j] - arr[i] >= k){
                i ++;
            }
            
            if(arr[j] - arr[i] < k){
                ans += (j - i);
            }
            
            j ++;
        }
        
        return ans;
    }
};