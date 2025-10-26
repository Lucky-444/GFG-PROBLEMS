class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &nums1, vector<int> &nums2, int k) {
        // code here
        int n = nums1.size();
        vector<vector<int>>ans;
        
        using T = tuple<int, int, int>; // Represents (sum, index in nums1, index in nums2)
        priority_queue<T, vector<T>, greater<T>> pq; // Min-heap based on the sum

        
        //push first nums1[0] with all nums2[i] sum
        //with {sum , i , j }
        for(int i = 0 ; i < nums2.size() ; i++){
            pq.emplace(nums1[0] + nums2[i] , 0 , i);
        }
        
        //now Extract K pairs With smallest 
        while(!pq.empty() && k --){
            auto [sum , i , j] = pq.top();
            pq.pop();
            
            ans.push_back({nums1[i] , nums2[j]});
            
            if(i + 1 < n){
                pq.emplace(nums1[i + 1] + nums2[j] , i + 1 , j);
            }
        }
        
        return ans;
    }
};
