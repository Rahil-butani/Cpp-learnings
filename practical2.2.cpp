#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[3];
    float average;

public:

    Student() {
        rollNo = 0;
        name = "Test Student";
        marks[0] = 60;
        marks[1] = 70;
        marks[2] = 80;
        calculateAverage();
    }


    Student(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateAverage();
    }


    void calculateAverage() {
        average = (marks[0] + marks[1] + marks[2]) / 3;
    }


    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: "
             << marks[0] << ", "
             << marks[1] << ", "
             << marks[2] << endl;
        cout << "Average Marks: " << average << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;


    Student students[n];


    cout << "\nDefault Student Record:\n";
    students[0].display();


    for (int i = 1; i < n; i++) {
        int roll;
        string name;
        float m1, m2, m3;

        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "Roll Number: ";
        cin >> roll;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter marks in 3 subjects: ";
        cin >> m1 >> m2 >> m3;

        students[i] = Student(roll, name, m1, m2, m3);
    }


    cout << "\nAll Student Records:\n";
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    return 0;
}
