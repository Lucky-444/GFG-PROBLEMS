//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int solve(int i, int p, vector<int>& arr, vector<vector<int>>& dp) {
        if (i >= arr.size())
            return 0;

        if (dp[i][p + 1] != -1)
            return dp[i][p + 1];
        // for pick condition
        int pick = 0;
        if (p == -1 || arr[p] < arr[i]) {
            pick = arr[i] + solve(i + 1, i, arr, dp);
        }
        // for not pick
        int np = solve(i + 1, p, arr, dp);

        // just do coordinate change -1 to 0

        return dp[i][p + 1] = max(pick, np);
    }
    int maxSumIS(vector<int>& nums) {
        // Your code goes here
          int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends