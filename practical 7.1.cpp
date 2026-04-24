#include <iostream>
using namespace std;

class calculator
{
    float results[100];
    int count;

public:
    calculator()
    {
        count = 0;
    }

    int add(int a, int b)
    {
        int r = a + b;
        results[count++] = r;
        return r;
    }

    float add(float a, float b)
    {
        float r = a + b;
        results[count++] = r;
        return r;
    }

    float add(int a, float b)
    {
        float r = a + b;
        results[count++] = r;
        return r;
    }

    float add(float a, int b)
    {
        float r = a + b;
        results[count++] = r;
        return r;
    }

    void display()
    {
        cout << "results:" << endl;
        for(int i = 0; i < count; i++)
            cout << results[i] << endl;
    }
};

int main()
{
    calculator c;

    int choice;

    do
    {
        cout << "1 add int int" << endl;
        cout << "2 add float float" << endl;
        cout << "3 add int float" << endl;
        cout << "4 add float int" << endl;
        cout << "5 display results" << endl;
        cout << "6 exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            int a, b;
            cout << "enter first integer: ";
            cin >> a;
            cout << "enter second integer: ";
            cin >> b;
            cout << "result: " << c.add(a, b) << endl;
        }
        else if(choice == 2)
        {
            float a, b;
            cout << "enter first float: ";
            cin >> a;
            cout << "enter second float: ";
            cin >> b;
            cout << "result: " << c.add(a, b) << endl;
        }
        else if(choice == 3)
        {
            int a;
            float b;
            cout << "enter integer: ";
            cin >> a;
            cout << "enter float: ";
            cin >> b;
            cout << "result: " << c.add(a, b) << endl;
        }
        else if(choice == 4)
        {
            float a;
            int b;
            cout << "enter float: ";
            cin >> a;
            cout << "enter integer: ";
            cin >> b;
            cout << "result: " << c.add(a, b) << endl;
        }
        else if(choice == 5)
        {
            c.display();
        }

    } while(choice != 6);

    cout << "this code is developed by 25ce011";

    return 0;
}