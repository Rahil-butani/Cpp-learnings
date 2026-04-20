#include <iostream>
using namespace std;

class Wallet {
private:
    int walletID;
    string userName;
    double balance;

public:

    Wallet(int id = 0, string name = "", double bal = 0) {
        walletID = id;
        userName = name;
        balance = bal;
    }


    void createWallet() {
        cout << "Enter Wallet ID: ";
        cin >> walletID;
        cout << "Enter User Name: ";
        cin >> userName;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }


    void loadMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Money loaded successfully.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }


    void transferMoney(Wallet &receiver, double amount) {
        if (amount <= 0) {
            cout << "Invalid transfer amount.\n";
        }
        else if (amount > balance) {
            cout << "Error: Insufficient balance.\n";
        }
        else {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful.\n";
        }
    }


    void display() {
        cout << "\nWallet ID: " << walletID << endl;
        cout << "User Name: " << userName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Wallet w1, w2;
    int choice;
    double amount;

    cout << "Create Wallet 1:\n";
    w1.createWallet();

    cout << "\nCreate Wallet 2:\n";
    w2.createWallet();

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Load Money (Wallet 1)\n";
        cout << "2. Load Money (Wallet 2)\n";
        cout << "3. Transfer from Wallet 1 to Wallet 2\n";
        cout << "4. Transfer from Wallet 2 to Wallet 1\n";
        cout << "5. Display Wallets\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount: ";
            cin >> amount;
            w1.loadMoney(amount);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amount;
            w2.loadMoney(amount);
            break;

        case 3:
            cout << "Enter amount: ";
            cin >> amount;
            w1.transferMoney(w2, amount);
            break;

        case 4:
            cout << "Enter amount: ";
            cin >> amount;
            w2.transferMoney(w1, amount);
            break;

        case 5:
            w1.display();
            w2.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
