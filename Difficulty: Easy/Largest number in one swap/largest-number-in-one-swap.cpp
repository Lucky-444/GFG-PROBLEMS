class Solution {
  public:
    string largestSwap(string &s) {
        vector<int>last(10, 0);

        
        // Store the last index of each digit
        for(int i = 0 ; i < s.size() ; i++){
            last[s[i] - '0'] = i;            
        }

        for(int i = 0 ; i < s.size() ; i++){
            //now start from 9 to s[i] - 0 + 1 find the greater number
            //which occurs at lastidx
            //means greater than the current index

            for(int d = 9 ; d > s[i] - '0' ; d--){
                //if(last[d] > i) then it is the greater number

                if(last[d] > i){
                    swap(s[i] , s[last[d]]);
                    return s;
                }
            }
        }

        return s;
    }
};