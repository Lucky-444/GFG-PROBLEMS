class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int base = 0;
        map<pair<int , int> , int>mp;

        for(int i = 1 ; i < n ; i ++){
            int x = nums[i - 1];
            int y = nums[i];

            if(x == y){
                base ++;
            }else{
                if(x > y){
                    swap(x , y);
                }

                mp[{x , y}] ++;
            }
        }  

        int ans = 0;

        for(auto [p , val] : mp){
            ans = max(val , ans);
        }

        return base + ans;
    }
};