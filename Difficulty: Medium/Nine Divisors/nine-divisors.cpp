class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        using ll = long long;
        int count = 0;
        ll  limit = (long long)(sqrt(n)) + 1;
        vector<long long >seive(limit + 1 , true);
        vector<long long >primes;
        
        seive[0] = seive[1] = false;
        
        for(int i = 2; i <= limit ; i++){
            if(seive[i]){
                primes.push_back(i);
                for(ll j = i * i ; j <= limit ; j += i){
                    seive[j] = false;
                }
            }
        }
        
        //case 1-> 
        //number is in the form of P^8;
        
        for(auto it : primes){
            ll val = it * it * it * it * it * it * it * it;
            if(val <= n){
                count++;
                
            }else{
                
                break;
            }
        }
        
        //case 2->
        //number is in tthe form of P^2 * Q^2
        
        for(int i = 0 ; i < primes.size();  i++){
            for(int j = i + 1; j < primes.size() ; j++){
                ll val = (primes[i] * primes[i]) * (primes[j] * primes[j]) ;
                if(val <= n){
                    count++;
                }else{
                    break;
                }
            }
        }
        
        return count;
    }
};