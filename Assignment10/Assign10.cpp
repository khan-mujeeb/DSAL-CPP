/*Name: mujeeb ur rahman khan
Roll no: 27035

Title: File Handling

Problem Statement:Department maintains student’s database. The file contains roll number, name, division and address. Write a program to create a sequential file to store and maintain student data. It should allow the user to add, delete information of student. Display information of particular student. If record of student does not exist, appropriate message is displayed. If student record is found it should display the student details.

*/
#include<iostream>      /// i/p and o/p stream....
#include<fstream>       // file stream...
#include<string.h>      // for String operations...we used strcmp so need to include this header file
using namespace std;


class Student 
{
    char name[20],div,grade;
    float m,p,c,cs,e,tot,per;
    int roll_no;

    public:
        void SetData()      
        {
            cout<<"\tEnter Student Name : ";
            cin>>name;
            cout<<"\tEnter Roll NO : ";
            cin>>roll_no;
            cout<<"\tEnter Student Division : ";
            cin>>div;
        }
        void show()             
        {
            cout<<"Student Name : "<<name<<endl;
            cout<<"Roll No : "<<roll_no<<endl; 
            cout<<"Student Division : "<<div<<endl;
        }
        int getRoll()
        {
            return roll_no;
        }
};

fstream file;
Student s;

void DataInFile()               // Create record...
{
    file.open("sd.dat",ios::out|ios::app);
    s.SetData();
    file.write((char*)&s,sizeof(s));
    file.close();
    cout<<"\n\n\t\tStudent Record Created!!"<<endl<<endl;
}
void Display_all_student()             //Display all students Result of Students for Faculties....
{
    cout<<"\t\t***Displaying Students Record***"<<endl;
    file.open("sd.dat",ios::in);
    
    while(file.read((char*)&s,sizeof(s)))
    {
        s.show();
        cout<<"================================="<<endl;
    }
    file.close();
}

void DisplaySearchByRoll(int n)            // For Searching Particular Student Result
{
    int flag=0;
    file.open("sd.dat",ios::binary|ios::in);
    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.getRoll()==n)
        {
            s.show();
            flag=1;
        }
    }
    file.close();
    if(flag==0)
    {
        cout<<"\n\tRecord does not Exist!!!"<<endl;
    }
}
void ModifyStudent()
{
    int c;
    int found=0;
    cout<<"Enter Roll no that u want to update : ";
    cin>>c;
    file.open("sd.dat",ios::in|ios::out);
    while(file.read((char*)&s,sizeof(Student)) && found==0)
    {
        if(s.getRoll()==c)
        {
            s.show();
            // \n\t for the new line and a Tab after the Previous Results are been Displayed...
            cout<<"\n\t\t**** MODIFYING SECTION ****"<<endl;
            cout<<"\n\tEnter NEW Details of Student : -  ";
            cout<<endl;
            s.SetData();
            int pos=-1*sizeof(Student);
            file.seekp(pos,ios::cur);
            file.write((char*)&s,sizeof(Student));
            cout<<"\n\n\t\tRecord updated!!"<<endl;
            found=1;
        }
    }
    file.close();
    if(found==0)
    {
        cout<<"Record Not Found!!!"<<endl;
    }
}
void DeleteStudent()
{
    int z;
    cout<<"Enter Roll no that u want Delete : ";
    cin>>z;
    file.open("sd.dat",ios::in|ios::out);
    int flag=-1;
    fstream n;
    n.open("rep.dat",ios::out);
    file.seekg(0,ios::beg);
    while(file.read((char*)&s,sizeof(Student)))
    {
        if(s.getRoll()!=z)
        {
            n.write((char*)&s,sizeof(Student));
            flag=0;
        }
        
    }
    n.close();
    file.close();
    remove("sd.dat");
    rename("rep.dat","sd.dat");
    if(flag==-1)
    {
        cout<<"Student is not in the record!!.....So can't be Deleted!!"<<endl;
    }
    else
    {
        cout<<"Record Deleted!!"<<endl;
    }
}

int main()
{
    int w;
    cout<<"\n\n\t\t\t\t***Welcome to Student Record System ***"<<endl;
    while(1)
    {
       
       
        cout<<"\n\n\t1]CREATE STUDENT RECORD";
        cout<<"\n\n\t2]DISPLAY ALL STUDENTS RECORDS";
        cout<<"\n\n\t3]SEARCH STUDENT RECORD ";
        cout<<"\n\n\t4]MODIFY STUDENT RECORD";
        cout<<"\n\n\t5]DELETE STUDENT RECORD";
        
        
        cout<<"\n\n\tPlease Enter Your Choice (1-6): ";
        cin>>w;
        cout<<endl;
        switch(w)
        {
            case 1:
                DataInFile();                   // Function for Creating a Student Record...
                break;
            case 2:
                Display_all_student();              // Founction Call for Displaying all students record...
                break;
            case 3:
                int num;
                cout<<"Enter Roll No that u want to search : ";
                cin>>num;
                DisplaySearchByRoll(num);               // Display particular Student Record using Roll NO...
                break;
            case 4:
                ModifyStudent();                    // to modify Record....
                break;
            case 5:
                DeleteStudent();                    // to delete a particular Student's Record...
                break;
           
                
            default:
                cout<<"Invalid option selected!!....Please select Valid option!!"<<endl;         
        }
    }
    return 0;
}
