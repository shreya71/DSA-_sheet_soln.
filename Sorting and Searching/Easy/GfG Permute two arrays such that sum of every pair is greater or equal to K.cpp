/******************************************************************************************************************************************
QUESTION: Given two arrays of equal size n and an integer k. The task is to permute both arrays such that sum of their corresponding element is greater than
          or equal to k i.e a[i] + b[i] >= k. The task is print “Yes” if any such permutation exists, otherwise print “No”.
          
APPROACH: Arranging on earray in ascending and other array in descending order. Then applying the condition a[i] + b[i] >= k.

********************************************************************************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int A[], int B[], int n, int k)
{
    sort(A, A+n);
    sort(B, B+n, greater<int>());
    for(int i =0; i< n; i++)
    if(A[i] + B[i] < k)
    return 0;
    return 1;
}
int main()
{
    int n, k;
    cin >> n;
    int A[n], B[n];
    for(int i = 0; i< n; i++)
    cin >> A[i];
    for(int i = 0; i< n; i++)
    cin >> B[i];
    cin >> k;
    if(check(A, B, n, k) == true)
    cout << "yes" << endl;
    else
    cout << "no" << endl;
}
