class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& nums) {
        // code here
        int n = nums.size();

        vector<int>ans(n , -1);
        //Next Greater Element
        stack<int>st;

        for(int i = n - 1 ; i >= 0 ; i --){
            // Remove all elements that are <= current,
            // because they cannot be the next greater element.
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            ans[i] = (st.empty() ? -1 : st.top());
            st.push(nums[i]);
        }

        return ans;
    }
};