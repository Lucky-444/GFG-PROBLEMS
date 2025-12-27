using ll = long long ;
class fenwickTree{
    int n ; 
    vector<ll>bit; 
    
    public : 
    fenwickTree(int n){
        this -> n = n ; 
        bit.assign(n + 1 , 0);
        
    }
    
    void Update(int idx ,int val){
        while(idx <= n){
            bit[idx] += val; 
            idx += idx & -idx; 
        }
    }
    
    int Query(int idx){
        ll sum = 0 ;
        
        while(idx > 0){
            sum += bit[idx]; 
            idx -= idx & -idx; 
        }
        
        return sum ; 
    }
};


class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size(); 
        fenwickTree* ft = new fenwickTree(1e4);
        
        ll ans = 0 ;
        
        //start traverse from last 
        for(int i = n - 1 ; i >= 0 ; i --){
            ans += ft -> Query(arr[i] - 1);
            
            ft -> Update(arr[i] , 1);
        }
        
        return ans ;
    }
};