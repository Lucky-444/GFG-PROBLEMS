class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        
        sort(arr , arr + n); 
        
        long long ans = 0;
        
        for(int i = 0 ; i < n - 2 ; i ++){
            int j = i + 1 ;
            int k = n - 1 ;
            
            while(j < k){
                long long NewSum = arr[i] + arr[j] + arr[k] ;
                
                if(NewSum < sum){
                    ans += (k - j) ; 
                    j ++;
                    
                }else{
                    k -- ; 
                }
            }
        }
        
        return ans;
    }
};