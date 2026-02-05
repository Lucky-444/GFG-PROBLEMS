class Solution {
  public:
    vector<int> smallestDiff(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3){ 
        // code here.
        // Sort all three arrays so we can use the two/three pointer technique
// Sorting allows us to move pointers intelligently to minimize max - min
sort(arr1.begin(), arr1.end());
sort(arr2.begin(), arr2.end());
sort(arr3.begin(), arr3.end());

// i, j, k are pointers for arr1, arr2, arr3 respectively
int i = 0, j = 0, k = 0;

// Size of arrays (problem guarantees equal size arrays)
int n = arr1.size();

// bestDiff stores the minimum difference (max - min) found so far
int bestDiff = INT_MAX;

// bestSum stores the minimum sum for the same bestDiff
// This is needed for tie-breaking
int bestSum = INT_MAX;

// This will store the final best triplet
vector<int> bestTriplet;

// Loop continues as long as all pointers are inside their arrays
while (i < n && j < n && k < n) {

    // Take current elements from each array
    int a = arr1[i], b = arr2[j], c = arr3[k];

    // Find the minimum value among the three
    // This tells us which pointer to move next
    int mn = min({a, b, c});

    // Find the maximum value among the three
    // Used to compute the current difference
    int mx = max({a, b, c});

    // Difference between max and min of the triplet
    int diff = mx - mn;

    // Sum of the current triplet
    int sum = a + b + c;

    // Update answer if:
    // 1) We found a smaller difference
    // 2) OR difference is same but sum is smaller (tie-breaker)
    if (diff < bestDiff || (diff == bestDiff && sum < bestSum)) {
        bestDiff = diff;          // store best difference
        bestSum = sum;            // store best sum
        bestTriplet = {a, b, c};  // store current triplet
    }

    // Move the pointer which points to the minimum element
    // WHY?
    // Increasing the minimum value is the ONLY way to possibly reduce (max - min)
    if (mn == a) 
        i++;      // move pointer in arr1
    else if (mn == b) 
        j++;      // move pointer in arr2
    else 
        k++;      // move pointer in arr3
}

// Sort the result in decreasing order as required by the problem
sort(bestTriplet.begin(), bestTriplet.end(), greater<int>());

// Return the final best triplet
return bestTriplet;

    }
};