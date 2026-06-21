class Solution {
  public:
    using ll = long long;
    ll solve(int a , int b){
        ll res = 1;
        
        while(b){
            if(b & 1){
                res = res * a;
            }
            
            a = a * a;
            b >>= 1;
        }
        
        return res;
    }
    int nthRoot(int n, int m) {
        // Code here
        //x ^ n == m
        //Check This Only
        //Think About X is +ve integer
        //Then Process Each X one by One then TC = O(n) * PowerCalculation Time
        if(m == 0) return 0;
        
        int low = 1;
        int high = m;
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            
            int val = solve(mid , n);
            if(val == m){
                return mid;
            }else if(val > m){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return -1;
    }
};