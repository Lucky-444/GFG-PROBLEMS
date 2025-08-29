class Solution {
  public:
  /*
    Suppose person C is the celebrity:
    
    For all i != C,
    mat[i][C] == 1 ✅ (everyone knows celebrity)
    
    For all j != C,
    mat[C][j] == 0 ✅ (celebrity knows no one)
  */
    int celebrity(vector<vector<int>>& mat) {
        // code here
        //the qn says that
        //There are n people → indexed 0, 1, 2, …, n-1.
        //which one of them is the celibrety
        int n = mat.size();
        // findout this one
        int a = 0, b = n - 1;
        
        //colm wise search which is the perfect candidate for the position
        // Step 1: Find candidate (binary search style elimination)
        while (a < b) {
            if (mat[a][b] == 1) {
                a++; // a knows b → a can't be celebrity
            } else {
                b--; // a does not know b → b can't be celebrity
            }
        }
        
        int c = a; //it stops at a position where both condition is satisfy
        
        for(int i = 0 ; i < n ; i++){
            if(i != c){
                if(mat[i][c] == 0 || mat[c][i] == 1){
                    return -1 ;
                }
            }
        }
        
        return c;
        
        
    }
};