class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int operations = 0;
        int n = arr.size();
        
        while(true){
            //Check all are Zero Or Not
            // Check whether every element has become 0
            bool allZero = true;

            for (int i = 0; i < n; i++) {
                if (arr[i] != 0) {
                    allZero = false;
                    break;
                }
            }
            
            if (allZero)
                break;

            // -------------------------------
            // Step 1 : Remove all odd numbers
            // Every odd number must have come
            // from an Increment operation.
            // -------------------------------
            bool hasOdd = false;

            for (int i = 0; i < n; i++) {
                if (arr[i] & 1) {
                    arr[i]--;
                    operations++;
                    hasOdd = true;
                }
            }

            // If we removed odd numbers,
            // continue to next iteration.
            if (hasOdd)
                continue;

            // -------------------------------
            // Step 2 : If every element is even,
            // reverse one Double operation.
            // -------------------------------
            for (int i = 0; i < n; i++) {
                arr[i] /= 2;
            }

            operations++;
        }
        return operations;
    }
};