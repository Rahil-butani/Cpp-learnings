#include <iostream>
#include <string>
using namespace std;

class person
{
protected:
    string name;
    int age;

public:
    person(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayperson()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
    }
};

class employee : public person
{
protected:
    int empid;

public:
    employee(string n, int a, int id) : person(n, a)
    {
        empid = id;
    }

    void displayemployee()
    {
        displayperson();
        cout << "employee id: " << empid << endl;
    }

    int getid()
    {
        return empid;
    }
};

class manager : public employee
{
    string department;

public:
    manager(string n, int a, int id, string d) : employee(n, a, id)
    {
        department = d;
    }

    void displaymanager()
    {
        displayemployee();
        cout << "department: " << department << endl;
    }
};

int main()
{
    int n;

    cout << "enter number of managers for dynamic method: ";
    cin >> n;

    manager **d = new manager*[n];

    for(int i = 0; i < n; i++)
    {
        string name, dept;
        int age, id;

        cout << "enter name: ";
        cin >> name;

        cout << "enter age: ";
        cin >> age;

        cout << "enter employee id: ";
        cin >> id;

        cout << "enter department: ";
        cin >> dept;

        d[i] = new manager(name, age, id, dept);
    }

    cout << "display all managers dynamic:" << endl;

    for(int i = 0; i < n; i++)
    {
        d[i]->displaymanager();
    }

    int searchid;
    cout << "enter employee id to search: ";
    cin >> searchid;

    int found = 0;

    for(int i = 0; i < n; i++)
    {
        if(d[i]->getid() == searchid)
        {
            d[i]->displaymanager();
            found = 1;
        }
    }

    if(found == 0)
        cout << "not found" << endl;

    for(int i = 0; i < n; i++)
        delete d[i];
    delete[] d;

    int m;

    cout << "enter number of managers for static method: ";
    cin >> m;

    manager *s[100];

    for(int i = 0; i < m; i++)
    {
        string name, dept;
        int age, id;

        cout << "enter name: ";
        cin >> name;

        cout << "enter age: ";
        cin >> age;

        cout << "enter employee id: ";
        cin >> id;

        cout << "enter department: ";
        cin >> dept;

        s[i] = new manager(name, age, id, dept);
    }

    cout << "display all managers static:" << endl;

    for(int i = 0; i < m; i++)
    {
        s[i]->displaymanager();
    }

    cout << "this code is developed by 25ce011";

    for(int i = 0; i < m; i++)
        delete s[i];

    return 0;
}