#include <iostream>
using namespace std;

class complexnum
{
    float real;
    float imag;

public:
    complexnum()
    {
        real = 0;
        imag = 0;
    }

    complexnum(float r, float i)
    {
        real = r;
        imag = i;
    }

    complexnum operator+(complexnum c)
    {
        return complexnum(real + c.real, imag + c.imag);
    }

    complexnum operator-(complexnum c)
    {
        return complexnum(real - c.real, imag - c.imag);
    }

    void display()
    {
        if(imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main()
{
    int n;

    cout << "enter number of complex numbers: ";
    cin >> n;

    complexnum arr[100];

    for(int i = 0; i < n; i++)
    {
        float r, im;
        cout << "enter real part: ";
        cin >> r;
        cout << "enter imaginary part: ";
        cin >> im;
        arr[i] = complexnum(r, im);
    }

    int choice;

    do
    {
        cout << "1 add two complex numbers" << endl;
        cout << "2 subtract two complex numbers" << endl;
        cout << "3 display all complex numbers" << endl;
        cout << "4 exit" << endl;
        cout << "enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            int a, b;
            cout << "enter index of first complex number: ";
            cin >> a;
            cout << "enter index of second complex number: ";
            cin >> b;

            if(a >= 0 && a < n && b >= 0 && b < n)
            {
                complexnum res = arr[a] + arr[b];
                cout << "result: ";
                res.display();
            }
            else
            {
                cout << "invalid index" << endl;
            }
        }
        else if(choice == 2)
        {
            int a, b;
            cout << "enter index of first complex number: ";
            cin >> a;
            cout << "enter index of second complex number: ";
            cin >> b;

            if(a >= 0 && a < n && b >= 0 && b < n)
            {
                complexnum res = arr[a] - arr[b];
                cout << "result: ";
                res.display();
            }
            else
            {
                cout << "invalid index" << endl;
            }
        }
        else if(choice == 3)
        {
            for(int i = 0; i < n; i++)
            {
                cout << i << ": ";
                arr[i].display();
            }
        }

    } while(choice != 4);

    cout << "this code is developed by 25ce011";

    return 0;
}