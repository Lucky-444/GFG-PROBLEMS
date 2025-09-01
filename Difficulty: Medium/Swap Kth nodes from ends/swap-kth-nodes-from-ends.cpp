/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
                if (!head || !head->next) return head;

        // Step 1: find length of list
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: check invalid case
        if (k > n) return head;

        int pos1 = k;
        int pos2 = n - k + 1;

        // If both are same, nothing to swap
        if (pos1 == pos2) return head;

        // Step 3: find kth from start (node1) and kth from end (node2)
        Node* prev1 = nullptr, *node1 = head;
        for (int i = 1; i < pos1; i++) {
            prev1 = node1;
            node1 = node1->next;
        }

        Node* prev2 = nullptr, *node2 = head;
        for (int i = 1; i < pos2; i++) {
            prev2 = node2;
            node2 = node2->next;
        }

        // Step 4: link previous nodes to opposite nodes
        if (prev1) prev1->next = node2;
        else head = node2;

        if (prev2) prev2->next = node1;
        else head = node1;

        // Step 5: swap next pointers of node1 and node2
        Node* tmp = node1->next;
        node1->next = node2->next;
        node2->next = tmp;

        return head;
    }
};