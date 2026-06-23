class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int i = 1;
        int cnt = 0 ;
        while((p >= (i * i))){
            
            cnt ++;
            p -= (i * i);
            i ++;
        }
        
        return cnt;
    }
};
