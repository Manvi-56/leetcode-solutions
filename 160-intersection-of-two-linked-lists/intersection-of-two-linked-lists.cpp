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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Step 1: Find length of list A
        int lenA = 0;
        ListNode* tempA = headA;
        while (tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }

        // Step 2: Find length of list B
        int lenB = 0;
        ListNode* tempB = headB;
        while (tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }

        // Step 3: Reset pointers to heads
        tempA = headA;
        tempB = headB;

        // Step 4: Move pointer of longer list by difference
        if (lenA > lenB) {
            int diff = lenA - lenB;
            for (int i = 0; i < diff; i++) {
                tempA = tempA->next;
            }
        } else {
            int diff = lenB - lenA;
            for (int i = 0; i < diff; i++) {
                tempB = tempB->next;
            }
        }

        // Step 5: Move both pointers together to find intersection
        while (tempA != NULL && tempB != NULL) {
            if (tempA == tempB) {
                return tempA;   // intersection node
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        // Step 6: No intersection
        return NULL;
    }
};
