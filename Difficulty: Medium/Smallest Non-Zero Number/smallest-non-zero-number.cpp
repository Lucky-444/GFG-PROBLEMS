class Solution {
public:
    bool check(long long x, vector<int>& arr) {
        __int128 cur = x;

        for (int a : arr) {
            cur = 2 * cur - a;
            if (cur < 0)
                return false;
        }

        return true;
    }

    long long find(vector<int>& arr) {
      int x=0;
      for(int i=arr.size()-1; i>=0; i--){
        x = (x+arr[i]+1)/2;  
      }
      
      return (x==0)? 1: x;
    }
};