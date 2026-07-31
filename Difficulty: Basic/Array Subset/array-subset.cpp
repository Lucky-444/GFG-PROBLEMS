class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        multiset<int>ms(a.begin() , a.end());
        
        for(auto it : b){
           if(ms.find(it) == ms.end()){
               return false;
           }
           
           ms.erase(ms.find(it)); //same Number Occur Multiple Times so
        }
        
        return  true;
        
    }
};