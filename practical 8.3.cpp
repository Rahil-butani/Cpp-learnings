#include <iostream>
using namespace std;

string logs[100];
int idx = 0;

void addlog(string s)
{
    logs[idx++] = s;
}

class BankAccount
{
    double balance;
public:
    BankAccount(double b)
    {
        balance = b;
        addlog("constructor called");
    }

    void deposit(double amt)
    {
        addlog("enter deposit");
        if (amt <= 0)
            throw "invalid deposit amount";
        balance += amt;
        addlog("deposit successful");
        addlog("exit deposit");
    }

    void withdraw(double amt)
    {
        addlog("enter withdraw");
        if (amt <= 0)
            throw "invalid withdraw amount";
        if (amt > balance)
            throw "insufficient balance";
        balance -= amt;
        addlog("withdraw successful");
        addlog("exit withdraw");
    }

    double getbalance()
    {
        addlog("get balance");
        return balance;
    }
};

void performDeposit(BankAccount &acc, double amt)
{
    addlog("enter performdeposit");
    acc.deposit(amt);
    addlog("exit performdeposit");
}

void performWithdraw(BankAccount &acc, double amt)
{
    addlog("enter performwithdraw");
    acc.withdraw(amt);
    addlog("exit performwithdraw");
}

int main()
{
    double bal, dep, wit;

    cout << "enter initial balance" << endl;
    cin >> bal;

    cout << "enter deposit amount" << endl;
    cin >> dep;

    cout << "enter withdraw amount" << endl;
    cin >> wit;

    BankAccount acc(bal);

    try
    {
        performDeposit(acc, dep);
        performWithdraw(acc, wit);
    }
    catch (const char *msg)
    {
        addlog("exception caught");
        cout << msg << endl;
    }

    cout << "final balance = " << acc.getbalance() << endl;

    cout << "transaction logs" << endl;
    for (int i = 0; i < idx; i++)
        cout << logs[i] << endl;

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}