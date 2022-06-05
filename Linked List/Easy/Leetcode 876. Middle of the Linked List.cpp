/*************************************************************************************************************************************
QUESTION: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

APPROACH: 1. INSTANT APPROACH: To find the middle of linked list and store it in count then return the nodes as sson as middle node is reached while traversing LL.
          2. BEST APPROACH: (TWO POINTER APPROACH/ TORTOISE METHOD) Optimized Solution
               USE THIS WHENEVER SOMETHING RELATEDD TO MIDDLE OF LINKED LIST IS TO BE DONE.
           We play with two pointers at a time. 1st pointer jumps one node at a time and second pointer jumps 2 nodes at a time. So till the 2nd pointer reaches 
           NULL or the last node of the LL(depending on even and odd nodes present respectively) the first pointer reaches the midlle elements as per the conditions. 
                       
****************************************************************************************************************************************/
//1.      Time Complexity: O(N)+O(N/2) 

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
    ListNode* middleNode(ListNode* head) {
        int count = 0, centre = 0;
        ListNode* temp = head;
        while(temp != NULL)
        { 
            count++;
            temp = temp->next ;
        }
        cout << count ;
        if(count%2 == 0)
            centre = (count/2) +1 ;
        else
            centre = (count+1)/2;
        temp = head;
        for(int i = 0; i < count; i++)
        {
            if(i < centre-1)
                temp = temp->next ;  
            else 
                i = count;
        }
        return temp;
    }
};


/* ################################################################################################################################################# */

//2. Time Complexity:  O(N/2)      Space Complexity: O(1)

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
    ListNode* middleNode(ListNode* head) {
        ListNode *first = head, *second = head;
        while(second != NULL && second->next != NULL )
        {
            first = first->next ;
            second = second->next->next;
        }
        return first;
    }
};
