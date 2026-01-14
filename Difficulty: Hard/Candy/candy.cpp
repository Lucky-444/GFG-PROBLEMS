class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        if (arr.size() == 1)
            return 1;
        int i = 1;
        int sum = 1;

        int n = arr.size();
        while (i < n) {
            if (arr[i] == arr[i - 1]) {
                sum = sum + 1;
                i++;
                continue;
            }
            int p = 1;

            while (i < n && arr[i] > arr[i - 1]) {
                p++;
                sum += p;
                i++;
            }
            int d = 0;
            while (i < n && arr[i] < arr[i -1]) {

                d++;
                sum += d;
                i++;
            }
            if (d >= p) {
                sum += (d - p + 1);
            }
        }
        return sum;
    }
};
