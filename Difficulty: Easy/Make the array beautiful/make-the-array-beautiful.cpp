class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> st;

        for (auto x : arr) {

            // Different signs -> remove pair
            if (!st.empty() &&
               ((st.top() >= 0 && x < 0) ||
                (st.top() < 0 && x >= 0))) {

                st.pop();
            }
            else {
                st.push(x);
            }
        }

        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};