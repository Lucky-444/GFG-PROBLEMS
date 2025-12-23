class Solution {
    public int countLessEqual(int[] arr, int x) {
        // code here
        // Step 1: Sort the array
        Arrays.sort(arr);

        // Step 2: Binary search for first element > x
        int low = 0, high = arr.length - 1;
        int ans = arr.length;   // default position if all <= x

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // ans is the count of elements <= x
        return ans;        
    }
}
