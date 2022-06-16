/*******************************************************************************************************************************************
QUESTION: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked 
          lists have no intersection at all, return null.
          
APPROACH: Finding the diff. in length of both lists, starting to check ptr from equal positions in both list by setting the pointer of longer list 
          to its length-diff.
          
**********************************************************************************************************************************************/          
          
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
    int lengthn(ListNode* head)
{
    ListNode* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = lengthn(headA), l2 = lengthn(headB);
        int equi = abs(l1-l2) ;
        ListNode *t1, *t2;
        if(l1 > l2)
        {
            t1 = headA;
            t2 = headB;
        }
        else
        {
            t2 = headA;
            t1 = headB;
        }
        while(equi)
        {
            t1 = t1->next;
            if(t1 == NULL)
                return NULL;
            equi--;
        }
        while(t1 != NULL && t2 != NULL)
        {
            if(t1 == t2)    // values at diff. points can be equal so we equate ptr
                break;      // ptr are pointing same address
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};
