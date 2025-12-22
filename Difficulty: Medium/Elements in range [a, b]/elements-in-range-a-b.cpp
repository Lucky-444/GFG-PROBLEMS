class Solution {
  public:
   int countGrt(vector<int>&arr,int l){
        int n= arr.size();
        int low = 0;
        int high = n-1;
        int mid = (low+high)/2;
        int ans = n-1;
        if(arr[n-1]<l)return 0;
        while(low<=high){
            mid = (low+ high)/2;
            if(arr[mid]>=l){
                ans= min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return n-ans;
    }
    int countLess(vector<int>&arr,int h){
        int n= arr.size();
        int low = 0;
        int high = n-1;
        int mid = (low+high)/2;
        int ans = 0;
        if(arr[0]>h)return 0;
        while(low<=high){
            mid = (low+ high)/2;
            if(arr[mid]<=h){
                ans= max(ans,mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans+1;
    }
    int countBtw(vector<int>&arr,int l,int h){
        int n= arr.size();
        return countGrt(arr,l) + countLess(arr,h) - n ;
    }
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        int n= arr.size();
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(countBtw(arr,queries[i][0],queries[i][1]));
        }
        return ans;
    }
};