#include <iostream>
using namespace std;

ostream& currency(ostream& out)
{
    out << "rs ";
    return out;
}

int main()
{
    int n;

    cout << "enter number of students: ";
    cin >> n;

    string name[100];
    float marks[100];
    float fees[100];

    for(int i = 0; i < n; i++)
    {
        cout << "enter student name: ";
        cin >> name[i];

        cout << "enter marks: ";
        cin >> marks[i];

        cout << "enter fees: ";
        cin >> fees[i];
    }

    cout << "name\tmarks\tfees" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << name[i] << "\t" << marks[i] << "\t" << currency << fees[i] << endl;
    }

    cout << "this code is developed by 25ce011";

    return 0;
}