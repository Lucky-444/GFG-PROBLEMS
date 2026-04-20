class Solution {
  public:
    int pour(int fromCap, int toCap, int d) {
    int from = fromCap;  // fill source
    int to = 0;
    int step = 1;

    while (from != d && to != d) {
        int temp = min(from, toCap - to);

        to += temp;
        from -= temp;
        step++;

        if (from == d || to == d) break;

        if (from == 0) {
            from = fromCap;
            step++;
        }

        if (to == toCap) {
            to = 0;
            step++;
        }
    }

    return step;
}

int minSteps(int m, int n, int d) {
    if (d > max(m, n)) return -1;

    int g = __gcd(m, n);
    if (d % g != 0) return -1;

    return min(pour(m, n, d), pour(n, m, d));
}

   
};