#include <iostream>
using namespace std;

class Item {
private:
    int itemID;
    string name;
    double price;
    int quantity;

public:

    Item() {
        itemID = 0;
        name = "None";
        price = 0;
        quantity = 0;
    }


    Item(int id, string n, double p, int q) {
        itemID = id;
        name = n;
        price = p;
        quantity = q;
    }


    void setItem() {
        cout << "Enter Item ID: ";
        cin >> itemID;
        cout << "Enter Item Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }


    void addStock(int qty) {
        if (qty > 0) {
            quantity += qty;
            cout << "Stock added successfully.\n";
        } else {
            cout << "Invalid quantity!\n";
        }
    }


    void sellItem(int qty) {
        if (qty <= 0) {
            cout << "Invalid quantity!\n";
        }
        else if (qty > quantity) {
            cout << "Error: Not enough stock available.\n";
        }
        else {
            quantity -= qty;
            cout << "Item sold successfully.\n";
        }
    }


    void display() {
        cout << "\nItem ID: " << itemID << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    int getID() {
        return itemID;
    }
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];


    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Item " << i + 1 << endl;
        items[i].setItem();
    }

    int choice, id, qty, i;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Add Stock\n";
        cout << "2. Sell Item\n";
        cout << "3. Display One Item\n";
        cout << "4. Display All Items\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter quantity to add: ";
            cin >> qty;

            for (i = 0; i < n; i++) {
                if (items[i].getID() == id) {
                    items[i].addStock(qty);
                    break;
                }
            }
            if (i == n) cout << "Item not found!\n";
            break;

        case 2:
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter quantity to sell: ";
            cin >> qty;

            for (i = 0; i < n; i++) {
                if (items[i].getID() == id) {
                    items[i].sellItem(qty);
                    break;
                }
            }
            if (i == n) cout << "Item not found!\n";
            break;

        case 3:
            cout << "Enter Item ID: ";
            cin >> id;

            for (i = 0; i < n; i++) {
                if (items[i].getID() == id) {
                    items[i].display();
                    break;
                }
            }
            if (i == n) cout << "Item not found!\n";
            break;

        case 4:
            for (i = 0; i < n; i++) {
                items[i].display();
            }
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
