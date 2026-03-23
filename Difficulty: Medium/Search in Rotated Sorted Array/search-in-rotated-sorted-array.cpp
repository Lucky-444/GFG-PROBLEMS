class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) >> 1;
            
            if (arr[mid] == key) {
                return mid; // ✅ return index
            }
            
            // Right half sorted
            else if (arr[mid] <= arr[high]) {
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            // Left half sorted
            else {
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        
        return -1;
    }
};