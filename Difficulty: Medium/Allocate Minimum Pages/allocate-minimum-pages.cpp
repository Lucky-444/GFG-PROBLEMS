class Solution {
  public:
    int check(auto &arr ,int mid , int k){
        int students = 1;   // start with 1 student
        int sum = 0;

        for (int pages : arr) {
            if (pages > mid) return false; // cannot allocate, too big

            if (sum + pages > mid) {
                // allocate to next student
                students++;
                sum = pages;
            } else {
                sum += pages;
            }
        }
        return students <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if (k > arr.size()) return -1 ;//impossiible to give books to the students
        int ans = -1;
        
        int low = *max_element(arr.begin() , arr.end());
        int high = accumulate(arr.begin() , arr.end()  ,0) ;
        
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(check(arr , mid , k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};