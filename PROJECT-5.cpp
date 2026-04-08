// Employee Payroll System
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Employee
{
    int id;
    string name;
    string designation;
    float baseSalary;
    float netSalary;    
};

// Function to calculate net salary based on base salary, allowance, and tax
void calculateSalary(Employee *emp) {
    cout<<"Enter Base Salary: ";
    cin>>emp->baseSalary;
    float allowance = emp->baseSalary * 0.10; // 10% allowance
    float tax = emp->baseSalary * 0.05;      // 5% tax
    emp->netSalary = (emp->baseSalary + allowance) - tax;
    cout<<"Net Salary calculated is: " << emp->netSalary << endl;
}

// Function to add employee details and save to file
void addEmployee(Employee *emp)
{
    cout<<"\n\n---Enter Employee Details---"<<endl;
    cout<<"Enter ID: "; 
    cin>>emp->id;
      cin.ignore(); // Ignore the newline character left in the input buffer
    cout<<"Enter Name: ";  
    getline(cin, emp->name);
    cout<<"Enter Designation: ";
    getline(cin, emp->designation);
    
    calculateSalary(emp); //Calculate net salary before saving to file

    ofstream outFile("employee.txt", ios::app); //Open file in append mode
    if(!outFile)
    {
        cout<<"Error opening file!"<<endl;
        return;
    }
    outFile<<emp->id<<"\n"<<emp->name<<"\n"<<emp->designation<<"\n"<<emp->baseSalary<<"\n"<<emp->netSalary<<endl; //Write employee details to file
    outFile.close(); //Close the file

}

// Function to display employee details from file
void displayEmployee()
{
    ifstream inFile("employee.txt"); //Open file to read employee details
    if(!inFile)
    {
        cerr<<"Error opening file!"<<endl;
        return;
    }
    cout<<"\n\n---Employee Details---"<<endl;
    cout<<left<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Designation"<<setw(15)<<"Base Salary"<<setw(15)<<"Net Salary"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    Employee emp;
    while(inFile>>emp.id) //Read employee details from file
    {
        
        inFile.ignore(); 
        getline(inFile, emp.name);
        getline(inFile, emp.designation);
        inFile >> emp.baseSalary;
        inFile >> emp.netSalary;
       // inFile.ignore(); // Clean up the newline for the next loop

        cout<<left<<setw(10)<<emp.id<<setw(20)<<emp.name<<setw(20)<<emp.designation<<setw(15)<<emp.baseSalary<<setw(15)<<emp.netSalary<<endl; //Display employee details
    }
    inFile.close(); //Close the file
}

int main()
{
    Employee emp; //Create an instance of Employee structure
    int choice;

     cout<<"\n\n **** WELCOME TO OUR LUXURY EMPLOYEE PAYROLL SYSTEM ****"<<endl;
    cout<<"\n System status: Feeling more productive already! :)"<<endl<<endl;
    do{
         cout<<"\n---Oprions for YOU:---"<<endl;
        cout<<"1. Add Employee Details"<<endl;
        cout<<"2. Calculate Net Salary"<<endl;
        cout<<"3. Display Employee Details"<<endl;
        cout<<"4. Exit"<<endl<<endl;
        cout<<"\nEnter your choice : ";
        cin >> choice;
        switch(choice) //Handle user choices with switch statement
        {
            case 1:
                cin.clear(); // Clear the input buffer before taking string input
                cin.ignore(); // Ignore the newline character left in the input buffer
                addEmployee(&emp); //Call function to add employee details
                break;
            case 2:
                calculateSalary(&emp); //Call function to calculate net salary
                cout<<"Net Salary calculated successfully!"<<endl;
                break;
            case 3:
                displayEmployee(); //Call function to display employee details
                break;
            case 4:
                cout<<"Exiting the program..."<<endl;
                break;
            default:
                cout<<"Really Madam? Please enter a valid choice!"<<endl;
                break;

        }
    }while(choice != 4); //Continue until user chooses to exit

    cout<<"\n\nThank you for using DIAMOND LUXE Employee-Payroll-System ^-^ \n Have a great day!"<<endl;
    
}