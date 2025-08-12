class Solution {
  public:
    int minimum(int n , int k){
        if(n % k == 0){
            return  0;
        }
        
        return (k - (n % k)); // soldiers to add 
    } 
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = (arr.size() + 1) / 2; //ceil value
        sort(arr.begin() , arr.end());
        
        int cnt = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] % k == 0){
                cnt ++;
            }
        }
        
        if(cnt >= n){
            return 0;
        }
        
        int req = n - cnt; 
        int minm = INT_MAX;
        vector<int>vec;
        for(int i = 0; i < arr.size() ; i++){
            if(arr[i] % k != 0){
                 int miniReq = minimum(arr[i] , k);
                 vec.push_back(miniReq);
            }
        }
        
        sort(vec.begin() , vec.end());
        
        int total = 0;
        for (int i = 0; i < req; i++) {
            total += vec[i];
        }
        return total;
    }
};