class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        // using(set)
        
        int n = arr.size(); 
        int maxi = *max_element(arr.begin() , arr.end());
        
        unordered_set<int>st(arr.begin() , arr.end()) ; 
        
        for(int i = 1 ; i < maxi ; i ++){
            if(st.count(i)){
                continue ; 
            }else{
                k -- ;
            }
            
            if(k == 0){
                return i ;
            }
        }
        
        return maxi + k ; 
    }
};