#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        if (k <= 1) return true;              // trivial
        int n = arr.size();
        if (n < k) return false;

        // map: value -> min-heap of lengths of subsequences that end at `value`
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> tails;
        tails.reserve(n*2);
        for (int num : arr) {
            // try to extend a subsequence that ends at num-1
            auto it = tails.find(num - 1);
            if (it != tails.end() && !it->second.empty()) {
                int curLen = it->second.top();
                it->second.pop();
                // push extended subsequence ending at num
                tails[num].push(curLen + 1);
            } else {
                // start a new subsequence of length 1 ending at num
                tails[num].push(1);
            }
        }

        // verify every subsequence length >= k
        for (auto &p : tails) {
            auto &pq = p.second;
            while (!pq.empty()) {
                if (pq.top() < k) return false;
                pq.pop();
            }
        }
        return true;
    }
};
