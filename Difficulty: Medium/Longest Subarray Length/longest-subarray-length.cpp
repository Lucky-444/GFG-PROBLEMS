class Solution {
  public:
    //using Previous Greater Element (PGE) and Next Greater Element (NGE) with a stack.
    int longestSubarray(vector<int>& arr) {
   int n = arr.size();
        vector<int> prev(n, -1), next(n, n);
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) prev[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (!st.empty()) next[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int len = next[i] - prev[i] - 1;
            if (arr[i] <= len) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};