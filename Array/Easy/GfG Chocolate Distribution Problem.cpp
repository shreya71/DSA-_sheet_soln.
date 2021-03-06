/*****************************************************************************
QUESTION: Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. 
          There are m students, the task is to distribute chocolate packets such that: 
          1. Each student gets one packet.
          2. The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
 
 APPROACH: Sorting array and then finding minimum difference between any ith and (i+student)th element
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int a[n];
   for(int i = 0; i< n; i++)
   {
       cin >> a[i];
   }
   int students;
   cin >> students;
   sort(a, a+n);
   int d = abs(a[0]-a[0+students-1]);
   for(int i = 0; i <= n-students; i++ )
   {
       if(abs(a[i]-a[i+students-1]) < d)
       d = abs(a[i]-a[i+students-1]);
   }
   cout << d << endl;
}
