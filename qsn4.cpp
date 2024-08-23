/*
Create a base class Account with data members accountNumber and balance.
Derive two classes SavingsAccount and CheckingAccount from Account.
Implement polymorphic behavior where the base class pointer can point to objects of
derived classes, and call their respective member functions to deposit and withdraw
money, applying specific rules for each account type.
*/

#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient balance in account " << accountNumber << endl;
        }
    }

    virtual void displayBalance() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, double rate) 
        : Account(accNum, bal), interestRate(rate) {}

    void deposit(double amount) override {
        double interest = amount * (interestRate / 100);
        balance += (amount + interest);
        cout << "Deposited " << amount << " with interest " << interest 
             << " into savings account " << accountNumber << endl;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << " from savings account " << accountNumber << endl;
        } else {
            cout << "Insufficient balance in savings account " << accountNumber << endl;
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, double limit) 
        : Account(accNum, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << " from checking account " << accountNumber << endl;
        } else {
            cout << "Exceeded overdraft limit in checking account " << accountNumber << endl;
        }
    }
};

int main() {
    int accNum;
    double bal, rate, limit;
    int accountType;

    cout << "Enter the type of account (1 for SavingsAccount, 2 for CheckingAccount): ";
    cin >> accountType;

    cout << "Enter account number: ";
    cin >> accNum;

    cout << "Enter initial balance: ";
    cin >> bal;

    Account* acc = nullptr;

    if (accountType == 1) {
        cout << "Enter interest rate: ";
        cin >> rate;
        acc = new SavingsAccount(accNum, bal, rate);
    } else if (accountType == 2) {
        cout << "Enter overdraft limit: ";
        cin >> limit;
        acc = new CheckingAccount(accNum, bal, limit);
    } else {
        cout << "Invalid account type!" << endl;
        return 1;
    }

    int choice;
    double amount;

    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc->deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc->withdraw(amount);
                break;
            case 3:
                acc->displayBalance();
                break;
            case 4:
                delete acc;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
