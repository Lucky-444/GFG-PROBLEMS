class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int maxHeight=INT_MIN, count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=maxHeight){
                maxHeight=arr[i];
                count++;
            }
        }
        return count;
    }
};