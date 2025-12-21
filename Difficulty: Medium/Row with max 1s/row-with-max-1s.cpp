// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        vector<int>ones(n,0);
        
        for(int i = 0;i < n;i++){
            for(int j=0;j<m;j++){
                ones[i] += arr[i][j];
             }
        }
        
        int idx = -1;
        int maxVal  = INT_MIN;
        for(int i = 0; i <n;i++){
           if(ones[i] > maxVal){
               maxVal = ones[i];
               idx = i;
           }
        }
        
        return idx ;
    }
};