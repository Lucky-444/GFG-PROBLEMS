class Solution {
  public:
    int maxCircularSum(vector<int> &v) {
        // code here
           int total_sum = 0, max_sum = INT_MIN, min_sum = INT_MAX, pos_sum = 0,
            neg_sum = 0;
        for (int i = 0; i < v.size(); i++) {
            total_sum += v[i];
            pos_sum += v[i];
            neg_sum += v[i];
            max_sum = max(pos_sum, max_sum);
            if (pos_sum < 0) {
                pos_sum = 0;
            }
            min_sum = min(neg_sum, min_sum);
            if (neg_sum > 0) {
                neg_sum = 0;
            }
        }
        return (total_sum == min_sum) ? max_sum
                                      : max(max_sum, total_sum - min_sum);
    }
};