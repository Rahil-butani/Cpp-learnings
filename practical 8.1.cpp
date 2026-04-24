#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "enter two integers for division" << endl;

    try
    {
        if (!(cin >> a))
            throw "invalid input";

        if (!(cin >> b))
            throw "invalid input";

        if (b == 0)
            throw "division by zero";

        cout << "result = " << (a / b) << endl;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}