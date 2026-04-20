#include <iostream>
using namespace std;

class Account {
private:
    int accNo;
    string name;
    double balance;

    static int totalAccounts;

public:
    Account(int a, string n, double b) {
        accNo = a;
        name = n;
        balance = b;
        totalAccounts++;
    }

    static void showTotalAccounts() {
        cout << "Total Accounts Created: " << totalAccounts << endl;
    }

    int getAccNo() {
        return accNo;
    }

    void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    bool withdraw(double amt) {
        if (amt <= 0) {
            cout << "Invalid amount!\n";
            return false;
        }
        else if (amt > balance) {
            cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amt;
        return true;
    }

    void transfer(Account &receiver, double amt) {
        if (withdraw(amt)) {
            receiver.balance += amt;
            cout << "Transfer successful.\n";
        }
    }

    void updateName(string newName) {
        name = newName;
    }

    void display() {
        cout << "\nAccount No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int Account::totalAccounts = 0;

int main() {
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;


    Account** acc = new Account*[n];

    int accNo;
    string name;
    double bal;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Account " << i + 1 << endl;
        cout << "Account No: ";
        cin >> accNo;
        cout << "Name: ";
        cin >> name;
        cout << "Balance: ";
        cin >> bal;

        acc[i] = new Account(accNo, name, bal);
    }

    int choice, id, i;
    double amt;
    string newName;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Deposit\n";
        cout << "2. Transfer\n";
        cout << "3. Update Name\n";
        cout << "4. Display One Account\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Show Total Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Account No: ";
            cin >> id;
            cout << "Enter amount: ";
            cin >> amt;

            for (i = 0; i < n; i++) {
                if (acc[i]->getAccNo() == id) {
                    acc[i]->deposit(amt);
                    break;
                }
            }
            if (i == n) cout << "Account not found!\n";
            break;

        case 2: {
            int from, to;
            cout << "Enter Sender Account No: ";
            cin >> from;
            cout << "Enter Receiver Account No: ";
            cin >> to;
            cout << "Enter amount: ";
            cin >> amt;

            Account *sender = NULL, *receiver = NULL;

            for (i = 0; i < n; i++) {
                if (acc[i]->getAccNo() == from)
                    sender = acc[i];
                if (acc[i]->getAccNo() == to)
                    receiver = acc[i];
            }

            if (sender && receiver) {
                sender->transfer(*receiver, amt);
            } else {
                cout << "Invalid account(s)!\n";
            }
            break;
        }

        case 3:
            cout << "Enter Account No: ";
            cin >> id;
            cout << "Enter new name: ";
            cin >> newName;

            for (i = 0; i < n; i++) {
                if (acc[i]->getAccNo() == id) {
                    acc[i]->updateName(newName);
                    cout << "Name updated.\n";
                    break;
                }
            }
            if (i == n) cout << "Account not found!\n";
            break;

        case 4:
            cout << "Enter Account No: ";
            cin >> id;

            for (i = 0; i < n; i++) {
                if (acc[i]->getAccNo() == id) {
                    acc[i]->display();
                    break;
                }
            }
            if (i == n) cout << "Account not found!\n";
            break;

        case 5:
            for (i = 0; i < n; i++) {
                acc[i]->display();
            }
            break;

        case 6:
            Account::showTotalAccounts();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);


    for (int i = 0; i < n; i++) {
        delete acc[i];
    }
    delete[] acc;

    return 0;
}
