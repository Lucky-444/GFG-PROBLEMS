class Solution {
  public:
 vector<int> NSE(vector<int>&arr)
    {
        stack<int>st;
        vector<int>nse(arr.size(),arr.size());
    for(int i=0;i<arr.size();i++){
        
        while(!st.empty() && arr[i] < arr[st.top()])
      {
        nse[st.top()]=i;
        st.pop();
      }
      st.push(i);
    
    }
    
    return nse;
    }
    
    vector<int> PSE(vector<int>&arr)
    {
        stack<int>st;
        vector<int>pse(arr.size(),-1);
    for(int i=arr.size()-1;i>=0;i--){
        
        while(!st.empty() && arr[i] <= arr[st.top()])
      {
        pse[st.top()]=i;
        st.pop();
      }
      st.push(i);
    
    }
    
    return pse;
    }
    long long sumSubarrayMins(vector<int> &arr) {
        int n= arr.size();
        long long s=0;
        vector<int>nse,pse;
        nse=NSE(arr);
        pse=PSE(arr);
        
        for(int i=0;i<n;i++)
        {
            int left=pse[i];
            int right=nse[i];
            long long temp=(long long)(i-left)*(right-i);
            s=s+(arr[i] * temp);
        }
        return s;
    }
    
    // FOR THE MAXIMUMS 
         vector<int> NGE(vector<int>&arr)
    {
        stack<int>st;
        vector<int>nse(arr.size(),arr.size());
    for(int i=0;i<arr.size();i++){
        
        while(!st.empty() && arr[i] > arr[st.top()])
      {
        nse[st.top()]=i;
        st.pop();
      }
      st.push(i);
    
    }
    
    return nse;
    }
    
    vector<int> PGE(vector<int>&arr)
    {
        stack<int>st;
        vector<int>pse(arr.size(),-1);
    for(int i=arr.size()-1;i>=0;i--){
        
        while(!st.empty() && arr[i] >= arr[st.top()])
      {
        pse[st.top()]=i;
        st.pop();
      }
      st.push(i);
    
    }
    
    return pse;
    }
    long long sumSubarrayMax(vector<int> &arr) {
        int n= arr.size();
        long long s=0;
        vector<int>nge,pge;
        nge=NGE(arr);
        pge=PGE(arr);
        
        for(int i=0;i<n;i++)
        {
            int left=pge[i];
            int right=nge[i];
            long long temp=(long long)(i-left)*(right-i);
           s=s+(arr[i] * temp);
        }
        return s;
    }
    long long subarrayRanges(vector<int> &arr) {
        return sumSubarrayMax(arr) - sumSubarrayMins(arr);
    }
};