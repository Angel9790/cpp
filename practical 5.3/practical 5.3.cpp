#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item
{
private:
    char name[50];
    int quantity;
    float price;

public:
    void input()
    {
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;
    }

    void display()
    {
        cout << "Name: " << name
             << " | Quantity: " << quantity
             << " | Price: " << price << endl;
    }

    char* getName()
    {
        return name;
    }

    void writeToFile()
    {
        ofstream file("inventory.txt", ios::app);
        file << name << " " << quantity << " " << price << endl;
        file.close();
    }

    bool readFromFile(ifstream &file)
    {
        if (file >> name >> quantity >> price)
            return true;
        return false;
    }
};

int main()
{
    int choice;
    Item item;
    char searchName[50];

    do
    {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            item.input();
            item.writeToFile();
            cout << "Item added successfully!\n";
            break;

        case 2:
        {
            ifstream file("inventory.txt");
            cout << "\n--- All Items ---\n";
            while (item.readFromFile(file))
            {
                item.display();
            }
            file.close();
            break;
        }

        case 3:
        {
            cout << "Enter item name to search: ";
            cin >> searchName;

            ifstream file("inventory.txt");
            bool found = false;

            while (item.readFromFile(file))
            {
                if (strcmp(item.getName(), searchName) == 0)
                {
                    cout << "\nItem Found:\n";
                    item.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Item not found!\n";

            file.close();
            break;
        }

        case 4:
            cout << "Thank You ! \n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);
    cout<<"This Program is made by Angel Bavarva";
    return 0;
}
