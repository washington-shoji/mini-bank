#include "../Classes/Account.h"
#include<iostream>
#include<fstream>
using namespace std;



void write_account()
{
    Account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary|ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
    outFile.close();
}

void display_detail(int n)
{
    Account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile)
    {
        cout<<"File could not be opened !! Press any key...";
        return;
    }
    cout<<"\nBalance Details\n";

    while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)));
    {
       if(ac.return_account_number()==n)
       {
        ac.show_account();
        flag=true;
       }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nAccount number does not exist";
    
}

void modify_account(int n)
{
    bool found=false;
    Account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any key...";
        return;
    }
    while (!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.return_account_number()==n)
        {
            ac.show_account();
            cout<<"\n\nEnter the new details of the account"<<endl;
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(Account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout<<"\n\n\t Record updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record not found";
    
}

void delete_account(int n)
{
    Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be opened !! Press any key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)));
    {
        if(ac.return_account_number()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\n\tRecord deleted...";
    
}

void display_all()
{
    Account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be opened !! Press any key...";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
	{
		ac.report();
	}
	inFile.close();

}

void deposit_withdraw(int n, int option)
{
    int amt;
    bool found=false;
    Account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
		return;
    }
    while (!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.return_account_number()==n)
        {
            ac.show_account();
            if(option==1)
            {
                cout<<"\n\n\tTO DEPOSIT AMOUNT ";
				cout<<"\n\nEnter the amount to be deposited";
				cin>>amt;
				ac.deposit_account(amt);
            }
            if(option==2)
            {
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter the amount to be withdraw";
				cin>>amt;
				int bal=ac.return_deposit()-amt;
				if((bal<500 && ac.return_type()=='S') || (bal<1000 && ac.return_type()=='C'))
					cout<<"Insufficient balance";
				else
					ac.withdraw_account(amt);
            }
            int pos=(-1)*static_cast<int>(sizeof(ac));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout<<"\n\n\t Record updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record not found";
    
}

void intro()
{
    cout<<"\n\n\n\t  MINI";
	cout<<"\n\n\tBANK";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : A DEVELOPER";
	cout<<"\n\nORG : NICE CODING";
	cin.get();
}