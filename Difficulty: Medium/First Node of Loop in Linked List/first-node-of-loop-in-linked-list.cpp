class Solution {
  public:
    int cycleStart(Node* head) {
        if (!head || !head->next) return -1;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find start of loop
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow->data; // starting node value
            }
        }

        return -1; // no loop
    }
};