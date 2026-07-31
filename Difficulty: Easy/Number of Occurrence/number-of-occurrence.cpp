class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
        int first = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        int last = upper_bound(nums.begin() , nums.end() , target) - nums.begin() - 1;

        // check if first and last index are valid or not
        if (first < nums.size() and nums[first] == target) {
            return last - first + 1;
        }

        return 0;
    }
};
