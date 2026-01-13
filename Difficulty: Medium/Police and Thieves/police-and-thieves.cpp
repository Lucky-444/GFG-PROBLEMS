class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int>police, theif;
        
        for(int i = 0; i < arr.size() ; i++){
            if(arr[i] == 'P') police.push_back(i);
            else theif.push_back(i);
        }
        
        int i = 0 , j = 0 , n = arr.size();
        int ans = 0;
        
        while(i < police.size() && j < theif.size()){
            if(abs(police[i] - theif[j]) <= k){
                i++;
                j++;
                ans++;
            }
             else if (theif[j] < police[i]) {
                j++;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};