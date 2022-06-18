/***************************************************************************************************************************************************
QUESTION: You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes
          contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero,
          except the number 0 itself.
          
APPROACH: Just reversing both numbers in beginnig and rest is same as Leetcode 2. Add Two Numbers .

********************************************************************************************************************************************************/

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
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        return head;
        ListNode* temp = reverse(head->next);         
    head->next->next = head;
    head->next = NULL;
    return temp;
    }
    void push(ListNode* &head, int val)
    {
        ListNode* n = new ListNode(val);
        n->next = head;
        head = n;
    }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ll1 = lengthn(l1), ll2 = lengthn(l2) ;
        ListNode* l1head = reverse(l1);
        ListNode* l2head = reverse(l2);
        ListNode* newhead = NULL;
        ListNode *t1, *t2;
        if(ll1 >= ll2)
         t1 = l1head, t2 = l2head;
               else 
            t1 = l2head, t2 = l1head;
        int psum = 0;
        while(t1 != NULL )
        {
            int sum = 0, carry = 0;
            if(psum > 9)
                carry = 1;
            if(carry == 1 && t2 != NULL)
                sum += t1->val + t2->val + 1;
            else if(carry == 1 && t2 == NULL)
                sum += t1->val + 1;
            else if(carry == 0 && t2 != NULL)
                sum += t1->val + t2->val;
            else
                sum += t1->val ;
            int s = sum;
            push(newhead, s%10);
            t1 = t1->next;
            if(t2 != NULL)
            t2 = t2->next;
            psum = sum;
        }
        if(psum > 9)
            push(newhead, 1);
        return newhead;
        
    }
};
