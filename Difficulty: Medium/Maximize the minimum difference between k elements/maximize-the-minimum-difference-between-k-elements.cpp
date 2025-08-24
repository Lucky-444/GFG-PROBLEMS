class Solution {
  public:
    int check(auto &arr , int mid  , int k){
        int last = arr[0];
        
        int cnt = 1;
        
        for(int i = 1; i < arr.size() ; i++){
            if(arr[i] - last >= mid){
                cnt ++;
                last = arr[i];
            }
        }
        
        return cnt >= k;
    }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        sort(arr.begin() , arr.end());
        int ans = 0;
        int low = 1 ; 
        int high = 1e9;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(check(arr , mid , k)){
                ans = mid; 
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
