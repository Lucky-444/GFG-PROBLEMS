class Solution {
  public:
    using P = pair<int , int>;
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int , int>mp;
        
        for(auto it : arr){
            mp[it] ++ ;
        }
        
        vector<int>ans(n , -1);
        
        stack<P>st;
        
        st.push({mp[arr[n - 1]] , arr[n - 1]});
        
        for(int i = n - 2 ; i >= 0 ; i --){
            while(!st.empty() && st.top().first <= mp[arr[i]]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = st.top().second;
            }
            
            st.push({mp[arr[i]] , arr[i]});
        }
        
        return ans;
    }
};
