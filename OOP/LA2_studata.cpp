/*
Develop a program in C++ to create a database of student’s information system containing the 
following information: Name, Roll number, Class, Division, Date of Birth, Blood group,
 Contact address, Telephone number, Driving license no. and other. Construct the database 
 with suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic memory
 allocation operators-new and delete as well as exception handling

*/
#include <iostream>
#include <string>
using namespace std;
class student
{
    private:
    string name, DoB, blood_grp, addr, year_class, mob;
    // as we need to use new and delete keyword, we should allocate memory dynamically to
    // some variable
    int* roll_no; //declaration of pointer for which we allocate memory dynamically
    int division;
    public:
    friend class faculty; //faculty class is friend of student class
    //default constructor
    student()
    {
        roll_no = new int; //reserve single location for roll no
        *roll_no = 0; division = 0; // assigned some default values to roll_no and div -- valid roll no starts with 1 you 
        //can initialize variable with 0 or -1 we are initializing variable to a starting point which is not a valid number
        name = blood_grp = DoB = addr = year_class = mob = " ";
    }
    //destructor: whatever the memory allocated by a new keyword it will deallocate by delete keyword
    ~student()
    {
        delete roll_no;//deallocation of roll_no
    }
    //function to add information in student database
    void add()
    {
        cout<<"\n Enter Student Information: ";
        cout<<"\n Enter Name: "<<endl;
        cin.ignore();//to clear input buffer
        getline(cin, name);//i want name along with the spaces thats why i have used getline(),
        //if only cin, it will only accepy first word.
        //when we use getline() sometimes it will not accept input or it will go to infinite loop 
        //or some kind of error occurs, to clear the input buffer we have used ignore()
        
        cout<<"Enter Roll number: "<<endl;
        cin>>*roll_no;
        cout<<"Enter Year (SE/TE/BE): ";
        cin>>year_class;
        cout<<"Enter Division(1/2/3/4): "<<endl;
        cin>>division;
        cout<<"Enter Date of Birth: "<<endl;
        cin>>DoB;
        cout<<"Enter Blood Group: "<<endl;
        cin>>blood_grp;
        cout<<"Enter Mobile number: "<<endl;
        cin>>mob;
        cout<<"Enter address: "<<endl;
        cin>>addr;
    }
    void display()
    {
        cout<<"\n-------------------------------------------"<<endl;
        cout<<"\n Name                      : "<<name;
        cout<<"\n Roll No.                  : "<<*roll_no;
        cout<<"\n Year(SE/TE/BE)            : "<<year_class;
        cout<<"\n Division(1/2/3/4)         : "<<division;
        cout<<"\n Date of Birth             : "<<DoB;
        cout<<"\n Blood Group               : "<<blood_grp;
        cout<<"\n Mobile Number             : "<<mob;
        cout<<"\n Address                   : "<<addr;
        cout<<"\n-------------------------------------------"<<endl;
    }
    //static member function
    static void header()
    {
        cout<<"\n * * * Student Information System * * *";
    }
};   //student class ends here
//class faculty
class faculty
{
    private:
    int id;
    
    public:
    //default constructor
    faculty()
    {
        id = 000;
    }
    //copy constructor
    faculty(const faculty &f1)
    {
        id = f1.id;
    }
    //function to display specific division Information
    void f_display(student &obj, int f_d)
    {
        try
        {
            if(obj.division == f_d)
            obj.display();
            else
            throw(obj.division);
        }
        catch(int x)
        {
            cout<<"\n Invalid Division : You are not teaching to this diivision.";
        }
    }
};
int main()
{
student st[5]; 
faculty f;
int ch = 0, count=0;
do
{
  cout<<"\n * * * * Student Information System * * * * ";
  cout<<"\n * * * Menu * * * ";
  cout<<"\n 1. Add Information ";
  cout<<"\n 2. Display Information ";
  cout<<"\n 3. Faculty wise Information ";
  cout<<"\n 4. Exit ";
  cout<<"\n Enter choice : ";
  cin>>ch;

    switch(ch)
    {
        case 1: 
            st[count].add();
            count++;
            break;
            
        
        case 2:
            for(int j = 0; j<count; j++)
            {
                student::header();//call static function
                st[j].display();
            }
            break;
        
        case 3:
            int f_div;
            cout<<"\n Enter Division of faculty : ";
            cin>>f_div;
            for(int j = 0; j<count; j++)
            {
                cout<<"\n * * * Student Information System (Faculty RAK)* * * ";
                f.f_display(st[j],f_div);
            }
            break;
        case 4:
            exit(0); // successful exit of a program // exit the program and return value 0
        
    } // end of switch statement
    
}while(ch!=4); //end of while

return 0;
}// end of main




