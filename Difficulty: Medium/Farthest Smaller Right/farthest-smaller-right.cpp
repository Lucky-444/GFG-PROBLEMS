class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        //binary search on suffix array
        int n = arr.size();
        vector<int>suffix(arr.size());
        
        suffix[n - 1] = arr[n - 1];
        
        for(int i = n - 2 ; i >= 0 ; i--){
            suffix[i] = min(suffix[i + 1] , arr[i]);
        }
        
        //  now apply binary search on each index 
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++){
            int low = i + 1, high = n - 1, res = -1;
            
            while(low <= high){
                int mid = (low + high) >> 1;
                
                if(suffix[mid] < arr[i]){
                    res = mid;
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
            
            ans[i] = res;
        }
        
        return ans;
    }
};