class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int cnt=0;
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              
                if(arr[j]>arr[j-1]){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};

