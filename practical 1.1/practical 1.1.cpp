#include <iostream>
#include <string>
using namespace std;

class wallet
{
private:
    int wallet_id;
    string username;
    float balance;

public:
    void createWallet()
    {
        cout << "\nEnter Wallet ID : ";
        cin >> wallet_id;
        cout << "Enter Username  : ";
        cin >> username;
        balance = 0;
    }

    void deposit(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Money loaded successfully!\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void transferMoney(wallet &w, float amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            w.balance += amount;
            cout << "Transfer successful!\n";
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    void display()
    {
        cout << "\n------ Wallet Details ------\n";
        cout << "Wallet ID : " << wallet_id << endl;
        cout << "Username  : " << username << endl;
        cout << "Balance   : " << balance << endl;
        cout << "---------------------------\n";
    }
};

int main()
{
    wallet w1, w2;
    int choice;
    float amount;

    cout << "\nCreate Wallet 1\n";
    w1.createWallet();

    cout << "\nCreate Wallet 2\n";
    w2.createWallet();

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Load Money into Wallet 1\n";
        cout << "2. Transfer Wallet 1 to Wallet 2\n";
        cout << "3. Transfer Wallet 2 to Wallet 1\n";
        cout << "4. Display Wallet 1\n";
        cout << "5. Display Wallet 2\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter amount: ";
            cin >> amount;
            w1.deposit(amount);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amount;
            w1.transferMoney(w2, amount);
            break;

        case 3:
            cout << "Enter amount: ";
            cin >> amount;
            w2.transferMoney(w1, amount);
            break;

        case 4:
            w1.display();
            break;

        case 5:
            w2.display();
            break;

        case 6:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
    cout<<"This Program is made by Angel bavarva 25CE00";
}
