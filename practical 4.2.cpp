#include <iostream>
using namespace std;

class point
{
    int x, y;

public:
    void input()
    {
        cout << "enter x coordinate: ";
        cin >> x;
        cout << "enter y coordinate: ";
        cin >> y;
    }

    point& move(int dx, int dy)
    {
        x += dx;
        y += dy;
        return *this;
    }

    void display()
    {
        cout << "point: " << x << " " << y << endl;
    }
};

void update(point *p)
{
    int dx, dy;
    cout << "enter dx for update: ";
    cin >> dx;
    cout << "enter dy for update: ";
    cin >> dy;
    p->move(dx, dy);
}

int main()
{
    point p;

    p.input();

    int dx1, dy1, dx2, dy2;

    cout << "enter dx and dy for first move: ";
    cin >> dx1 >> dy1;

    cout << "enter dx and dy for second move: ";
    cin >> dx2 >> dy2;

    p.move(dx1, dy1).move(dx2, dy2);

    p.display();

    update(&p);

    p.display();

    
    cout <<"program developed by 25CE011";
    return 0;
}