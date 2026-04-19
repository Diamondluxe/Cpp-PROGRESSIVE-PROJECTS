//School Management System

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

class Person
{
    protected:
        string name, faculty;
        int id, age;
    public:
        virtual void getdata()=0;
        virtual void showdata()=0;
};

class Student:public Person{
    private:
        float gpa;
    public:
        void getdata()override
        {
            cout<<"Enter Student ID: ";
            cin>>id;
            cin.ignore();
            cout<<"Enter Student Name: ";
            getline(cin,name);
            cin.ignore();
            cout<<"Enter Student Faculty: ";
            getline(cin,faculty);
            cout<<"Enter Student Age: ";
            cin>>age;
            cout<<"Enter Student GPA: ";
            cin>>gpa;
        }

        void showdata()override
        {
            cout<<left<<setw(10)<<id<<setw(15)<<name<<setw(15)<<faculty<<setw(10)<<age<<setw(10)<<gpa<<endl;
        }

        int getid()  {return id;}
        string getname() {return name;}
        string getfaculty() {return faculty;}
        int getage() {return age;}
        int getgpa() {return gpa;}

};

class Teacher:public Person{
    private:
        int salary;
    public:
        void getdata()override
        {
            cout<<"Enter Teacher ID: ";
            cin>>id;
            cin.ignore();
            cout<<"Enter Teacher Name: ";
            getline(cin,name);
            cin.ignore();
            cout<<"Enter Teacher Faculty: ";
            getline(cin,faculty);
            cout<<"Enter Teacher Age: ";
            cin>>age;
            cout<<"Enter Teacher Salary: ";
            cin>>salary;
        }

        void showdata()override
        {
            cout<<left<<setw(10)<<id<<setw(15)<<name<<setw(15)<<faculty<<setw(10)<<age<<setw(10)<<salary<<endl;
        }

        int getid()  {return id;}
        string getname() {return name;}
        string getfaculty() {return faculty;}
        int getage() {return age;}
        int getsalary() {return salary;}
};

class SchoolManager{
    public:
        void savestudent(Student &s)
        {
            ofstream sout("Text-File/StudentRecord.txt", ios::app);
            if(!sout)
            {
                cout<<"\nFile opening error! Skip the coffeee ^-^ and Check your File explorer "<<endl;
            }
            else{
                sout<<s.getid()<<","<<s.getname()<<","<<s.getfaculty()<<","<<s.getage()<<","<<s.getgpa()<<endl;
                cout<<"Congrats! Student Data uploaded to Lunar Server.."<<endl;
                sout.close();
            }
            
        }

        void saveteacher(Teacher &t)
        {
            ofstream tout("Text-File/TeacherRecord.txt", ios::app);
            if(!tout)
            {
                cout<<"File opening error! Skip the coffeee ^-^ and Check your File explorer "<<endl;
            }
            else{
                tout<<t.getid()<<","<<t.getname()<<","<<t.getfaculty()<<","<<t.getage()<<","<<t.getsalary()<<endl;
                cout<<"Congrats! Teacher Data uploaded to Lunar Server.."<<endl;
                tout.close();
            }
            
        }

        void displaystudent()
        {
            cout<<"\nConnecting to LUNA Server for Records....Wait!"<<endl<<endl;
  
             ifstream sin("Text-File/StudentRecord.txt");
            if(!sin)
            {
                cout<<"File opening error! Skip the coffee ^-^ and Check you File explorer first.."<<endl;
            }
            else{
                cout<<setw(60)<<"\n--DIAMOND LUXE STUDENT RECORDS--"<<endl;
                cout<<left<<setw(10)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"FACULTY"<<setw(10)<<"AGE"<<setw(10)<<"GPA"<<endl;
                string n,f;
                int id,a;
                float g;
                while(sin>>id)
                {
                    sin.ignore();
                    getline(sin,n,',');
                    getline(sin,f,',');
                    sin>>a;
                    sin.ignore();
                    sin>>g;
                    cout<<left<<setw(10)<<id<<setw(15)<<n<<setw(15)<<f<<setw(10)<<a<<setw(10)<<g<<endl;

                }
                sin.close();
                
            }
            
        }

         void displayteacher()
        { 
            cout<<"\nConnecting to LUNA Server for Records....Wait!"<<endl<<endl;

              ifstream tin("Text-File/TeacherRecord.txt");
            if(!tin)
            {
                cout<<"File opening error! Skip the coffee ^-^ and Check you File explorer first.."<<endl;
            }
            else{
                cout<<setw(60)<<"\n--DIAMOND LUXE TEACHER RECORDS--"<<endl;
                cout<<left<<setw(10)<<"ID"<<setw(15)<<"NAME"<<setw(15)<<"FACULTY"<<setw(10)<<"AGE"<<setw(10)<<"SALARY"<<endl;
                string n,f;
                int id,a,s;
                while(tin>>id)
                {
                    tin.ignore();
                    getline(tin,n,',');
                    getline(tin,f,',');
                    tin>>a;
                    tin.ignore();
                    tin>>s;
                    cout<<left<<setw(10)<<id<<setw(15)<<n<<setw(15)<<f<<setw(10)<<a<<setw(10)<<s<<endl;

                }
                tin.close();
                
            }
            
        }
};


int main()
{
    cout<<"\n\nWELCOME TO OUR LUXURY DIAMOND LUXE ACADEMY"<<endl;
    cout<<"Location: At Luna valley area of Moon"<<endl<<endl;
    cout<<"System status: Slightly happier after seeing you :)"<<endl;
    

    SchoolManager SM;
    Teacher T;
    Student S;
    int choice;
    do
    {
        cout<<"\n---Oprions for YOU:---"<<endl;
        cout<<"1. Add New Student"<<endl;
        cout<<"2. Add New Teacher"<<endl;
        cout<<"3. Display Student Records"<<endl;
        cout<<"4. Display Teacher Records"<<endl;
        cout<<"5. Exit."<<endl<<endl;
        cout<<"\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout<<"Tell the info of Lucky kid: "<<endl;
                S.getdata();
                SM.savestudent(S);
                break;
            case 2:
                cout<<"Tell the info of Lucky Teacher: "<<endl;
                T.getdata();
                SM.saveteacher(T);
                break;
            case 3:
                SM.displaystudent();
                break;
            case 4:
                SM.displayteacher();
                break;
            case 5:
                cout<<"Exiting the program..."<<endl;
                break;
            default:
                cout<<"Really! You can see this option Bravoo.. Try Again Kindly!"<<endl;
                break;
        }
    }while(choice!=5);


    cout<<"\nThank You for Visiting DIAMOND LUXE ACADEMY"<<endl;
    cout<<"You have such a nice taste.. Have a nice day ^-^\n\n"<<endl;
    return 0; 
}