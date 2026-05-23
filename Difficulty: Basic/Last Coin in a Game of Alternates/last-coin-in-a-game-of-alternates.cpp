class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
          int s=0, e=arr.size()-1;
      
      while(s<e){
        if(arr[s] > arr[e]) s++;
        else e--;
      }
      
      return arr[s];
    }
};