class Solution {
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> result;

        // prefix sum
        for(int i = 1; i < n; i++)
            arr[i] += arr[i - 1];

        for(int i = 0; i < queries.size(); i++) {
            int L = queries[i][0];
            int R = queries[i][1];

            int sum = arr[R];
            if(L > 0)
                sum -= arr[L - 1];

            int mean = sum / (R - L + 1);
            result.push_back(mean);
        }

        return result;
    }
};