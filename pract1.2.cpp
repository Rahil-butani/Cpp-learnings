#include <iostream>
using namespace std;

class book {
public:
    int id;
    string title;
    string author;
    int copies;

    void input() {
        cout << "enter id: ";
        cin >> id;
        cout << "enter title: ";
        cin >> title;
        cout << "enter author: ";
        cin >> author;
        cout << "enter copies: ";
        cin >> copies;
    }

    void issue() {
        if(copies > 0) {
            copies--;
            cout << "book issued\n";
        } else {
            cout << "no copies available\n";
        }
    }

    void ret() {
        copies++;
        cout << "book returned\n";
    }
};

int main() {
    book b[100];
    int n, x, t = 0;

    cout << "enter number of books: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\nbook " << i+1 << endl;
        b[i].input();
    }

    cout << "\nenter book id to issue: ";
    cin >> x;
    for(int i = 0; i < n; i++) {
        if(b[i].id == x) {
            b[i].issue();
        }
    }

    cout << "\nenter book id to return: ";
    cin >> x;
    for(int i = 0; i < n; i++) {
        if(b[i].id == x) {
            b[i].ret();
        }
    }

    for(int i = 0; i < n; i++) {
        t += b[i].copies;
    }

    cout << "\ntotal books: " << t << endl;

    return 0;
}
