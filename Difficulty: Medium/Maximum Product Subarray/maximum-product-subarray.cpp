class Solution {
public:
    int maxProduct(vector<int>& arr) {

        // Initialize max product, min product, and final result
        // using the first element of the array
        int maxProd = arr[0];
        int minProd = arr[0];
        int result  = arr[0];

        // Traverse the array from the second element
        for (int i = 1; i < arr.size(); i++) {

            // Store previous maxProd because
            // maxProd will be updated before minProd
            int prevMax = maxProd;

            /*
             Three possibilities for max product ending at index i:
             1. Start a new subarray from arr[i]
             2. Extend previous max product subarray
             3. Extend previous min product subarray
                (important when arr[i] is negative)
            */
            maxProd = max(
                arr[i],
                max(arr[i] * maxProd, arr[i] * minProd)
            );

            /*
             Three possibilities for min product ending at index i:
             1. Start a new subarray from arr[i]
             2. Extend previous max product subarray
             3. Extend previous min product subarray
            */
            minProd = min(
                arr[i],
                min(arr[i] * prevMax, arr[i] * minProd)
            );

            // Update the overall maximum product found so far
            result = max(result, maxProd);
        }

        return result;
    }
};
