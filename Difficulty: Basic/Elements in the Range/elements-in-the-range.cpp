class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
          long long expectedCount = end - start + 1;

    long long expectedSum =
        1LL * (expectedCount) * (start + end) / 2;

    long long actualSum = 0;
    long long actualCount = 0;

    for (int x : arr) {

        if (x >= start && x <= end) {
            actualSum += x;
            actualCount++;
        }
    }

    return (actualCount == expectedCount &&
            actualSum == expectedSum);
    }
};
