/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // Slow pointer moves one step at a time
        ListNode* slow = head;

        // Fast pointer moves two steps at a time
        ListNode* fast = head;

        // Traverse the linked list
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;          // move slow by 1 step
            fast = fast->next->next;   // move fast by 2 steps

            // If slow and fast meet, a cycle exists
            if (slow == fast)
                return true;
        }

        // If fast reaches NULL, no cycle exists
        return false;
    }
};
