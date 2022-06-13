/******************************************************************************************************************************
QUESTION: Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some
          node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's
          next pointer is connected to. Note that pos is not passed as a parameter. Return true if there is a cycle in the linked list. Otherwise, return false.

APPROACH: FLoyd's Cycle finding algo/ Hare Tortoise
          The time when faster moves by 2 nodes slower moves 1 node. So till the 2nd pointer reaches NULL or the last node of the LL, here the faster pointer moves to the
          position where cyclinf takes. So there is a time when slow == fast which means cycling is possible and basically if cycling will happen there will be no
          NULL so if slow==fast we get our solution.
********************************************************************************************************************************/

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
        ListNode *p1 = head, *p2 = head;
        if(head == NULL )
            return 0;
           while(p2 != NULL && p2->next != NULL)        // take care that p2->next condition should not be written before p2 condition
            {
                p1 = p1->next;
                p2 = p2->next->next;
                if(p1 == p2)
                   return 1;
            }
               return false;
    }
};
