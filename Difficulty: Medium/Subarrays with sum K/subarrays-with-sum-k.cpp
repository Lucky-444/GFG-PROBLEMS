class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
       map<int, int> mp;
       mp[0]=1;
       int count=0;
       int prefixSum=0;
       for (int i=0; i< arr.size(); i++){
           prefixSum+= arr[i];
           if(mp.count(prefixSum-k)){
               count+= mp[prefixSum-k];
           }
           mp[prefixSum]++;
       }
       return count; 
    }
};