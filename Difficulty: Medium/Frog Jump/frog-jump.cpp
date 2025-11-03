class Solution {
  public:
      int frogjump(int n,vector<int>&a){
    vector<int>DP(n+1,-1);
     DP[0]=0;
    int ls,rs;
    for(int i=1;i<n;i++){
         ls=DP[i-1]+abs(a[i]-a[i-1]);
         rs=INT_MAX;
        if(i>1) {
             rs=DP[i-2]+abs(a[i]-a[i-2]);
        }
        DP[i]=min(ls,rs);
        
    }
    return DP[n-1];

  }
    int minCost(vector<int>& arr) {
        int n = arr.size();
      return  frogjump(n,arr);
        // Code here
    }
};