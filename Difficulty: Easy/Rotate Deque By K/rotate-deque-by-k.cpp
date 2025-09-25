class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(dq.empty()){
            return;
        }
        k %= dq.size();
        int i=0;
        while(i<k){
            if(type==2){
                int a=dq.front();
                dq.pop_front();
                dq.push_back(a);
            }
            else{
                int a=dq.back();
                dq.pop_back();
                dq.push_front(a);
            }
            i++;
        }
    }
};