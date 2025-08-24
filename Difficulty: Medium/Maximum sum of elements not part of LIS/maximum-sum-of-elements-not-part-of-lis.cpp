class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>length(n , 1);
        vector<int>sum(n , 0);
        
        
        for(int i = 0 ; i < n ; i++){
            sum[i] = arr[i];
        }
        
        
        int maxLen = 1;
        int minLisSum = arr[0];
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[i] > arr[j]){
                    if(length[j] + 1 > length[i]){
                        length[i] = length[j] + 1;
                        sum[i] = sum[j] + arr[i];
                    }else if(length[j] + 1 == length[i]){
                        sum[i]  = min(sum[i] , sum[j] + arr[i]);
                    }
                }
            }
            
            if(length[i] > maxLen){
                maxLen = length[i];
                minLisSum = sum[i];
            }
            else if(length[i] == maxLen){
                minLisSum = min(minLisSum , sum[i]);
            }
        }
        
        int totalSum = 0;
        
        for(auto it : arr){
            totalSum += it;
        }
        
        
        return totalSum - minLisSum;
    }
};