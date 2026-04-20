#include <iostream>
using namespace std;


string logs[100];
int logIndex = 0;

void addLog(string msg) {
    logs[logIndex++] = msg;
}

class BankAccount {
private:
    float balance;

public:

    BankAccount(float b) {
        balance = b;
        addLog("Constructor: Account created");
    }

    void deposit(float amount) {
        addLog("Entered deposit()");
        if (amount <= 0) {
            throw "Invalid deposit amount!";
        }
        balance += amount;
        addLog("Deposit successful");
        addLog("Exiting deposit()");
    }

    void withdraw(float amount) {
        addLog("Entered withdraw()");
        if (amount > balance) {
            throw "Insufficient balance!";
        }
        balance -= amount;
        addLog("Withdraw successful");
        addLog("Exiting withdraw()");
    }

    void display() {
        cout << "Current Balance: " << balance << endl;
    }
};

void performTransaction(BankAccount &acc) {
    addLog("Entered performTransaction()");

    float amt;
    int choice;

    cout << "\n1. Deposit\n2. Withdraw\nEnter choice: ";
    cin >> choice;

    cout << "Enter amount: ";
    cin >> amt;

    if (choice == 1) {
        acc.deposit(amt);
    } else if (choice == 2) {
        acc.withdraw(amt);
    }

    addLog("Exiting performTransaction()");
}

int main() {
    BankAccount acc(1000);

    try {
        addLog("Entered main()");
        performTransaction(acc);
        acc.display();
        addLog("Exiting main()");
    }

    catch (const char* msg) {
        addLog("Exception caught in main()");
        cout << "Exception: " << msg << endl;
    }

    cout << "\n--- Transaction Logs ---\n";
    for (int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    return 0;
}
