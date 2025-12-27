class Solution {
  public:
    bool CanPossible(int mid , auto &vec , int k){
        int cnt = 0 ;
        
        for(int i = 0 ; i < vec.size() ; i ++){
            int t = vec[i]; 
            int mul = 2 ; 
            while(t <= mid){
                t += vec[i] * mul ;
                cnt ++ ; 
                mul ++ ; 
            }
            
            if(cnt >= k){
                return  true;
            }
        }
        
        return cnt >= k ;
    }
    int minTime(vector<int>& ranks, int n) {
        // code here
        //binary search on answer
        
        int low = 0 , high = 1e9 ; 
        
        int ans = 0; 
        
        while(low <= high){
            int mid = (low + high) >> 1; 
            
            if(CanPossible(mid , ranks , n)){
                ans = mid ; 
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans; 
    }
};