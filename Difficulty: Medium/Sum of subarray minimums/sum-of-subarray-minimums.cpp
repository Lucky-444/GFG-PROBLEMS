class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        // Arrays to store the count of subarrays where arr[i] is minimum
        vector<long long> left(n), right(n);
        
        // Stack to maintain indices in increasing order of their values
        stack<int> st;
        
        // Calculate left[i]: number of elements to the left where arr[i] is minimum
        for (int i = 0; i < n; i++) {
            // Pop elements that are greater than or equal to current element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            // If stack is empty, arr[i] is minimum for all elements to its left
            // Otherwise, arr[i] is minimum from the element after st.top() to i
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        
        // Clear stack for right calculation
        while (!st.empty()) st.pop();
        
        // Calculate right[i]: number of elements to the right where arr[i] is minimum
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements that are greater than current element
            // Note: We use > (not >=) to handle duplicates correctly
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            
            // If stack is empty, arr[i] is minimum for all elements to its right
            // Otherwise, arr[i] is minimum from i to the element before st.top()
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        
        // Calculate the final answer
        long long result = 0;
        for (int i = 0; i < n; i++) {
            // Contribution of arr[i] = arr[i] × left[i] × right[i]
            long long contribution = (1LL * arr[i] * left[i] % MOD * right[i]) % MOD;
            result = (result + contribution) % MOD;
        }
        
        return result;
    }
};