#include <iostream>
using namespace std;

class shape
{
public:
    virtual float area() = 0;
    virtual void input() = 0;
    virtual ~shape() {}
};

class rectangle : public shape
{
    float l, w;

public:
    void input()
    {
        cout << "enter length: ";
        cin >> l;
        cout << "enter width: ";
        cin >> w;
    }

    float area()
    {
        return l * w;
    }
};

class circle : public shape
{
    float r;

public:
    void input()
    {
        cout << "enter radius: ";
        cin >> r;
    }

    float area()
    {
        return 3.14159f * r * r;
    }
};

int main()
{
    int n;

    cout << "enter number of shapes for dynamic method: ";
    cin >> n;

    shape **d = new shape*[n];

    for(int i = 0; i < n; i++)
    {
        int type;
        cout << "enter shape type 1 rectangle 2 circle: ";
        cin >> type;

        if(type == 1)
        {
            d[i] = new rectangle();
        }
        else
        {
            d[i] = new circle();
        }

        d[i]->input();
    }

    cout << "areas using dynamic method:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "area: " << d[i]->area() << endl;
    }

    for(int i = 0; i < n; i++)
        delete d[i];
    delete[] d;

    int m;

    cout << "enter number of shapes for static method: ";
    cin >> m;

    shape *s[100];

    for(int i = 0; i < m; i++)
    {
        int type;
        cout << "enter shape type 1 rectangle 2 circle: ";
        cin >> type;

        if(type == 1)
        {
            s[i] = new rectangle();
        }
        else
        {
            s[i] = new circle();
        }

        s[i]->input();
    }

    cout << "areas using static method:" << endl;

    for(int i = 0; i < m; i++)
    {
        cout << "area: " << s[i]->area() << endl;
    }

    cout << "this code is developed by 25ce011";

    for(int i = 0; i < m; i++)
        delete s[i];

    return 0;
}