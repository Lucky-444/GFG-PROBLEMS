class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int>ans(n,1);
        stack<int>s;
        
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] <= arr[i])
            {
                ans[i] += ans[s.top()];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};