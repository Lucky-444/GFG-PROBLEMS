class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
         // Code here
        vector<int>ans;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1 ;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]<arr[j] && arr[j]< arr[k]){
                        ans.push_back(arr[i]);
                        ans.push_back(arr[j]);
                        ans.push_back(arr[k]);
                         return ans;
                    }
                }
            }
            
        }
        return ans;
    }
};