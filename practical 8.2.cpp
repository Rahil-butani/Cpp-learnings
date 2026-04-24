#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException
{
};

int main()
{
    double n;

    cout << "enter a number to calculate square root" << endl;

    try
    {
        if (!(cin >> n))
            throw "invalid input";

        if (n < 0)
            throw NegativeNumberException();

        cout << "square root = " << sqrt(n) << endl;
    }
    catch (NegativeNumberException)
    {
        cout << "negative number exception" << endl;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}