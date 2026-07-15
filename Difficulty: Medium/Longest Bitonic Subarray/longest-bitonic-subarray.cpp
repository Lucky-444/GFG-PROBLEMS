class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int>prefix(n) , suffix(n);
        
        prefix[0] = 1;
        
        for(int i = 1 ; i < n ; i ++){
            if(arr[i] >= arr[i - 1]){
                prefix[i] = prefix[i - 1] + 1;
            }else{
                prefix[i] = 1;
            }
        }
        
        suffix[n - 1] = 1;
        for(int i = n - 2 ; i >= 0 ; i --){
            if(arr[i] >= arr[i + 1]){
                suffix[i] = suffix[i + 1] + 1;
            }else{
                suffix[i] = 1;
            }
        }
        
        //Now 
        int ans = ;
        for(int i = 0 ; i < n ; i ++){
            int x = prefix[i] + suffix[i] - 1;
            ans = max(ans , x);
        }
        
        return ans;
    }
};