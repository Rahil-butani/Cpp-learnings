#include <iostream>
using namespace std;

class base1
{
public:
    ~base1()
    {
        cout << "base destructor called (non virtual)" << endl;
    }
};

class derived1 : public base1
{
    int *data;
public:
    derived1()
    {
        data = new int[5];
        cout << "derived constructor allocating memory" << endl;
    }
    ~derived1()
    {
        delete[] data;
        cout << "derived destructor releasing memory" << endl;
    }
};

class base2
{
public:
    virtual ~base2()
    {
        cout << "base destructor called (virtual)" << endl;
    }
};

class derived2 : public base2
{
    int *data;
public:
    derived2()
    {
        data = new int[5];
        cout << "derived constructor allocating memory" << endl;
    }
    ~derived2()
    {
        delete[] data;
        cout << "derived destructor releasing memory" << endl;
    }
};

int main()
{
    cout << "case 1: without virtual destructor" << endl;
    base1 *b1 = new derived1();
    delete b1;

    cout << endl;

    cout << "case 2: with virtual destructor" << endl;
    base2 *b2 = new derived2();
    delete b2;

    cout << endl;
    cout << "this code is developed by 25CE011" << endl;

    return 0;
}