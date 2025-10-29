/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool solve(Node *r1 , Node *r2){
        if(!r1 && !r2){
            return true ;
        }
        
        if(!r1 || !r2){
            return false;
        }
        
        if(r1 -> data != r2 -> data){
            return false;
        }
        
        //go once both left and once roght
        //go once left another node right
        //go right another node left
        return (solve(r1 -> left , r2 -> left) && solve(r1 -> right , r2 -> right)) ||
                solve(r1 -> left , r2 -> right) && solve(r1 -> right , r2 -> left); 
    }
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1, Node *root2) {
        // add code here.
        //swap any left node with right
        return solve(root1 , root2);
        
    }
};