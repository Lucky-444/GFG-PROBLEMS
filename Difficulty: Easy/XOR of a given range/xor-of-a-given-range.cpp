class Solution {
  public:
    int getXor(vector<int>& nums, int a, int b) {
        // Code here
        int n = nums.size();
        vector<int>prefix(n , 0);
        
        prefix[0] = nums[0];
        for(int i = 1; i < n ; i ++){
            prefix[i] = prefix[i - 1] ^ nums[i];
        }
        
        return a == 0 ? prefix[b] : prefix[b] ^ prefix[a - 1];
    }
};