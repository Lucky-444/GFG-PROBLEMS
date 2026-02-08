class Solution {
  public:
    using ll = long long int ;
    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) {
        ll ans = INT_MIN ;
        
        //First calculate maxSum at each index i 
        //maxSum[i] = [0....i] what is the max SUm
        
        vector<ll>maxSum(n , 0);
        maxSum[0] = a[0];
        ll currSum = a[0];
        for(int i = 1 ; i < n ; i ++){
            if(currSum > 0){
                currSum += a[i];
            }else{
                currSum = a[i];
            }
            
            maxSum[i] = currSum;
        }
        
        // Calculate sum of the first k elements
        ll exactK = 0;
        for (int i = 0; i < k; i++) {
            exactK += a[i];
        }
        
        ans = max(ans,  exactK);
        
        for(int i = k ; i < n ; i ++){
            exactK += a[i];
            exactK -= a[i - k];
            
            ans = max(ans , exactK);
            
            ll addPrevSum = maxSum[i - k] + exactK; 
            
            ans = max(ans , addPrevSum);
        }
        
        return ans;
        
        
        
    }
};