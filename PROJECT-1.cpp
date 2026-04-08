// SMART STUDENT CALCULATOR SYSTEM
//Calculates total, average, percentage, and grade using user input, variables, and arithmetic operators.
#include <iostream>
using namespace std;
int main()
{
    string name; 
    int rollno; 
    float subj1,subj2,subj3,subj4,subj5; 
    float total, average, percentage; 
    char grade;

    cout<<"**SMART STUDENT CALCULATOR SYSTEM**"<<endl; //display the title of the program

    cout<<"Enter the name of the student : "; 
    cin>>name; //store the input from user in variable name

    cout<<"Enter the roll number of the student : "; 
    cin>>rollno; //store the input from user in variable rollno

    cout<<"Enter the marks of 5 subjects one by one : "<<endl; 
    cin>>subj1>>subj2>>subj3>>subj4>>subj5; //store the input from user in variables subj1, subj2, subj3, subj4, and subj5

    total = subj1+subj2+subj3+subj4+subj5; //calculate total by adding all the subject marks
    average = total/5; //calculate average by dividing total by 5
    percentage = (total/500)*100; //calculate percentage by dividing total by 500 and multiplying by 100

     // Grade Calculation
    if (percentage >= 80)
        grade = 'A';
    else if (percentage >= 70)
        grade = 'B';
    else if (percentage >= 60)
        grade = 'C';
    else if (percentage >= 50)
        grade = 'D';
    else
        grade = 'F';

    cout<<"**********RESULT**********"<<endl; //display the result title
    cout<<"Name: "<<name<<endl; //display name of the student
    cout<<"Roll Number: "<<rollno<<endl; //display roll number of the student
    cout<<"Total Marks: "<<total<<endl; //display total marks obtained by the student
    cout<<"Average Marks: "<<average<<endl; //display average marks obtained by the student
    cout<<"Percentage: "<<percentage<<"%"<<endl; //display percentage obtained by the student
    cout<<"Grade: "<<grade<<endl; //display grade obtained by the student

    return 0;
}

    