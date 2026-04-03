/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


class Solution {
  public:
  
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    Node* addOne(Node* head) {
        // Step 1: reverse
        head = reverse(head);
        
        Node* curr = head;
        int carry = 1;
        
        // Step 2: add 1
        while (curr && carry) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            
            // if last node and still carry
            if (!curr->next && carry) {
                curr->next = new Node(carry);
                carry = 0;
                break;
            }
            
            curr = curr->next;
        }
        
        // Step 3: reverse back
        head = reverse(head);
        
        return head;
    }
};