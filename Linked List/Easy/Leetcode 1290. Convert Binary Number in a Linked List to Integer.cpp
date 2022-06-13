/**************************************************************************************************************************************
QUESTION: Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list 
          holds the binary representation of a number. Return the decimal value of the number in the linked list.
          
APPROACH: Finding size of linked list to get the multiplier m, then calculating integer using the exp. bn in solution.

******************************************************************************************************************************************/

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
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        int bn = 0, m = 0;
        while(temp->next != NULL)
        {
            temp = temp->next;
            m++;
        }
        temp = head;
        while(temp != NULL)
        {
                bn += pow(2, m) * temp->val;
            temp = temp->next;
            m--;
        }
        return bn;
    }
};
