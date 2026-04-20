#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:

    void setDimensions(double l, double w) {
        if (l > 0 && w > 0) {
            length = l;
            width = w;
            cout << "Dimensions updated successfully.\n";
        } else {
            cout << "Invalid dimensions!\n";
        }
    }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (length + width);
    }

    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of rectangles: ";
    cin >> n;

    Rectangle rect[n];

    for (int i = 0; i < n; i++) {
        double l, w;
        cout << "\nRectangle " << i + 1 << endl;
        cout << "Enter length: ";
        cin >> l;
        cout << "Enter width: ";
        cin >> w;
        rect[i].setDimensions(l, w);
    }

    int choice, index;
    double l, w;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Update Rectangle Dimensions\n";
        cout << "2. Display One Rectangle\n";
        cout << "3. Display All Rectangles\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter rectangle number (1 to " << n << "): ";
            cin >> index;
            if (index >= 1 && index <= n) {
                cout << "Enter new length: ";
                cin >> l;
                cout << "Enter new width: ";
                cin >> w;
                rect[index - 1].setDimensions(l, w);
            } else {
                cout << "Invalid rectangle number!\n";
            }
            break;

        case 2:
            cout << "Enter rectangle number: ";
            cin >> index;
            if (index >= 1 && index <= n) {
                rect[index - 1].display();
            } else {
                cout << "Invalid rectangle number!\n";
            }
            break;

        case 3:
            for (int i = 0; i < n; i++) {
                cout << "\nRectangle " << i + 1 << endl;
                rect[i].display();
            }
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
