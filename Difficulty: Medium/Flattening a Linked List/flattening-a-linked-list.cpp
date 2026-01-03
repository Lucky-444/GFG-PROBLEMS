/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
Node *flatten(Node *root) {
        // code here
        // Time - O(n^2), Space - O(1)
// first try to sort all the nodes for next pointer and then place all node to bottom.
        if(root == NULL || (root->next == NULL && root->bottom == NULL)) return root;
        
        Node* cur = root;
        while(cur!= NULL){
// iterating all the bottom nodes for ....
            while(cur->bottom!=NULL){
                Node* replace = cur->bottom;
                cur->bottom = cur->bottom->bottom;
                replace->bottom = NULL;

                // find approprite place for replace to place
                Node* ptr = cur;
                while(ptr->next != NULL){
                    if(ptr->next->data >= replace->data) {
                        replace->next = ptr->next;
                        ptr->next = replace;
                        
                        break;
                    }
                    ptr = ptr->next;
                }
                if(ptr->next == NULL){
                    ptr->next = replace;
                }
            }
            cur = cur->next;
            
        }
// this will give us the linked list in sorted order
        cur = root;
// moving all the sorted nodes to the bottom of the head
        Node* bt = cur;
        while(cur->next!=NULL){
            Node* temp = cur->next;
            cur->next = cur->next->next;
            bt->bottom = temp;
            bt = bt->bottom;
        }
        
        return root;
    }
};