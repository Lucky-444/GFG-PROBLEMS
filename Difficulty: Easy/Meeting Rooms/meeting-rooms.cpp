class Solution {
  public:
     static  bool cmp (vector<int>&v1 ,vector<int>&v2){
       if(v1[0]!=v2[0]) return v1[0]<v2[0];
       return v1[1]<v2[1];
   }
     bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        
        sort(arr.begin(),arr.end(),cmp);
        
        for(int i=1;i<arr.size();i++){
            if(arr[i-1][1] > arr[i][0]) return false;
        }
        return true;
    }
};