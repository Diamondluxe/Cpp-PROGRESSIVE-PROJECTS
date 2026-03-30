// MINI ATM MACHINE 
//Simulates ATM operations including login authentication, balance checking, deposit, withdrawl, and menu handling
#include<iostream>
using namespace std;

void login();
void menu(double &balance);
void deposit(double &balance);
void withdraw(double &balance);

int main(){
    double balance=15000;

    cout<<"\n\n ******** WELCOME TO OUR LUXURY ATM ********"<<endl;
    cout<<"\n System status: Slightly happier after seeing you :)"<<endl;

    login();

    menu(balance);

    return 0;   
}


void login(){
    int pin;
    int attempts=0;

    while(attempts<3)
    {
        cout<<"\nEnter Your pin Cutieee: ";
        cin>>pin;

        if(pin==5555)
        {
            cout<<"Login Successful * "<<endl;
            break;
        }
        else{
            cout<<"Incorrect PIN!"<<endl;
            attempts++;
        }

    }

    if(attempts==3)
    {
        cout<<"Too many incorrect attempts Miss. Your Card Blocked!"<<endl;
        exit(0);
    }
}


void menu(double &balance){
    int choice;
    do{
        
        cout<<"\n***** Options For YOU! *****\n"<<endl;
        cout<<"1. Check Balance"<<endl;
        cout<<"2. Deposit Money"<<endl;
        cout<<"3. Withdraw Money"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"\nEnter Your choice Cutie: ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"Your Currect Balance is: "<<balance<<endl;
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                cout<<"\nThank YOU for using DIAMOND LUXE's ATM ^-^"<<endl;
                cout<<"You're officially my favorite visitor today."<<endl;
                cout<<"Take care and keep smiling Cutie.\n\n"<<endl;
                break;
            default:
                cout<<"Invalid Choice! \n Wear Your Glasses then TRY AGAIN!"<<endl;
                break;
        }
    }while(choice!=4);

}

void deposit(double &balance){
    double deposit;
    cout<<"Enter amount to deposit: ";
    cin>>deposit;
    balance+=deposit;
    cout<<"Deposit Successful!"<<endl;
}

void withdraw(double &balance){
    double withdraw;
    cout<<"Enter amount to withdraw: ";
    cin>>withdraw;
    if(withdraw <= balance)
    {
        balance -= withdraw;
        cout<<"Withdrawal successful."<<endl;
        cout<<"Remaining Amount: "<<balance<<endl;
    }
    else{
        cout<<"Insufficient Amount"<<endl;
    }
}