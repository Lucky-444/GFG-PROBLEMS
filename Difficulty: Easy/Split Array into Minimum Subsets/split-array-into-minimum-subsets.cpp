class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin() , arr.end());
        
        int cnt = 0;
        
        int i = 0;
        int n = arr.size();
        
        while(i < n){
            int j = i + 1;
            cnt ++;
            
            while(j < n && arr[j] - arr[j - 1] == 1){
                j ++;
            }
            
            i = j;
        }
        
        return cnt;
    }
};
