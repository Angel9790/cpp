#include <iostream>
#include <vector>
using namespace std;

// -------- Base Class --------
class Account {
protected:
    int accNumber;
    double balance;
    vector<double> history; // +ve deposit, -ve withdraw

public:
    // Constructor
    Account(int accNo, double bal) {
        accNumber = accNo;
        balance = bal;
        cout << "Account Created\n";
    }

    // Destructor
    ~Account() {
        cout << "Account Deleted\n";
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(amount);
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(-amount);
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient Balance\n";
        }
    }

    void undoTransaction() {
        if (!history.empty()) {
            double last = history.back();
            history.pop_back();
            balance -= last;  // reverse effect
            cout << "Last transaction undone\n";
        } else {
            cout << "No transaction to undo\n";
        }
    }

    void showHistory() {
        cout << "Transaction History:\n";
        for (double t : history) {
            if (t > 0)
                cout << "Deposit: " << t << endl;
            else
                cout << "Withdraw: " << -t << endl;
        }
    }

    void display() {
        cout << "Account No: " << accNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// -------- Savings Account --------
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, double bal, double rate)
        : Account(accNo, bal) {
        interestRate = rate;
    }

    void display() {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

// -------- Current Account --------
class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNo, double bal, double limit)
        : Account(accNo, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            history.push_back(-amount);
            cout << "Withdrawn (with overdraft): " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded\n";
        }
    }

    void display() {
        Account::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

// -------- MAIN FUNCTION --------
int main() {

    cout << "\n--- Savings Account ---\n";
    SavingsAccount s(101, 5000, 5);

    s.deposit(1000);
    s.withdraw(2000);
    s.display();
    s.showHistory();

    s.undoTransaction();
    s.display();

    cout << "\n--- Current Account ---\n";
    CurrentAccount c(201, 3000, 2000);

    c.deposit(500);
    c.withdraw(4000); // overdraft allowed
    c.display();
    c.showHistory();

    c.undoTransaction();
    c.display();

    return 0;
}
