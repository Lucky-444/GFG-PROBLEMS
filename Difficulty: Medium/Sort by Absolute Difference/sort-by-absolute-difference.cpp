class Solution {
  public:
    void rearrange(vector<int> &arr, int k) {
  // map: difference -> elements (preserves insertion order for each difference)
        unordered_map<int, vector<int>> mp;
        vector<int> diffs;

        // fill map
        for (int x : arr) {
            int diff = abs(k - x);
            if (mp.find(diff) == mp.end()) {
                diffs.push_back(diff); // store diff once
            }
            mp[diff].push_back(x);
        }

        // sort differences
        sort(diffs.begin(), diffs.end());

        // rebuild arr
        arr.clear();
        for (int d : diffs) {
            for (int val : mp[d]) {
                arr.push_back(val);
            }
        }
    }
};