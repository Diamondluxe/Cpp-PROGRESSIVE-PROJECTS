//Student Management system
//Stores multiple student records using arrays and fuctions withsearch and result calculation features

#include <iostream>
#include <string.h>
using namespace std;

struct Student{  //Structure to hold the data of a student
    int rollNo;
    string name;
    float marks[5];  //Array to hold the marks of 5 subjects
    float total;
    float percentage;
};

Student data[50]; //Array of 50 Student structures to hold the data of 50 students
int count=0;  //Gloabal variable count

void addRecord(){
    if(count<50)
    {
        cout<<"\n---Enter Student Details---"<<endl;
        cout<<"Roll No : ";
        cin>>data[count].rollNo; //Input roll number of the student
        cout<<"Name : ";
        cin.ignore(); //Ignore the newline character left in the input buffer
        getline(cin, data[count].name); //Input name of the student
        
        float sum=0; //Variable to hold the sum of marks
        for(int i=0; i<5; i++){
            cout<<"Marks in subject "<<i+1<<" : ";
            cin>>data[count].marks[i]; //Input marks of the student in each subject
            sum+=data[count].marks[i]; //Add the marks to sum
        }

        data[count].total = sum; //Calculate total marks and store in the structure
        data[count].percentage = (sum/500)*100; //Calculate percentage and store in

        count++; //Increment the count of students
        cout<<"\nMashaAllah, Record added Successfully!"<<endl;
    }
    else{
        cout<<"\nSorry, Maximum number of records reached!"<<endl;
    }
}

void searchRecord()
{
    int no;
    cout<<"Enter ROLL NO to search : ";
    cin>>no;

    bool found=false; //Variable to check if the record is found
    for(int i=0; i<count; i++){
        if(data[i].rollNo == no){ //Check if the roll number matches
            cout<<"\n---Student Details---"<<endl;
            cout<<"Roll No : "<<data[i].rollNo<<endl; //Display roll number
            cout<<"Name : "<<data[i].name<<endl; //Display name
            cout<<"Percentage : "<<data[i].percentage<<"%"<<endl; //Display percentage
            
            char choice;
            cout<<"Want to see marks in each subject? (y/n) : ";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){

                for(int j=0; j<5; j++){
                    cout<<"Marks in subject "<<j+1<<" : "<<data[i].marks[j]<<endl; //Display marks in each subject
                }
                cout<<"Total Marks : "<<data[i].total<<endl; //Display total marks
                cout<<"Percentage : "<<data[i].percentage<<"%"<<endl; //Display percentage
            }
            found=true; 
            break; 
        }
    }
    if(!found){
        cout<<"Record not found, Madam! "<<endl;
    }
}

int main()
{
     cout<<"\n\n **** WELCOME TO OUR LUXURY STUDENT RECORD MANAGEMENT SYSTEM ****";
    cout<<"\n System status: Slightly happier after seeing you :)"<<endl;
    int choice;
    do{
        cout<<"\n---Oprions for YOU:---"<<endl;
        cout<<"1. Add Record"<<endl;
        cout<<"2. Search Record"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                addRecord(); //Call function to add a new student record
                break;
            case 2:
                searchRecord(); //Call function to search for a student record
                break;
            case 3:
                cout<<"Exiting the program..."<<endl;
                break;
            default:
                cout<<"\nREALLy, You can see this option. Try again, MISS!"<<endl;
        }
    } while(choice != 3); //Continue until the user chooses to exit
    
    cout<<"\n\nThank you for using DIAMONDLUXE's SRMS ^-^!\n Have a great day, Miss!\n\n"<<endl;

    return 0;
}