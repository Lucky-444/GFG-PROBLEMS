/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    int getSize(Node* root) {
        // code here
        int cnt=  0;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            cnt ++;
            
            if(node -> left){
                q.push(node -> left);
            }
            
            if(node -> right){
                q.push(node -> right);
            }
        }
        
        return cnt;
    }
};