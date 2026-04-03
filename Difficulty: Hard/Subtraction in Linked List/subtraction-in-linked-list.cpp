

class Solution {
  public:
  
    // Reverse linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        while (head) {
            Node* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    
    // Compare two lists
    bool isSmaller(Node* a, Node* b) {
        int len1 = 0, len2 = 0;
        Node* t1 = a;
        Node* t2 = b;
        
        while (t1) { len1++; t1 = t1->next; }
        while (t2) { len2++; t2 = t2->next; }
        
        if (len1 != len2) return len1 < len2;
        
        // same length → compare digit by digit
        while (a && b) {
            if (a->data != b->data)
                return a->data < b->data;
            a = a->next;
            b = b->next;
        }
        
        return false;
    }
    
    Node* subLinkedList(Node* l1, Node* l2) {
        
        // Step 1: Ensure l1 >= l2
        if (isSmaller(l1, l2)) {
            swap(l1, l2);
        }
        
        // Step 2: Reverse both
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        Node* head = NULL;
        Node* tail = NULL;
        
        int borrow = 0;
        
        // Step 3: Subtract
        while (l1) {
            int x = l1->data;
            int y = (l2 ? l2->data : 0);
            
            int diff = x - y - borrow;
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            Node* newNode = new Node(diff);
            
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        // Step 4: Reverse result
        head = reverse(head);
        
        // Step 5: Remove leading zeros
        while (head && head->data == 0 && head->next) {
            head = head->next;
        }
        
        return head;
    }
};