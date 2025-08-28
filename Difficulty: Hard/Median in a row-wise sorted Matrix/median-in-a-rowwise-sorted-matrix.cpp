class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        // using priority_queue<method>> pq;
        //min heap
        int n = mat.size();
        int m = mat[0].size();
        
        
        
        using T = vector<int>;
        priority_queue<T , vector<T> , greater<>>pq; //{val , row ,col}
        
        int medianIndex = (n * m) / 2; 
        
        //first push all first elements into the pq
        
        for(int i = 0 ; i < n ; i++){
            pq.push({mat[i][0] , i , 0});
        }
        
        int cnt = 0;
        //now iterate on pq and apply the method
        int res = -1;
        while(cnt <= medianIndex){
            auto top = pq.top();
            pq.pop();
            
            int val = top[0] , r = top[1] , c = top[2] ;
            res = val ;
            
            cnt ++;
            // if more elements are left in the current
            // row, push next
            if(c + 1 < m){
                pq.push({mat[r][c + 1] , r  , c + 1});
            }
            
            
            
        }
        
        return res;
    }
};
