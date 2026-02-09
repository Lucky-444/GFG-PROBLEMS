class Solution {
  public:
    bool solve(vector<int>&arr ,  int  mid ,int k){
       int ans=0;
        for(int i=0;i<arr.size();i++){
            int cnt=arr[i]/mid;
            if(arr[i]%mid!=0){
                cnt++;
            }
            ans+=cnt;
        }
        return ans <= k;
  }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1 , high = 1e9;
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(solve(arr , mid , k)){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};