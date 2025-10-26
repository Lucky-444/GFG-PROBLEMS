/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/


class Solution {
  public:
    Node* createTree(vector<int>& parent) {
        // code here
             
        vector<Node*>node;
        int n=parent.size();
        for(int i=0; i<n; i++){
            node.push_back(new Node(i));
        }
        
        Node* root=NULL;
        
        for(int i=0; i<n; i++){
            if(parent[i] == -1){
                root = node[i];
            }
            else{
                if(!node[parent[i]]->left){
                    node[parent[i]]->left = node[i];
                }
                else{
                    node[parent[i]]->right = node[i];
                }
            }
        }
        
        return root;
    }
};
