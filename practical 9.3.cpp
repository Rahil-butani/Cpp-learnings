#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n, x;

    cout << "enter number of elements" << endl;
    cin >> n;

    set<int> s;

    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }

    cout << "unique sorted elements using set" << endl;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;

    vector<int> v;

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        v.push_back(*it);

    cout << "elements after converting to vector" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}