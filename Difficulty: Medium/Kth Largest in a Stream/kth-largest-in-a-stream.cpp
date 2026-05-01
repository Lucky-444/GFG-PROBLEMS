class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        multiset<int> ms;   // will store k largest elements
        vector<int> ans;

        for(int x : arr){
            ms.insert(x);

            // keep only k largest elements
            if(ms.size() > k){
                ms.erase(ms.begin()); // remove smallest
            }

            // if we don't have k elements yet
            if(ms.size() < k){
                ans.push_back(-1);
            } else {
                ans.push_back(*ms.begin()); // kth largest
            }
        }

        return ans;
    }
};