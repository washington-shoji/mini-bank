#include <iomanip>
#include<iostream>
using namespace std;

#include "Account.h"



Account::Account(){}

void Account::create_account()
{
    cout<<"\nEnter the account No. :";
    cin>>account_number;
    cout<<"\n\nEnter the name of the account holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout<<"\nEnter type of account (C/S) : ";
    cin>>type;
    type=toupper(type);
    cout<<"\nEnter the initial amount(>=500 for saving and >=1000 for current) : ";
    cin>>deposit;
    cout<<"\n\n\nAccount created...";
}

void Account::show_account() const
{
    cout<<"\nAccount No. : ";
    cout<<"\nAccount holder name : ";
    cout<<name;
    cout<<"\nType of account : "<<type;
    cout<<"\nBalance amount : "<<deposit;
}

void Account::modify()
{
    cout<<"\nAccount No. : "<<account_number;
    cout<<"\nModify account holder name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout<<"\nModify type of account";
    cin>>type;
    type=toupper(type);
    cout<<"\nModify balance amount : ";
    cin>>deposit;
}

void Account::deposit_account(int x)
{
    deposit+=x;
}

void Account::withdraw_account(int x)
{
    deposit-=x;
}

void Account::report() const
{
    cout<<account_number<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int Account::return_account_number() const
{
    return account_number;
}

int Account::return_deposit() const
{
    return deposit;
}

char Account::return_type() const
{
    return type;
}
