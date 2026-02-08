class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        int ans = 0;
        int mini = INT_MAX;

        while (low <= high) {
            int mid = (low + high) >> 1;

            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                // Check if this sorted part has a smaller element
                if (arr[low] < mini) {
                    mini = arr[low];
                    ans = low;
                }
                // Move to right half
                low = mid + 1;
            }
            // Right half is sorted
            else {
                // Check if mid is smaller
                if (arr[mid] < mini) {
                    mini = arr[mid];
                    ans = mid;
                }
                // Move to left half
                high = mid - 1;
            }
        }

        return ans;
    }
};
