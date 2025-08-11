class Solution {
  public:
  /***
   * Minimum cost → buy the cheapest candy each time, get the k most expensive remaining candies for free.

Maximum cost → buy the most expensive candy each time, get the k cheapest remaining candies for free.
  
  
  
  
  
  ***/
    vector<int> minMaxCandy(vector<int>& prices, int k) {
    sort(prices.begin(), prices.end());
    int n = prices.size();

    // Minimum cost
    int minCost = 0, i = 0, j = n - 1;
    while (i <= j) {
        minCost += prices[i];
        i++;
        j -= k; // take k free from the end
    }

    // Maximum cost
    int maxCost = 0;
    i = n - 1, j = 0;
    while (j <= i) {
        maxCost += prices[i];
        i--;
        j += k; // take k free from the start
    }

    return {minCost, maxCost};
    }
};