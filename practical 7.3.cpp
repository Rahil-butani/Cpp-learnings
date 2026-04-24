#include <iostream>
using namespace std;

class fahrenheit;

class celsius
{
    float c;

public:
    celsius()
    {
        c = 0;
    }

    celsius(float x)
    {
        c = x;
    }

    float get()
    {
        return c;
    }

    operator fahrenheit();

    bool operator==(celsius other)
    {
        return c == other.c;
    }
};

class fahrenheit
{
    float f;

public:
    fahrenheit()
    {
        f = 0;
    }

    fahrenheit(float x)
    {
        f = x;
    }

    float get()
    {
        return f;
    }

    operator celsius()
    {
        return celsius((f - 32) * 5 / 9);
    }

    bool operator==(fahrenheit other)
    {
        return f == other.f;
    }
};

celsius::operator fahrenheit()
{
    return fahrenheit((c * 9 / 5) + 32);
}

int main()
{
    int n;

    cout << "enter number of temperatures for dynamic queue: ";
    cin >> n;

    celsius *queue = new celsius[n];
    int front = 0, rear = -1;

    for(int i = 0; i < n; i++)
    {
        float x;
        cout << "enter celsius value: ";
        cin >> x;
        rear++;
        queue[rear] = celsius(x);
    }

    cout << "processing queue:" << endl;

    while(front <= rear)
    {
        celsius c = queue[front];
        fahrenheit f = c;
        cout << "celsius: " << c.get() << " fahrenheit: " << f.get() << endl;
        front++;
    }

    delete[] queue;

    int m;

    cout << "enter number of temperatures for static array: ";
    cin >> m;

    fahrenheit arr[100];

    for(int i = 0; i < m; i++)
    {
        float x;
        cout << "enter fahrenheit value: ";
        cin >> x;
        arr[i] = fahrenheit(x);
    }

    cout << "converted values:" << endl;

    for(int i = 0; i < m; i++)
    {
        celsius c = arr[i];
        cout << "fahrenheit: " << arr[i].get() << " celsius: " << c.get() << endl;
    }

    int a, b;

    cout << "enter index to compare first: ";
    cin >> a;
    cout << "enter index to compare second: ";
    cin >> b;

    if(a >= 0 && a < m && b >= 0 && b < m)
    {
        if(arr[a] == arr[b])
            cout << "equal" << endl;
        else
            cout << "not equal" << endl;
    }
    else
    {
        cout << "invalid index" << endl;
    }

    cout << "this code is developed by 25ce011";

    return 0;
}