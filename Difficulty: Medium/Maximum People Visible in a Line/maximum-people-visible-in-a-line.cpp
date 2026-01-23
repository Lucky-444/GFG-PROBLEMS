class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n = arr.size();
    vector<int> pge(n), nge(n);
    stack<int> st;

    // Previous Greater or Equal
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next Greater or Equal
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int visible = (i - pge[i] - 1) + (nge[i] - i - 1) + 1;
        ans = max(ans, visible);
    }

    return ans;
    }
};