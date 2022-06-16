/* 
QUESTION: Given two numbers represented by linked lists, write a function that returns the multiplication of these two linked lists.

APPROACH: finding length of each list, getting the list nodes in no. format and returning the multiplied value.
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
void push(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
        head = n;
}
int lengthn(node* head)
{
    node* temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int multiplication(node* &head1, node* &head2)
{
    int n1 = 0, n2 = 0, l ;
    node *t1 = head1, *t2 = head2;
    l = lengthn(head1);
    l--;
    while(t1 != NULL)
    {
        n1 += t1->data * pow(10, l);
        t1 = t1->next;
        l--;
    }
    l = lengthn(head2);
    l--;
    while(t2 != NULL)
    {
        n2 += t2->data * pow(10, l);;
        t2 = t2->next;
        l--;
    }
    return n1*n2 ;
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
    node* head1 = NULL;
    push(head1, 6);
    push(head1, 4);
    push(head1, 9);
    node* head2 = NULL;
    push(head2, 4);
    push(head2, 8);
    display(head1);
    display(head2);
    int result = multiplication(head1, head2);
    cout << result << endl;
}
