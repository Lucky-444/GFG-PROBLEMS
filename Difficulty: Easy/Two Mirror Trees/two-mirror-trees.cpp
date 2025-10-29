/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution {
  public:
    bool solve(Node *a , Node *b){
        if(!a || !b){
            return a == b;
        }
        
        if(a -> data != b -> data){
            return false ;
        }
        
        return solve(a -> left , b -> right) && solve(a -> right , b -> left);
    }
    bool areMirror(Node* a, Node* b) {
        // Your code here
        return solve(a , b);
    }
};