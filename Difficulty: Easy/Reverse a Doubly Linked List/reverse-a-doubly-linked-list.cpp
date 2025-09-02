/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* left = head;
        Node* temp = new Node(0);
        int l=0, r=0;
        Node* right = head;
        while(right->next != NULL){
            right = right->next;
            r++;
        }
        while(l<=r){
            temp->data = left->data;
            left->data = right->data;
            right->data = temp->data;
            
            right = right->prev;
            left = left->next;
            l++, r--;
        }
        return head;
    }
};