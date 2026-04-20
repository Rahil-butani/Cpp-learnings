#include <iostream>
using namespace std;

class Account {
private:
    int accountID;
    string name;
    double balance;

public:

    void createAccount() {
        cout << "Enter Account ID: ";
        cin >> accountID;
        cout << "Enter Customer Name: ";
        cin >> name;

        cout << "Enter Initial Balance (0 or more): ";
        cin >> balance;

        if (balance < 0) {
            balance = 0;
            cout << "Invalid amount! Balance set to 0.\n";
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        }
        else if (amount > balance) {
            cout << "Error: Insufficient balance (No overdraft allowed).\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }

    void display() {
        cout << "\nAccount ID: " << accountID << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Current Balance: " << balance << endl;
    }

    int getID() {
        return accountID;
    }
};

int main() {
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    Account acc[n];

    for (int i = 0; i < n; i++) {
        cout << "\nCreate Account " << i + 1 << endl;
        acc[i].createAccount();
    }

    int choice, id, i;
    double amount;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account\n";
        cout << "4. Display All Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            for (i = 0; i < n; i++) {
                if (acc[i].getID() == id) {
                    acc[i].deposit(amount);
                    break;
                }
            }
            if (i == n) cout << "Account not found!\n";
            break;

        case 2:
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            for (i = 0; i < n; i++) {
                if (acc[i].getID() == id) {
                    acc[i].withdraw(amount);
                    break;
                }
            }
            if (i == n) cout << "Account not found!\n";
            break;

        case 3:
            cout << "Enter Account ID: ";
            cin >> id;

            for (i = 0; i < n; i++) {
                if (acc[i].getID() == id) {
                    acc[i].display();
                    break;
                }
            }
            if (i == n) cout << "Account not found!\n";
            break;

        case 4:
            for (i = 0; i < n; i++) {
                acc[i].display();
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
