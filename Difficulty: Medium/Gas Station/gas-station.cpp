class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int sumGas = accumulate(gas.begin() , gas.end() , 0);
        int sumCost = accumulate(cost.begin() , cost.end() , 0);

        if(sumGas < sumCost){
            return -1;
        }

        int ans = 0, res = 0;
        for(int i = 0 ; i < gas.size() ; i++){
            ans = ans + (gas[i] - cost[i]);
            
            if(ans < 0){
                ans = 0;
                res = i + 1; 
            }
        }
        
        return res ;
    }
};