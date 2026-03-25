// User function Template for C++
//Back-end complete function Template for C++

class Solution {
  public:
    using ll = long long;
    long long solve(vector<int>& bt) {
        // code here
        ll n = bt.size();
        sort(bt.begin() , bt.end());
        
        vector<ll>prefix(n + 1 , 0);
        
        for(int i = 1 ; i <= n ;i ++){
            prefix[i] = prefix[i - 1] + bt[i - 1];
        }
        
        ll total = 0;
        
        for(auto it : prefix){
            total += it;
        }
        
        total -= prefix[n];
        
        return total / n;
        
    }
    
    
};