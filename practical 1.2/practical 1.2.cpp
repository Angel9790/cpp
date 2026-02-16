#include <iostream>
#include <string>
using namespace std;

struct Library
{
    int book_id;
    string title;
    string author_name;
    int copies;
};

int main()
{
    Library book[20];
    int choice, i, id, n = 0;

    do
    {
        cout << "\nMENU";
        cout << "\n1. Add new book to the library";
        cout << "\n2. Issue a book";
        cout << "\n3. Return issued book";
        cout << "\n4. Display total books in the library";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter book id: ";
                cin >> book[n].book_id;

                cin.ignore();
                cout << "Enter title: ";
                getline(cin, book[n].title);

                cout << "Enter author name: ";
                getline(cin, book[n].author_name);

                cout << "Enter copies: ";
                cin >> book[n].copies;

                n++;
                break;

            case 2:
                cout << "Enter book id for issue: ";
                cin >> id;

                for(i = 0; i < n; i++)
                {
                    if(book[i].book_id == id)
                    {
                        if(book[i].copies > 0)
                        {
                            book[i].copies--;
                            cout << "Book issued successfully!\n";
                        }
                        else
                        {
                            cout << "Book not available\n";
                        }
                        break;
                    }
                }
                break;

            case 3:
                cout << "Enter book id for return: ";
                cin >> id;

                for(i = 0; i < n; i++)
                {
                    if(book[i].book_id == id)
                    {
                        book[i].copies++;
                        cout << "Book returned successfully!\n";
                        break;
                    }
                }
                break;

            case 4:
                cout << "\nId\tTitle\tAuthor\tCopies\n";
                for(i = 0; i < n; i++)
                {
                    cout << book[i].book_id << "\t"
                         << book[i].title << "\t"
                         << book[i].author_name << "\t"
                         << book[i].copies << endl;
                }
                break;

            case 5:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    }
    while(choice != 5);

    return 0;
}

