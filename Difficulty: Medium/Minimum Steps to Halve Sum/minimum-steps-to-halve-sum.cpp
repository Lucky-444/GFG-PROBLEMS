class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double>pq;
        
        double sum = 0.0;
        
        for(auto it : arr){
            pq.push(it);
            sum += it;
        }
        
        //target = sum / 2.0
        double target = sum / 2.0;
        double currSum = 0.0;
        int operations = 0;
        
        while(!pq.empty() && currSum < target){
            double top = pq.top();
            pq.pop();

            double half = top / 2.0;
            currSum += half;
            pq.push(half);
            operations++;
        }
        
        return operations ;
    }
};