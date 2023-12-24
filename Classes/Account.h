#pragma once

class Account
{
private:
    int account_number;
    char name[50];
    int deposit;
    char type;
public:
    Account();
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
