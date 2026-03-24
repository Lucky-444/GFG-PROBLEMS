class Solution {
  public:
    using P = pair<double , pair<double , double>>;
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double ans;
        int n = val.size();
        
        vector<P>vec;
        
        for(int i = 0 ; i < val.size() ; i ++){
            double ratio = (double)val[i] / wt[i];
            vec.push_back({ratio , {val[i] , wt[i]}});
        }
        
        sort(vec.rbegin() , vec.rend());
        
        double totalValue = 0;
        int remainingCapacity = capacity;
        
        for(int i = 0; i < n; i++) {
            int itemVal = vec[i].second.first;
            int itemWt = vec[i].second.second;

            if(remainingCapacity >= itemWt) {
                // take full item
                totalValue += itemVal;
                remainingCapacity -= itemWt;
            } else {
                // take fraction of item
                totalValue += vec[i].first * remainingCapacity; // ratio * remaining weight
                break; // knapsack is full
            }
        }

        return totalValue;
    }
};
