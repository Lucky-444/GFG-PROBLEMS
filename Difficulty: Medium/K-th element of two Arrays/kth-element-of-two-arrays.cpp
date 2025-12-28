class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int low = 1 , high = 1e9 ; 
        int ans = 1;
        
        while(low <= high){
            int mid = (low  + high) >> 1;
            //find out no of smaller elements in both array 
            // count elements <= mid in both arrays
            int cnt = upper_bound(a.begin(), a.end(), mid) - a.begin();
            cnt += upper_bound(b.begin(), b.end(), mid) - b.begin();
            if (cnt >= k) {
                ans = mid;       // possible answer
                high = mid - 1;  // try smaller value
            } else {
                low = mid + 1;   // need bigger value
            }
        }
        return ans;
            
        }
};