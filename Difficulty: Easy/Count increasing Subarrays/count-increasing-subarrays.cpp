class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
         int prev = 0;
        int n = arr.size();
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(arr[i] <= arr[i - 1]){  // FIXED condition
                int len = i - prev;
                ans += (len * (len - 1)) / 2;
                prev = i;
            }
        }

        if(prev != n - 1){
            int len = n - prev;
            ans += (len * (len - 1)) / 2;
        }

        return ans;
    }
};

