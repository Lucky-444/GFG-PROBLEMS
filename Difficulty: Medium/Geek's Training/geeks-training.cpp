//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    int helper(auto &arr , int row , int lastCol , auto &dp){
        if(row == n){
            return 0;
        }
        if(dp[row][lastCol] != -1){
            return dp[row][lastCol];
        }
            
        int ans = INT_MIN;
        for(int i = 0; i < 3 ; i++){
            if(i != lastCol){
                int val = arr[row][i] + helper(arr , row + 1 ,i ,dp);
                ans = max(ans , val);
            }
        }
            
            
        return dp[row][lastCol] = ans;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
         n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); // last = 0,1,2, or 3 (none)
        return helper(arr, 0,3, dp); // Start with no task done previously
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends