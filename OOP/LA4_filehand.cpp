/*
Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.
*/
#include<iostream>
#include<fstream>
using namespace std;

class student
{
private:
string name;
int rollno;

public:
void add_info()
{
fstream fs;

fs.open("sample.txt", ios::app); //proper path of the file(sample.txt) should be given as the first
//argument
if(!fs)
{
cout<<" file creation failed...";
}else{
cout<<"\n Enter name : ";
cin>>name;
cout<<"\n Enter roll number : ";
cin>> rollno;

fs<<name<<" ";
fs<<rollno<<"\n";
fs.close();
} // else closes
} //add_info() ends

void display_info()
{
fstream fs;
fs.open("sample.txt", ios::in);

if(!fs)
cout<<"No such file....";
else
{
while(!fs.eof())
{
fs>>name;
fs>>rollno;
if(!fs.eof())

{
cout<<name<< " ";
cout<<rollno<< " \n ";
}
}
}
}
};

int main()
{
int ch;
student s;
fstream fs;

do
{
cout<<"\n **studnet information **";
cout<<"\n ** Menu ** ";
cout<<"\n 1. Add information : ";
cout<<"\n 2. Display information : ";
cout<<"\n 3. exit : ";
cout<<"\n Enter choice : ";
cin>>ch;

switch(ch)
{
case 1:
s.add_info();
break;

case 2:
s.display_info();
break;

case 3:
exit(0);
break;
}
} while(ch != 3);
 return 0;
}