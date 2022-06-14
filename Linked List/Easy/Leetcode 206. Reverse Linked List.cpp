/***********************************************************************************************************************************************
QUESTION: Given the head of a singly linked list, reverse the list, and return the reversed list.

APPROACH: Using iteration method, three pointers used. Prev. pointed to NULL, current to head and next pointer next to current, transverse till
          current iteratot not equal to NULL. At every point we switch prev and nextptr links and then we define new sets of prev, curr, and nextptr
          moving to next node. So after last switching our prev. becomes our head and curr = NULL

*************************************************************************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode *prev = NULL, *curr = head, *nextptr;
        while(curr != NULL)
        {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;                                                     // new  head
    }
};
