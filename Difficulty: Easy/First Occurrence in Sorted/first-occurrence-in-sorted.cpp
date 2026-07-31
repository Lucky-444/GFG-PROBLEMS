class Solution {
  public:
    int solve(vector<int>&arr , int k){
        int low = 0 , high = arr.size() - 1;
        
        int ans = -1;
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(arr[mid] == k){
                ans = mid;
                high = mid - 1;
            }else if(arr[mid] < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
    int firstSearch(vector<int> &arr, int k) {
        // code here
        return solve(arr  ,k);
    }
};