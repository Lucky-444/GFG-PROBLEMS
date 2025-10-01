class Solution {
  public:
    set<vector<int>> st;       // to store unique permutations
    vector<int> temp;          // current permutation
    vector<bool> used;         // marks used elements

    void backtrack(vector<int>& arr) {
        if (temp.size() == arr.size()) {
            st.insert(temp);   // store in set to avoid duplicates
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                temp.push_back(arr[i]);

                backtrack(arr);

                // backtrack
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        used.assign(arr.size(), false);
        backtrack(arr);

        // convert set to vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};