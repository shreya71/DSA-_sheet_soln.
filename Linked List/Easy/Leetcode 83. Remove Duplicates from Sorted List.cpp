/********************************************************************************************************************************************************
QUESTION: Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

APPROACH: We search for temp->val equal to val of tamp->next till temp and temp->exist otherwise we make temp-> as temp->next->next.

*********************************************************************************************************************************************************/

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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head ;
        while(temp)
        {
            if( temp->next && temp->next->val == temp->val )
            temp->next = temp->next->next;
            else
        temp = temp->next;
        }
        return head;
    }
};
