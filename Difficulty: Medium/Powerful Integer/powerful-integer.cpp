class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        //sweepLine algorithm
        /**
         -------------------------
         1    3    4   6 
         ------
              ------
                   ------
                   
        
        maxi = max(maxi , 3,4) which has count >= k
        */
        
        map<int , int>mp;
        for(auto x : intervals){
            mp[x[0]]++;
            mp[x[1] + 1]--;
        }
 
          int cnt = 0 , ans = -1 ;
                for(auto &x : mp){
                    if(cnt >= k){
                        ans = max(ans , x.first - 1) ;
                    }
                    cnt += x.second ;
                }
                return ans ;
    }
};