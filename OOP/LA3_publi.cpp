/*Imagine a publishing company which does marketing for book and audio cassette versions.
 Create a class publication that stores the title (a string) and price (type float) of publications. 
 From this class derive two classes: book which adds a page count (type int) and tape which adds a
 playing time in minutes (type float).Write a program that instantiates the book and tape class,
  allows user to enter data and displays the data members. If an exception is caught, replace 
  all the data member values with zero values.
*/
#include<iostream>
#include<string>
using namespace std;

class publication
{
public:
string title;
float price;

public:
void add()
{
cout<<"\n Enter Title of publication: "<<endl;
cin.ignore();
getline(cin,title);

cout<<"\n Enter price of publication: "<<endl;
cin>>price;
}

void display()
{
cout<<"\n------------------------------------"<<endl;
cout<<"\n Title of publication : "<<title<<endl;
cout<<"\n Publication price : "<<price<<endl;
}
};//publication class ends

class book: public publication
{
private:
int page_count;
public:
void add_book()
{
try
{
add(); //call function of base class
cout<<"Enter page count of book : "<<endl;
cin>>page_count;

if(page_count<=0)
throw page_count;
}
catch(...)
{
cout<<"Invalid page count....";
page_count = 0;
}//end of catch
}// end of add_book()

void display_book()
{
display(); //call function of base class
cout<<"\n page count : "<<page_count<< " "<<endl;
cout<<"\n------------------------------------"<<endl;
}

};//end of book class

class tape: public publication
{
private:
float play_time;
public:
void add_tape()
{
try
{
add(); //call function of base class
cout<<"Enter play time of tape in minutes : "<<endl;
cin>>play_time;

if(play_time<=0)
throw play_time;
}
catch(...)
{
cout<<"Invalid play time...."<<endl;
play_time = 0;
}//end of catch
}// end of add_book()

void display_tape()
{
display();//call function of base class
cout<<"\n play time : "<<play_time<<" minutes"<<endl;
cout<<"\n------------------------------------"<<endl;
}
};//end of book class

int main()
{
book b1[10];
tape t1[10];
int ch=0, b_count = 0, t_count = 0;

do
{
cout<<"\n *** Publication Details ***"<<endl;
cout<<"\n *** Menu ***"<<endl;
cout<<"\n 1. Add Information of Books "<<endl;
cout<<"\n 2. Add Information of Tape "<<endl;
cout<<"\n 3. Display Information of Books "<<endl;
cout<<"\n 4. Display Information of Tapes "<<endl;
cout<<"\n 5. Exit "<<endl;
cout<<"Enter your choice ";
cin>>ch;

switch(ch)
{
case 1:
b1[b_count].add_book();
b_count++;
break;

case 2:

t1[t_count].add_tape();
t_count++;
break;

case 3:
cout<<"\n *** Publication Information system (books) ***"<<endl;
for(int j=0;j<b_count;j++){
b1[j].display_book();
}
break;

case 4:
cout<<"\n *** Publication Information system (tape) ***"<<endl;
for(int j=0;j<t_count;j++){
t1[j].display_tape();
}
break;

case 5:
exit(0);
}//end of switch
}while(ch != 5);

return 0;
}