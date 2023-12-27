#include "Classes/Account.h"
#include "Functions/AccountFunction.h"

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

void write_account();
void display_detail(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();

int main()
{
    char ch;
    int num;
    void intro();
    do
    {
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
			cout<<"\n\n\tEnter the account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter the account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\n\tEnter the account No. : "; cin>>num;
			display_detail(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter the account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter the account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\tThanks for using mini-bank system";
			break;
        default:cout<<"\a";
            break;
        }
        cin.ignore();
        cin.get();
    }while (ch!='8');
    return 0;  
}