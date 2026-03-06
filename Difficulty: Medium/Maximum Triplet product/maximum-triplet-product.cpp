// User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long nums[], int n) {
        // Complete the function
        
        sort(nums , nums + n);
        long long maxi=nums[n-1]*nums[n-2]*nums[n-3];
        long long maxo=nums[0]*nums[1]*nums[n-1];

        return max(maxi,maxo);
    }
};