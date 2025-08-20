class Solution {
  public:
    vector<int> smallestDifferenceTriplet(vector<int>& arr1, vector<int>& arr2,
                                          vector<int>& arr3) {
        // code here.
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        sort(arr3.begin(), arr3.end());
        
        int i = 0, j = 0, k = 0;
        int n = arr1.size();
        
        int bestDiff = INT_MAX;
        int bestSum = INT_MAX;
        vector<int> bestTriplet;
        
        while (i < n && j < n && k < n) {
            int a = arr1[i], b = arr2[j], c = arr3[k];
            int mn = min({a,b,c});
            int mx = max({a,b,c});
            int diff = mx - mn;
            int sum = a + b + c;
            
            if (diff < bestDiff || (diff == bestDiff && sum < bestSum)) {
                bestDiff = diff;
                bestSum = sum;
                bestTriplet = {a,b,c};
            }
            
            // move pointer of the minimum element
            if (mn == a) i++;
            else if (mn == b) j++;
            else k++;
        }
        
        // print in decreasing order
        sort(bestTriplet.begin(), bestTriplet.end(), greater<int>());
        return bestTriplet;
    }
};