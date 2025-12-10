class Solution {
  public:
  vector<int> solve(vector<int>& arr) {
        int m = arr.size();
        
        // Solve quadratic: m = n*(n-1)/2
        int n = (1 + sqrt(1 + 8*m)) / 2;

        vector<int> res(n);

        // First three needed pair sums:
        int S01 = arr[0];
        int S02 = arr[1];
        int S12 = arr[n - 1]; // first element of block starting with res[1]

        // compute res[0], res[1], res[2]
        res[0] = (S01 + S02 - S12) / 2;
        res[1] = S01 - res[0];
        res[2] = S02 - res[0];

        // Now fill remaining elements
        int idx = 2;  // arr index for sums with res[0]
        for(int i = 3; i < n; i++) {
            res[i] = arr[idx] - res[0];
            idx++;
        }

        return res;
  }
    vector<int> constructArr(vector<int>& arr) {
        // code here
        return solve(arr);
    }
};