#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "1 add item" << endl;
        cout << "2 view all items" << endl;
        cout << "3 search item by name" << endl;
        cout << "4 exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            ofstream file("inventory.txt", ios::app);

            if(!file)
            {
                cout << "error opening file" << endl;
                continue;
            }

            string name;
            int quantity;
            float price;

            cout << "enter item name: ";
            cin >> name;

            cout << "enter quantity: ";
            cin >> quantity;

            cout << "enter price: ";
            cin >> price;

            file << name << " " << quantity << " " << price << endl;

            file.close();
        }
        else if(choice == 2)
        {
            ifstream file("inventory.txt");

            if(!file)
            {
                cout << "error opening file" << endl;
                continue;
            }

            string name;
            int quantity;
            float price;

            cout << "items:" << endl;

            while(file >> name >> quantity >> price)
            {
                cout << name << " " << quantity << " " << price << endl;
            }

            file.close();
        }
        else if(choice == 3)
        {
            ifstream file("inventory.txt");

            if(!file)
            {
                cout << "error opening file" << endl;
                continue;
            }

            string searchname;
            cout << "enter item name to search: ";
            cin >> searchname;

            string name;
            int quantity;
            float price;
            int found = 0;

            while(file >> name >> quantity >> price)
            {
                if(name == searchname)
                {
                    cout << name << " " << quantity << " " << price << endl;
                    found = 1;
                }
            }

            if(found == 0)
                cout << "item not found" << endl;

            file.close();
        }

    } while(choice != 4);

    cout << "this code is developed by 25ce011";

    return 0;
}