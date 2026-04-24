#include <iostream>
#include <string>
using namespace std;

class account
{
protected:
    int accno;
    float balance;
    string history[100];
    int top;

public:
    account(int a, float b)
    {
        accno = a;
        balance = b;
        top = -1;
    }

    ~account() {}

    void deposit(float amt)
    {
        balance += amt;
        top++;
        history[top] = "deposit " + to_string(amt);
    }

    void withdraw(float amt)
    {
        if(amt <= balance)
        {
            balance -= amt;
            top++;
            history[top] = "withdraw " + to_string(amt);
        }
        else
        {
            cout << "insufficient balance" << endl;
        }
    }

    void undo()
    {
        if(top < 0)
        {
            cout << "no transaction" << endl;
            return;
        }

        string t = history[top];
        top--;

        string type = "";
        string num = "";

        for(int i = 0; i < t.length(); i++)
        {
            if(t[i] == ' ')
                break;
            type += t[i];
        }

        for(int i = type.length() + 1; i < t.length(); i++)
            num += t[i];

        float amt = stof(num);

        if(type == "deposit")
            balance -= amt;
        else if(type == "withdraw")
            balance += amt;
    }

    void display()
    {
        cout << "account number: " << accno << endl;
        cout << "balance: " << balance << endl;
    }

    void showhistory()
    {
        cout << "transaction history:" << endl;
        for(int i = 0; i <= top; i++)
            cout << history[i] << endl;
    }
};

class savings : public account
{
    float rate;

public:
    savings(int a, float b, float r) : account(a, b)
    {
        rate = r;
    }

    ~savings() {}

    void displaysavings()
    {
        display();
        cout << "interest rate: " << rate << endl;
    }
};

class current : public account
{
    float limit;

public:
    current(int a, float b, float l) : account(a, b)
    {
        limit = l;
    }

    ~current() {}

    void withdraw(float amt)
    {
        if(amt <= balance + limit)
        {
            balance -= amt;
            top++;
            history[top] = "withdraw " + to_string(amt);
        }
        else
        {
            cout << "limit exceeded" << endl;
        }
    }

    void displaycurrent()
    {
        display();
        cout << "overdraft limit: " << limit << endl;
    }
};

int main()
{
    int choice;

    cout << "enter account type 1 savings 2 current: ";
    cin >> choice;

    if(choice == 1)
    {
        int acc;
        float bal, rate;

        cout << "enter account number: ";
        cin >> acc;

        cout << "enter initial balance: ";
        cin >> bal;

        cout << "enter interest rate: ";
        cin >> rate;

        savings s(acc, bal, rate);

        int ch;
        do
        {
            cout << "1 deposit" << endl;
            cout << "2 withdraw" << endl;
            cout << "3 display" << endl;
            cout << "4 history" << endl;
            cout << "5 undo" << endl;
            cout << "6 exit" << endl;
            cout << "enter choice: ";
            cin >> ch;

            if(ch == 1)
            {
                float amt;
                cout << "enter amount: ";
                cin >> amt;
                s.deposit(amt);
            }
            else if(ch == 2)
            {
                float amt;
                cout << "enter amount: ";
                cin >> amt;
                s.withdraw(amt);
            }
            else if(ch == 3)
            {
                s.displaysavings();
            }
            else if(ch == 4)
            {
                s.showhistory();
            }
            else if(ch == 5)
            {
                s.undo();
            }

        } while(ch != 6);
    }
    else if(choice == 2)
    {
        int acc;
        float bal, limit;

        cout << "enter account number: ";
        cin >> acc;

        cout << "enter initial balance: ";
        cin >> bal;

        cout << "enter overdraft limit: ";
        cin >> limit;

        current c(acc, bal, limit);

        int ch;
        do
        {
            cout << "1 deposit" << endl;
            cout << "2 withdraw" << endl;
            cout << "3 display" << endl;
            cout << "4 history" << endl;
            cout << "5 undo" << endl;
            cout << "6 exit" << endl;
            cout << "enter choice: ";
            cin >> ch;

            if(ch == 1)
            {
                float amt;
                cout << "enter amount: ";
                cin >> amt;
                c.deposit(amt);
            }
            else if(ch == 2)
            {
                float amt;
                cout << "enter amount: ";
                cin >> amt;
                c.withdraw(amt);
            }
            else if(ch == 3)
            {
                c.displaycurrent();
            }
            else if(ch == 4)
            {
                c.showhistory();
            }
            else if(ch == 5)
            {
                c.undo();
            }

        } while(ch != 6);
    }

    cout << "this code is developed by 25ce011";

    return 0;
}