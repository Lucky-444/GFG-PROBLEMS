class Solution {
  public:
    int minMoves(vector<int>& nums) {
        // code here
        int N = nums.size();
        int maxx=0;
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++)
        {
            mp[nums[i]]+=(mp[nums[i]-1]+1);
            maxx=max(maxx,mp[nums[i]]);
        }
        return N-maxx;
    }
};