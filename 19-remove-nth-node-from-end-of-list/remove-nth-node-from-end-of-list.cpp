class Solution {
public:
    // Function to calculate length of linked list
    int size(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            cnt++;              // count each node
            temp = temp->next;  // move forward
        }
        return cnt;
    }

    // Function to remove Nth node from the end
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = size(head);          // total number of nodes
        int deleteIdx = l - n;       // it the idex frm start

        // Case 1: If head node needs to be deleted
        if (deleteIdx == 0) {
            return head->next;
        }

        // Traverse to the node just before the one to delete
        ListNode* temp = head;
        for (int i = 0; i < deleteIdx - 1; i++) {
            temp = temp->next;
        }

        // Delete the Nth node from end
           temp->next = temp->next->next;

        return head;                 // return updated head
    }
};
