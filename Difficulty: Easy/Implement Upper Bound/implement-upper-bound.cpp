class Solution {
  public:
    int upperBound(vector<int>& arr, int x) {
        // code here
        int low = 0 , high = arr.size() - 1;
        int ans = arr.size();
        
        while (low <= high) {
            int mid = (low + high) >> 1;

            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;   // go left
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
