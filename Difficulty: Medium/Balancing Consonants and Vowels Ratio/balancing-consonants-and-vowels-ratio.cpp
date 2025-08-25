class Solution {
  public:
    //it stores vowel and consonant count of each string inside the array
      bool isVowel(char ch) {

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';

    }
    vector<int>vec;
    void solve(vector<string>&arr){
        for(auto it : arr){
            int v = 0 , c = 0;
            for(auto ch  : it){
                if (isVowel(ch)){
                    v++;
                }else{
                    c++;
                }
            }
            vec.push_back(v - c);
        }
    }
    int countBalanced(vector<string>& arr) {
        // code here
        //precompute vowels cnt and consonant count of each string in tthe string vector
        solve(arr);
        
        //
        int ans = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        
        int sum = 0;
        for(int i = 0; i < vec.size(); i++){
            sum += vec[i];
            
            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            
            mp[sum]++;
        }
        
        return ans;
        
    }
};