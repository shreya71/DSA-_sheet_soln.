/***********************************************************************************************************************************

QUESTION: Given an array of size n, generate and print all possible combinations of r elements in array. Also handle duplicates. 
          For example, if input array is {1, 2, 1} and r is 2, then the program prints {1, 2} and {2, 1} as two different combinations. Avoid this.

APPROACH: RECURSION

*************************************************************************************************************************************/
//                   Time Complexity = O(N^2)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void subsets(int A[], int n, int r, int index, int data[], int i)
{
    if(index == r)                                   // Printing the subset obtained
    {
        for(int j = 0; j < r; j++)
        cout << data[j] << " " ;
        cout << endl;
    return;
    }
    if(i >= n)
    return;
    data[index] = A[i] ;
    subsets(A, n, r, index+1, data, i+1);           // Inclusion
    while (A[i] == A[i+1])                         // TO avoid repetition of subsets in case of duplicatess
             i++;
    subsets(A, n, r, index, data, i+1);           // Exclusion
}
int main()
{
    int A[] = {1, 2, 1};
    int r = 2;
    int n = sizeof(A)/sizeof(A[0]);
    int data[r];
    sort(A, A+n);
    subsets(A, n, r, 0, data, 0);
    return 0;
}
