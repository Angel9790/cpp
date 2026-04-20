#include <iostream>
using namespace std;

class BankAccount
{
public:
    int accNo;
    string name;
    double balance;

    static int totalAccounts;

    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accNo;

        cout << "Enter Account Holder Name: ";
        cin >> name;

        cout << "Enter Balance: ";
        cin >> balance;

        totalAccounts++;
    }

    void display()
    {
        cout << "\nAccount Number: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int BankAccount::totalAccounts = 0;

int main()
{
    int n;

    cout << "Enter number of accounts: ";
    cin >> n;

    BankAccount acc[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details for account " << i+1 << endl;
        acc[i].createAccount();
    }

    cout << "\n--- Account Details ---\n";

    for(int i = 0; i < n; i++)
    {
        acc[i].display();
    }

    cout << "\nTotal Accounts Created: " << BankAccount::totalAccounts;

    return 0;
}
