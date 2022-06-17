/*
QUESTION: Given a linked list of 0s, 1s and 2s, sort it.

APPROACH: Count no. of 1s, 2s, and 0s, and make a list tp push them in ascending order.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void push(node* &head, int val)          //insertAtHead
{
    node* n = new node(val);
    n->next = head;
        head = n;
}
node* sortList(node* &head)
{
    int n1 = 0, n2 = 0, n3 = 0;
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        n1++;
        else if(temp->data == 1)
        n2++;
        else
        n3++;
        temp = temp->next;
    }
    node* list = NULL;
    while(n3 != 0)
    {
       push(list, 2);
        n3--;
    }
     while(n2 != 0)
    {
        push(list, 1);
        n2--;
    }
    while(n1 != 0)
    {
        push(list, 0);
        n1--;
    }
    return list;
}
void display(node* head)            
{
    node* temp = head;
    while(temp != NULL)
    {
    cout << temp->data << "->" ;
    temp = temp->next ;
    }
    cout << "NULL" <<  endl;
}
int main()
{
    node* head = NULL;
    push(head, 0);
    push(head, 1);
    push(head, 0);
    push(head, 2);
    push(head, 1);
    push(head, 1);
    push(head, 2);
    push(head, 1);
    push(head, 2);
    cout << "Linked List Before Sorting\n";
    display(head);
    
    node* newhead = sortList(head);
 
    cout << "Linked List After Sorting\n";
    display(newhead);
}
