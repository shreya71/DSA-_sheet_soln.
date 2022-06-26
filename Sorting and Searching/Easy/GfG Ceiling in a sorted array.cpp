/********************************************************************************************************************
QUESTION: Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x,
          and the floor is the greatest element smaller than or equal to x. Assume that the array is sorted in non-decreasing order. Write efficient functions 
          to find the floor and ceiling of x. 
          
APPROACH: finding element in array >= x....break; sice found.
************************************************************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n, x, ceil_r;
    cin >> n;
    int a[n];
    for(int i = 0; i< n; i++)
    cin >> a[i] ;
    cin >> x;
    for(int i = 0; i< n; i++)
    {
        if(x > a[n-1])
        {ceil_r = -1 ;
        break;}
        else if(a[i] >= x)
        {ceil_r = a[i];
        break;}
    }
    if(ceil_r == -1)
    cout << "ceiling doesn't exist" << endl ;
    else
    cout << ceil_r << endl;
    return 0;
}
