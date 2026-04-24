#include <iostream>
#include <string>
using namespace std;

class grading
{
protected:
    float marks;

public:
    virtual void input() = 0;
    virtual char computegade() = 0;
    virtual void display() = 0;
    virtual ~grading() {}
};

class undergraduate : public grading
{
    string name;
    char grade;

public:
    void input()
    {
        cout << "enter student name: ";
        cin >> name;
        cout << "enter marks: ";
        cin >> marks;
    }

    char computegade()
    {
        if(marks >= 80) grade = 'a';
        else if(marks >= 60) grade = 'b';
        else if(marks >= 50) grade = 'c';
        else if(marks >= 40) grade = 'd';
        else grade = 'f';
        return grade;
    }

    void display()
    {
        cout << "name: " << name << endl;
        cout << "marks: " << marks << endl;
        cout << "grade: " << grade << endl;
    }
};

class postgraduate : public grading
{
    string name;
    char grade;

public:
    void input()
    {
        cout << "enter student name: ";
        cin >> name;
        cout << "enter marks: ";
        cin >> marks;
    }

    char computegade()
    {
        if(marks >= 85) grade = 'a';
        else if(marks >= 70) grade = 'b';
        else if(marks >= 60) grade = 'c';
        else if(marks >= 50) grade = 'd';
        else grade = 'f';
        return grade;
    }

    void display()
    {
        cout << "name: " << name << endl;
        cout << "marks: " << marks << endl;
        cout << "grade: " << grade << endl;
    }
};

int main()
{
    int n;

    cout << "enter number of students: ";
    cin >> n;

    grading *students[100];

    for(int i = 0; i < n; i++)
    {
        int type;
        cout << "enter type 1 undergraduate 2 postgraduate: ";
        cin >> type;

        if(type == 1)
            students[i] = new undergraduate();
        else
            students[i] = new postgraduate();

        students[i]->input();
        students[i]->computegade();
    }

    cout << "student records:" << endl;

    for(int i = 0; i < n; i++)
    {
        students[i]->display();
    }

    for(int i = 0; i < n; i++)
        delete students[i];

    cout << "this code is developed by 25ce011";

    return 0;
}