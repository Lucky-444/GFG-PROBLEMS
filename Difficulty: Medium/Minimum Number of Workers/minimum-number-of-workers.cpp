class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<pair<int, int>>vec;
        
        for(int i = 0 ; i < arr.size(); i ++){
            int L = max(0 , i - arr[i]);
            int R = min(n - 1 , i + arr[i]);
            
            vec.push_back({L , R});
        }
        
        sort(vec.begin(), vec.end());
        
        //Greedily Findout the Next end 
        int currEnd = -1;
        int nextEnd = -1;
        int count = 0 ;
        int i = 0;
        
        while(currEnd < n - 1){
            nextEnd = currEnd;
            // Choose interval starting before or at currEnd + 1
            while(i < vec.size() && vec[i].first <= currEnd + 1){
                nextEnd = max(nextEnd, vec[i].second);
                i++;
            }
            
              // If coverage can't be extended
            if (nextEnd == currEnd) return -1;
    
            count++;
            currEnd = nextEnd;
        }
        
        return count; 
    }
};