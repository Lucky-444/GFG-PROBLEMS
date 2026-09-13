class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        // code here
           int rows = mat.size();
           int cols = mat[0].size();

           // Step 1: Mark adjacent unsafe cells as unsafe
           for (int row = 0; row < rows; row++) {
               for (int col = 0; col < cols; col++) {
                   if (mat[row][col] == 0) {
                       if (row - 1 >= 0 && mat[row - 1][col] == 1)
                           mat[row - 1][col] = 2; // Mark upper cell
                       if (row + 1 < rows && mat[row + 1][col] == 1)
                           mat[row + 1][col] = 2; // Mark lower cell
                       if (col - 1 >= 0 && mat[row][col - 1] == 1)
                           mat[row][col - 1] = 2; // Mark left cell
                       if (col + 1 < cols && mat[row][col + 1] == 1)
                           mat[row][col + 1] = 2; // Mark right cell
                   }
               }
           }

           // Step 2: Initialize distance matrix
           vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

           // Priority queue to store {distance, {row, col}}
           priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

           // Step 3: Add all valid starting points from the leftmost column
           for (int i = 0; i < rows; i++) {
               if (mat[i][0] == 1) {
                   pq.push({1, {i, 0}});
                   dist[i][0] = 1;
               }
           }

           // Step 4: Define directions for movement (up, left, down, right)
           int delrow[] = {-1, 0, 1, 0};
           int delcol[] = {0, -1, 0, 1};

           // Step 5: Perform Dijkstra's algorithm to find the shortest path
           while (!pq.empty()) {
               auto it = pq.top();
               pq.pop();
               int dis = it.first;
               int row = it.second.first;
               int col = it.second.second;

               // If we reach the last column, return the distance
               if (col == cols - 1)
                   return dis;

               // Explore all 4 possible directions
               for (int i = 0; i < 4; i++) {
                   int nrow = row + delrow[i];
                   int ncol = col + delcol[i];

                   // Check bounds, valid cell, and if a shorter distance is found
                   if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols &&
                       mat[nrow][ncol] == 1 && dist[nrow][ncol] > dis + 1) {
                       dist[nrow][ncol] = dis + 1;
                       pq.push({dist[nrow][ncol], {nrow, ncol}});
                   }
               }
           }

           // Return -1 if no path exists
           return -1;
    }
};