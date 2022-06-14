/**************************************************************************************************************************************************
QUESTION: Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

APPROACH: if val matches any next node we skip to next of next.
          Base conditions if head == NULL, NULL returned
          and if val of head is = val, we send the head->next in the function again to begin with a new head.
***************************************************************************************************************************************************/
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        if(head->val == val)                                              // case when head value == val
            return removeElements(head->next, val);
        ListNode* temp = head;
        while(temp)
        {
            if(temp->next && temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};
