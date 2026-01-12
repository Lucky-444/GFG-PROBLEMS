class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int cnt_5 = 0, cnt_10 = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 5){
                cnt_5++; 
            }
            else if(arr[i] == 10){
                // need one 5 as change
                if(cnt_5 == 0) return false;
                cnt_10++;
                cnt_5--;
            }
            else if(arr[i] == 20){
                // prefer giving 10 + 5
                if(cnt_10 > 0 && cnt_5 > 0){
                    cnt_10--;
                    cnt_5--;
                }
                // otherwise give 3 fives
                else if(cnt_5 >= 3){
                    cnt_5 -= 3;
                }
                else{
                    return false;
                }
            }
        }
        
        return true;
    }
};
