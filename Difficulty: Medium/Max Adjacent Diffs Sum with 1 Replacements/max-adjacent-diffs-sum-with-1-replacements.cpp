class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0 ; i < n - 1 ; i ++){
            int diff = abs(arr[i] - arr[i + 1]);
            sum += diff;
        }
        
        int maxSum = sum;
        
        //Type of Kadane Algorithm
        int keep = 0 , replace = 0;
        
        for(int i = 1 ; i < n ; i ++){
            int newKeep = max(keep + abs(arr[i] - arr[i - 1]) , 
                            replace + abs(arr[i] - 1)
                            );
                
            //Current Value ko replace Karna Hai
            int newReplace = max(keep + (arr[i - 1] - 1) , replace);
            
            keep = newKeep;
            replace = newReplace;
            
        }
        
        return max(keep  , replace);
    }
};