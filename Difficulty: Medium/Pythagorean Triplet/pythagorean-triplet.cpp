class Solution {
  public:
        bool pythagoreanTriplet(vector<int>& arr) {
            int n = arr.size();
            unordered_set<int> squares;
            
            // Store all squares in a set
            for (int i = 0; i < n; i++) {
                squares.insert(arr[i] * arr[i]);
            }
        
            // Check all pairs
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int sum = arr[i]*arr[i] + arr[j]*arr[j];
                    if (squares.find(sum) != squares.end())
                        return true;
                }
            }
        
            return false;
        }

};