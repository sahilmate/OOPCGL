/* 
Write a function template for selection sort that inputs,
 sorts and outputs an integer array and a float array
*/
#include<iostream>
using namespace std;
template<class T>

void sort(T a[], int n)
{
int pos_min, i;
T temp;

for(int i=0; i < n-1; i++)
{
pos_min = i;

for(int j = i+1; j<n; j++)
{

if(a[j] < a[pos_min])
pos_min = j;
}
if(pos_min != i)
{
temp = a[i];
a[i] = a[pos_min];
a[pos_min] = temp;
}
}
cout<< "\n sorted elements are :\n";

for(i=0; i<n; i++)
cout<< "\t" <<a[i];
}
//main function
int main()
{
int n, i, ch;
int a[10];
float b[10];
do
{
cout<<"\n selection sort using function temmplate ";
cout<<"\n \t 1. sort integer numbers ";
cout<<"\n \t 2. sort float numbers ";
cout<<"\n \t 3. exit ";
cout<< "\n enter your choice ";
cin>>ch;

switch(ch)

{
case 1:
cout<< "\n\t sorting integer numbers ";
cout<< "\n\t enter how many numbers wanted to sort ";
cin >> n;

for(i=0; i<n; i++)
cin>>a[i];

sort<int>(a, n);
break;

case 2:
cout<< "\n\t sorting float numbers ::: ";
cout<< "\n\t enter how many numbers wanted to sort ::: ";
cin >> n;

for(i=0; i<n; i++)
cin>>b[i];

sort<float>(b, n);
break;

case 3:
exit (0);
break;
}
}
while(ch != 3);
return (0);
}