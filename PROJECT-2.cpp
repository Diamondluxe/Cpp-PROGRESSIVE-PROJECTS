// Implements username and password validation with limited login attempts using conditions and loops.
#include <iostream>
using namespace std;
int main()
{
    string name, password;
    string correctname = "Diamondluxe";
    string correctpassword = "diamond123";
    int attempts =0;
   
    cout<<"**WELCOME TO THE LOGIN SYSTEM**"<<endl; //display the title of the program
   
    while(attempts < 3)
    {
        cout<<"Enter username: ";
        cin>>name; //store the input from user in variable name
        cout<<"Enter password: ";
        cin>>password; //store the input from user in variable password 
       
        if(name == correctname && password == correctpassword) //check if the entered username and password are correct
        {
            cout<<"Login successful! Welcome " << name <<"."<<endl; //display success message with the username
            break; //exit the loop if login is successful
        }
       
        else
        {
            cout<<"Invalid username or password. Please try again."<<endl; //display error message
            attempts++; //increment attempts if login is unsuccessful
        }
    }

    if(attempts == 3) //check if the user has reached the maximum number of attempts
    {
        cout<<"Too many failed attempts. Accout locked!"<<endl;
    }
}