class Solution {
  public:
    bool check(auto &arr ,int k , int m , int mid){
        int cnt = 0;
        int bkt = 0;
        for(auto blooms : arr){
            if(blooms <= mid){
                cnt ++;
                //we have to take consecutive k 
                if(cnt == k){
                   bkt++; //collect one bouquets
                   cnt = 0; //reset the cnt = 0
                   //for further bouquets
                }
            }else{
                cnt = 0; //becoz we need only consecutive bkts
            }
        }
        
        return bkt >= m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // Code here
        int low = 1;
        int high = 1e9 ;
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(check(arr , k , m , mid)){
                ans = mid ;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans ;
    }
};