#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;


class account
{
private:
    int account_number;
    char name[50];
    int deposit;
    char type;
public:
    void create_account();
    void show_account() const;
    void modify();
    void deposit_account(int);
    void withdraw_account(int);
    void report() const;
    int return_account_number() const;
    int return_deposit() const;
    char return_type() const;

};

void account::create_account()
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

void account::show_account() const
{
    cout<<"\nAccount No. : ";
    cout<<"\nAccount holder name : ";
    cout<<name;
    cout<<"\nType of account : "<<type;
    cout<<"\nBalance amount : "<<deposit;
}

void account::modify()
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

void account::deposit_account(int x)
{
    deposit+=x;
}

void account::withdraw_account(int x)
{
    deposit-=x;
}

void account::report() const
{
    cout<<account_number<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int account::return_account_number() const
{
    return account_number;
}

int account::return_deposit() const
{
    return deposit;
}

char account::return_type() const
{
    return type;
}

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

void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary|ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
    outFile.close();
}

void display_detail(int n)
{
    account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if(!inFile)
    {
        cout<<"File could not be opened !! Press any key...";
        return;
    }
    cout<<"\nBalance Details\n";

    while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)));
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
    account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any key...";
        return;
    }
    while (!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
        if(ac.return_account_number()==n)
        {
            ac.show_account();
            cout<<"\n\nEnter the new details of the account"<<endl;
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
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
    account ac;
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
    while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)));
    {
        if(ac.return_account_number()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
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
    account ac;
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
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();

}

void deposit_withdraw(int n, int option)
{
    int amt;
    bool found=false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
		return;
    }
    while (!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(account));
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
            File.write(reinterpret_cast<char *> (&ac), sizeof(account));
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