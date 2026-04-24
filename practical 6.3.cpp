#include <iostream>
#include <string>
using namespace std;

class fuel
{
protected:
    string fueltype;

public:
    fuel(string f)
    {
        fueltype = f;
    }

    void displayfuel()
    {
        cout << "fuel type: " << fueltype << endl;
    }
};

class brand
{
protected:
    string brandname;

public:
    brand(string b)
    {
        brandname = b;
    }

    void displaybrand()
    {
        cout << "brand name: " << brandname << endl;
    }
};

class car : public fuel, public brand
{
public:
    car(string f, string b) : fuel(f), brand(b) {}

    void displaycar()
    {
        displaybrand();
        displayfuel();
    }
};

int main()
{
    int n;

    cout << "enter number of cars for dynamic method: ";
    cin >> n;

    car **d = new car*[n];

    for(int i = 0; i < n; i++)
    {
        string f, b;

        cout << "enter fuel type: ";
        cin >> f;

        cout << "enter brand name: ";
        cin >> b;

        d[i] = new car(f, b);
    }

    cout << "display cars dynamic:" << endl;

    for(int i = 0; i < n; i++)
    {
        d[i]->displaycar();
    }

    for(int i = 0; i < n; i++)
        delete d[i];
    delete[] d;

    int m;

    cout << "enter number of cars for static method: ";
    cin >> m;

    car *s[100];

    for(int i = 0; i < m; i++)
    {
        string f, b;

        cout << "enter fuel type: ";
        cin >> f;

        cout << "enter brand name: ";
        cin >> b;

        s[i] = new car(f, b);
    }

    cout << "display cars static:" << endl;

    for(int i = 0; i < m; i++)
    {
        s[i]->displaycar();
    }

    cout << "this code is developed by 25ce011";

    for(int i = 0; i < m; i++)
        delete s[i];

    return 0;
}