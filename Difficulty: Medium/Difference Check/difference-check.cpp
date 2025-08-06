class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        vector<int>timer;
        
        for(auto s : arr){
            
            string hr = s.substr(0 , 2);
            string mn = s.substr(3 , 2);
            string sec = s.substr(6 , 2);
            
            int hours = stoi(hr);
            int mns = stoi(mn);
            int second = stoi(sec);
            //convert all to seconds 
            int total = hours * 3600 + mns * 60 + second ;
            
            timer.push_back(total);
        }
        
        sort(timer.begin() , timer.end());
        
        int minDiff = INT_MAX;
        
        for(int i = 1 ; i < timer.size() ; i ++){
            int diff = timer[i] - timer[i - 1];
            minDiff = min(minDiff , diff);
        }
            
        //check wrapAround Times
        int n = timer.size();
        int diff = timer[n - 1] - timer[0];
        // Wrap-around difference (from last to first, through midnight)
        int wrapDiff = 24 * 3600 - diff;
        minDiff = min(minDiff , wrapDiff);
        
        return minDiff;
    }
};
