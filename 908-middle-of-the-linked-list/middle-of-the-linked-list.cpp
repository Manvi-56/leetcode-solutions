class Solution {
public:
    // Function to calculate the size (length) of the linked list
    int size(ListNode* head) {
        int n = 0;                  // counter to store number of nodes
        ListNode* temp = head;      // temp pointer to traverse the list

        // Traverse the linked list
        while (temp != NULL) {
            n++;                    // increase count for each node
            temp = temp->next;      // move to the next node
        }
        return n;                   // return total number of nodes
    }

    // Function to find the middle node of the linked list
    ListNode* middleNode(ListNode* head) {
        int n = size(head);         // get total number of nodes
        int mid = n / 2;            // index of middle node (0-based)

        ListNode* temp = head;      // pointer to traverse from head

        // Move temp 'mid' steps forward
        for (int i = 0; i < mid; i++) {
            temp = temp->next;      // move to next node
        }

        // temp now points to the middle node
        return temp;
    }
};

