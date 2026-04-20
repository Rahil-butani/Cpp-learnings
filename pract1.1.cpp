#include <iostream>
using namespace std;

class wallet {
public:
    int id;
    string name;
    double bal;

    void load(double amt) {
        bal += amt;
    }

    void send(wallet &w, double amt) {
        if (amt > bal) {
            cout << "not enough balance\n";
            return;
        }
        bal -= amt;
        w.bal += amt;
    }

    void show() {
        cout << "id: " << id << endl;
        cout << "name: " << name << endl;
        cout << "balance: " << bal << endl;
    }
};

int main() {
    wallet w1, w2;
    double amt;

    cout << "enter wallet 1 id: ";
    cin >> w1.id;
    cout << "enter wallet 1 name: ";
    cin >> w1.name;
    cout << "enter wallet 1 balance: ";
    cin >> w1.bal;

    cout << "enter wallet 2 id: ";
    cin >> w2.id;
    cout << "enter wallet 2 name: ";
    cin >> w2.name;
    cout << "enter wallet 2 balance: ";
    cin >> w2.bal;

    cout << "enter amount to load in wallet 1: ";
    cin >> amt;
    w1.load(amt);

    cout << "enter amount to transfer from wallet 1 to wallet 2: ";
    cin >> amt;
    w1.send(w2, amt);

    w1.show();
    w2.show();

    return 0;
}
