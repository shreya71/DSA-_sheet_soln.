/*****************************************************************************************************************************************
QUESTION: You are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a one sorted list. The list should be made by splicing
          together the nodes of the first two lists. Return the head of the merged linked list.
          
APPROACH: Two methods: 1. By iteration      2. By recursion(easier)
          1. we make 3 pointers, for LL1, LL2 and for a dummy node in which we return our final merged LL.
          2. we create a pointer named list and store the smaller node and then recursively call function till both list1 & list doesn't reaches NULL.
          
**********************************************************************************************************************************************/

// ITERATIVE METHOD

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *t1 = list1, *t2 = list2 ; 
        ListNode* fl = new ListNode(-1);     // this is node not pointer
        ListNode *list = fl;  
        while(t1 != NULL && t2 != NULL)
        {
            if(t1->val < t2->val)
            {
                list->next = t1;
                t1 = t1->next;
            }
            else
            {
                list->next = t2;
                t2 = t2->next;
            }
            list = list->next;
        }
        while(t1 != NULL)
        {
            list->next = t1;
                t1 = t1->next;
            list = list->next;
        }
         while(t2 != NULL)
        {
            list->next = t2;
                t2 = t2->next;
            list = list->next;
        }
        return fl->next;        // we return the next of our dummy node(fl)
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  RECURSIVE METHOD

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list ; 
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        if(list1->val < list2->val)
            {
                list= list1;
                list->next = mergeTwoLists(list1->next, list2) ;
            }
            else
            {
                list= list2;
                list->next = mergeTwoLists(list1, list2->next) ;
            }
        return list;      
    }
};
