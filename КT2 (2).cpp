#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый класс BankAccount
class BankAccount {
protected:
    string ownerName;
    string accountNumber;
    double balance;

    bool isValidAmount(double amount) const {
        return amount > 0;
    }

public:
    BankAccount(const string& owner, const string& number, double initialBalance)
        : ownerName(owner), accountNumber(number), balance(initialBalance) {
    }

    virtual void deposit(double amount) {
        if (isValidAmount(amount)) {
            balance += amount;
        }
    }

    virtual bool withdraw(double amount) {
        if (isValidAmount(amount) && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    virtual void displayInfo() const {
        cout << "Owner: " << ownerName << ", Account: " << accountNumber << ", Balance: " << balance << endl;
    }

    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }
};

// Производный класс SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& owner, const string& number, double initialBalance, double rate)
        : BankAccount(owner, number, initialBalance), interestRate(rate) {
    }

    void deposit(double amount) override {
        if (isValidAmount(amount)) {
            balance += amount + (amount * interestRate / 100);
        }
    }

    void displayInfo() const override {
        BankAccount::displayInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Перегруженная функция processTransaction
void processTransaction(BankAccount& account) {
    account.deposit(1000);
    cout << "Deposited 1000 to account " << account.getAccountNumber() << endl;
}

void processTransaction(BankAccount& from, BankAccount& to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        cout << "Transferred " << amount << " from account " << from.getAccountNumber()
            << " to account " << to.getAccountNumber() << endl;
    }
    else {
        cout << "Transfer failed." << endl;
    }
}

int main() {
    BankAccount regularAccount("Aleksandr Petrov", "123456", 5000);
    SavingsAccount savingsAccount("Vladik Sedoi", "654321", 10000, 5.0);

    vector<BankAccount*> accounts = { &regularAccount, &savingsAccount };

    for (BankAccount* account : accounts) {
        account->displayInfo();
    }

    processTransaction(regularAccount);
    processTransaction(savingsAccount);

    processTransaction(regularAccount, savingsAccount, 2000);

    for (BankAccount* account : accounts) {
        account->displayInfo();
    }

    if (regularAccount > savingsAccount) {
        cout << "Regular account has a larger balance." << endl;
    }
    else {
        cout << "Savings account has a larger balance." << endl;
    }

    return 0;
}
