#include <iostream>
using namespace std;

class Item {
private:
    int itemID;
    string name;
    float price;
    int quantity;

public:

    Item() {
        itemID = 0;
        name = "None";
        price = 0.0;
        quantity = 0;
    }

    Item(int id, string n, float p, int q) {
        itemID = id;
        name = n;
        price = p;
        quantity = q;
    }


    void addStock(int q) {
        quantity += q;
        cout << "Stock added successfully!\n";
    }


    void sellItem(int q) {
        if (q <= quantity) {
            quantity -= q;
            cout << "Item sold successfully!\n";
        } else {
            cout << "Not enough stock available!\n";
        }
    }


    void display() {
        cout << "\nItem ID: " << itemID;
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
        cout << "\nQuantity: " << quantity << endl;
    }

    int getID() {
        return itemID;
    }
};

int main() {
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[50];

    for (int i = 0; i < n; i++) {
        int id, qty;
        float price;
        string name;

        cout << "\nEnter details for item " << i + 1 << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> qty;

        items[i] = Item(id, name, price, qty);
    }

    int choice;
    do {
        cout << "\n--- Inventory Menu ---";
        cout << "\n1. Display all items";
        cout << "\n2. Add stock";
        cout << "\n3. Sell item";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < n; i++) {
                items[i].display();
            }
        }

        else if (choice == 2) {
            int id, qty;
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter quantity to add: ";
            cin >> qty;

            for (int i = 0; i < n; i++) {
                if (items[i].getID() == id) {
                    items[i].addStock(qty);
                }
            }
        }

        else if (choice == 3) {
            int id, qty;
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter quantity to sell: ";
            cin >> qty;

            for (int i = 0; i < n; i++) {
                if (items[i].getID() == id) {
                    items[i].sellItem(qty);
                }
            }
        }

    } while (choice != 4);

    return 0;
}
