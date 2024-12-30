/*Write C++ program using STL for sorting and searching user defined records such as Item records 
(Item code, Name, Cost, Quantity etc) using vector container.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class student
{
public:
int roll_no;
string name;
char mob[10];
bool operator == (const student &student1)
{
return(roll_no == student1.roll_no);
}
friend ostream& operator << (ostream &out, const student &k);
friend istream& operator >> (istream &in, const student &k);
};
ostream & operator << (ostream &out, student &k)
{
out<<"\n\t\t"<<k.roll_no<<"\t\t"<<k.name<<"\t\t"<<k.mob;
return out;
}

istream & operator >> (istream &in, student &k)
{
cout<<"\n Enter roll no : ";
in>>k.roll_no;
cout<<"\n Enter name : ";
in>>k.name;
cout<<"\n Enter mobile number : ";
in>>k.mob;
return in;
}
vector<student> read()
{
int n;
student k;
vector<student> j;
cout<<"\n Enter total no. of studnets: ";
cin>>n;
for(int i=0; i<n; i++)
{
cin>>k;
j.push_back(k);
}
return j;
}
void printfunction(student &k)
{
cout<<k;
}
void print(vector<student> &j)
{
cout<<"\n\t\t Roll number \t\t Name \t\t Mobile Number";
for_each(j.begin(), j.end(), printfunction);
}
void search(vector <student> &j)
{
student k;
cout<<"\n Enter student roll number to search : ";
cin>>k.roll_no;
cout<<"\n\n\t\t Roll No \t\t Name \t\t Mobile number";
vector<student>::iterator p;
p=find(j.begin(), j.end(), k);
if(p!=j.end())
cout<<*p;
else

cout<<"\n not found";
}
bool sort_func(student &x, const student &y){
return(x.roll_no < y.roll_no);
}
void sort(vector <student> &j)
{
sort(j.begin(), j.end(), sort_func);
}
int main()
{
vector <student> s;
int ch;
do{
cout<<"\n\n\t\t ---- Personal REcor database------";
cout<<"\n\t\t 1. Create record";
cout<<"\n\t\t 2. Display record";
cout<<"\n\t\t 3. Search record";
cout<<"\n\t\t 4. Sort record";
cout<<"\n\t\t 5. Quit";
cout<< "choice : ";
cin>>ch;
switch(ch)
{
case 1:
s=read();
break;
case 2:
print(s);
break;
case 3:
search(s);
break;
case 4:
sort(s);
print(s);
break;
case 5:
exit(0);

}

}while(ch != 5);
}