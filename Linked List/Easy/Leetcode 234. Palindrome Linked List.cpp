/*****************************************************************************************************************************************************
QUESTION: Given the head of a singly linked list, return true if it is a palindrome.

APPROACH: To check Palindrome we first store the values of list in a vector since further process will lead in modifications in LL. We create a reverse function
          to get reversed LL, after storing. Now we compare the LL and vector values to check palindrome or not.
          
*******************************************************************************************************************************************************/          

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
    bool isPalindrome(ListNode* head) {
        ListNode* myl = head;
    vector<int> v;
    while(myl != NULL)
    {
        v.push_back(myl->val);
        myl = myl->next;
    }
        ListNode* newhead = reverseList(head);
        ListNode *t1 = head, *t2 = newhead;
       for(int i = 0; i < v.size(); i++)
        {
            if(v[i] != t2->val)
            return 0;
            t2 = t2->next;
        }
        return 1;
        v.empty();
    }
};
