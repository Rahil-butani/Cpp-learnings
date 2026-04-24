#include <iostream>
using namespace std;

class shape
{
protected:
    float radius;

public:
    void setradius(float r)
    {
        radius = r;
    }

    float getradius()
    {
        return radius;
    }
};

class circle : public shape
{
public:
    float area()
    {
        return 3.14159f * radius * radius;
    }
};

int main()
{
    int n;

    cout << "enter number of circles for dynamic method: ";
    cin >> n;

    circle *d = new circle[n];

    for(int i = 0; i < n; i++)
    {
        float r;
        cout << "enter radius: ";
        cin >> r;
        d[i].setradius(r);
    }

    cout << "areas using dynamic method:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "area: " << d[i].area() << endl;
    }

    delete[] d;

    int m;

    cout << "enter number of circles for static method: ";
    cin >> m;

    circle s[100];

    for(int i = 0; i < m; i++)
    {
        float r;
        cout << "enter radius: ";
        cin >> r;
        s[i].setradius(r);
    }

    cout << "areas using static method:" << endl;

    for(int i = 0; i < m; i++)
    {
        cout << "area: " << s[i].area() << endl;
    }

    cout << "this code is developed by 25ce011";

    return 0;
}