/*
 * Define a DebitAccount class to work with a debit bank account.
 * Each bank account must keep the user’s name and surname
 * (a string of max. 100 characters), an account number (long number)
 * and an instant balance (double). Write methods for reviewing the account,
 * depositing and withholding money from the account.
Then define a CreditAccount class that will allow
 the account user to take out a loan from the bank. A mechanism should be provided
 for calculating interest if the user owes money to the bank.*/

#include <iostream>
#include <cstring>

using namespace std;

class DebitAccount {
    char name[100];
    long int number;
    float balance;

public:
    DebitAccount(char *n="", long int num=0, float b=0.0) {
        strncpy(this->name, n, 99);
        this->name[99] = 0;
        this->number = num;
        this->balance = 0.0;
    }

    const char *getName() const {
        return name;
    }

    long getNumber() const {
        return number;
    }

    void setNumber(long number) {
        DebitAccount::number = number;
    }

    float getBalance() const {
        return balance;
    }

    void setBalance(float balance) {
        DebitAccount::balance = balance;
    }

    void showInfo() {
        cout << name << '\n'
             << "\t Bank No: "<< number << '\n'
             << "\t Balance: "<< getBalance() << '\n';
    }

    void deposit(float amount) {
        if (amount >= 0)
            this->balance+=amount;
        else
            cout << "You cannot deposit negative amount!\n";
    }

    void withdraw(float amount) {
        if (amount <= balance)
            balance -= amount;
        else {
            cout << "You can not withdraw more money than you have on your account.\n"
                 << "Please upgrade your debut account to credit account!"<<endl;
        }
    }

    ~DebitAccount() {}
};

class CreditAccount: public DebitAccount {
    double limit;
    double interest; // % percent
    double minus;

public:
    CreditAccount(char *name="", const long number=0,
                  const double balance=0, const double limit=1000,
                  const double interest=0.05, const double minus=0):
            DebitAccount(name, number, balance) {

        this->limit = limit;
        this->interest = interest;
        this->minus = minus;
    }

    void withdraw(float amount) {
        float balance = getBalance();

        if (amount <= balance)
            DebitAccount::withdraw(amount);

        else if (amount <= balance + limit - minus) {
            float advance = amount - balance;
            this->minus += advance * (1.0 + interest);

            cout<<"Minus: " << advance <<"\n"
                << "Minus with interest: " << advance*interest<<endl;

            deposit(advance);
            DebitAccount::withdraw(amount);
        } else {
            cout << "The bank is not giving you that much money..." << endl;
            this->showInfo();
        }
    }

    void showInfo() {
        DebitAccount::showInfo();
        cout<<"\t Limit: "<<this->limit << "\n"
            <<"\t In minus: " << this->minus << "\n"
            <<"\t Interest: " << this->interest << "%\n";
    }


    double getInterest() {
        return this->interest;;
    }

    ~CreditAccount() {}
};

int main() {
    DebitAccount d("Pero Perovski", 6, 100000);
    CreditAccount ca("Mitko Mitkovski", 10, 5000, 1000);
    d.showInfo();
    d.deposit(50000);
    d.withdraw(600000);
    d.showInfo();
    ca.showInfo();
    ca.deposit(500);
    ca.showInfo();
    ca.withdraw(6200);
    ca.showInfo();
    return 0;
}

