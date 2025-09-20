class Solution {
  public:
  int maxarea(vector<int>&histo){
    int n=histo.size();
    stack<int>st;
    int maxa=0;
    for(int i=0;i<=n;i++){
    while(!st.empty() && (i== histo.size() || histo[st.top()]>histo[i])){
        int height=histo[st.top()];
        st.pop();
        int width=st.empty() ? i : i - st.top() - 1;
       
        maxa=max(maxa,width*height);
    }
    st.push(i);
    }
    return maxa;
  }
    int maximalRectangle(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m=matrix[0].size();
     // int n=matrix.size();

      int ans=0;
      vector<int>height(m,0) ;
     for(auto &row:matrix){
        for(int i=0;i<row.size();++i)
            height[i]=(row[i]==0 ? 0:height[i]+1);
            ans=max(ans,maxarea(height));
        
     }
      return ans; 
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        return maximalRectangle(mat);
    }
};