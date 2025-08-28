class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        //first find the minimum value and its index
        //the index is the kth rotation value
        
        int minimum = *min_element(arr.begin() , arr.end());
        
        for(int i = 0; i < arr.size() ; i++){
            if(arr[i] == minimum){
                return i;
            }
        }
        
        return 0;
    }
};
