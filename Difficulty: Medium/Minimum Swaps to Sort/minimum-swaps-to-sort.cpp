class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        vector<pair<int , int>>vec;
        for(int i = 0 ; i < arr.size() ; i++){
            vec.push_back({arr[i] , i});
        }
        
        sort(vec.begin() , vec.end());
        int cnt = 0;
        for(int i = 0 ; i < vec.size() ;){
            if(vec[i].second == i){
                i++;
                continue ; 
            }
            
            else{
                swap(vec[i] , vec[vec[i].second]);
                cnt ++;
            }
        }
        
        return cnt;
    }
};