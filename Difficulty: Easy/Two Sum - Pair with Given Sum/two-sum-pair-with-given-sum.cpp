class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        //Sum of Two Elements Gives TArget Element
        //first sort the array
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int i = 0 , j = n - 1;
        
        while(i < j){
            int sum = arr[i] + arr[j];
            
            if(sum == target){
                return true;
            }else if(sum < target){
                i ++;
            }else{
                j --;
            }
        }
        
        return false;
    }
};