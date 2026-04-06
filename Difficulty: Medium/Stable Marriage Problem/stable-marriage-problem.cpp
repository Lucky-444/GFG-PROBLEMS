class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        vector<int> wife(n, -1);      // wife[w] = man engaged to woman w
        vector<int> husband(n, -1);   // husband[m] = woman engaged to man m
        vector<int> next(n, 0);       // next woman to propose for each man
        
        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);  // all men are free initially
        }
        
        while (!q.empty()) {
            int m = q.front();
            q.pop();
            
            int w = men[m][next[m]]; // next preferred woman
            next[m]++;
            
            if (wife[w] == -1) {
                // woman is free
                wife[w] = m;
                husband[m] = w;
            } else {
                int m1 = wife[w];
                
                // check preference
                if (rank[w][m] < rank[w][m1]) {
                    // she prefers new man
                    wife[w] = m;
                    husband[m] = w;
                    
                    husband[m1] = -1;
                    q.push(m1); // previous man becomes free
                } else {
                    // she rejects new man
                    q.push(m);
                }
            }
        }
        
        return husband;
    }
};