class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        //by using priority_queue
        sort(arr.begin() , arr.end());
        int n = arr.size();
        //we only concern about the right half of the array
        int mid = n / 2;
        
        priority_queue<int ,vector<int>, greater<>>pq;
        
        if(n % 2 == 0){
            pq.push(arr[mid - 1]);
        }
        
        for(int i = mid  ; i < n ; i++){
            pq.push(arr[i]);
        }
        
        for(int i = 0; i < k ; i++){
            int val = pq.top();
            pq.pop();
            pq.push(val + 1);
        }
        
        if(n % 2 == 0){
            int val = pq.top();
            pq.pop();
            val += pq.top();
            
            return val / 2;
        }
        
        return pq.top();
        
    }
};