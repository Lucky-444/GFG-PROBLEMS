class Solution {
  public:
    int minCost(int n, int m, vector<int>& X, vector<int>& Y) {
        //  code here
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        int i = X.size()-1;
        int j = Y.size()-1;
        int row = 1;
        int col = 1;
        int ans = 0;

        while(i>=0 || j>=0){
            int hcut = (i >= 0) ? X[i] : -1;
            int vcut = (j >= 0) ? Y[j] : -1;

            if(hcut>vcut){
                ans += (hcut*col);
                if(row<m) row++;
                i--;
            }
            
            else{
                ans += (vcut*row);
                if(col<n) col++;
                j--;
            }
        }

        return ans; 
    }
};
