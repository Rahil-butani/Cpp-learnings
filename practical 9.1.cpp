#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;

    cout << "enter number of elements" << endl;
    cin >> n;

    vector<int> v;

    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    vector<int> v1 = v;
    vector<int> v2 = v;

    vector<int>::iterator i = v1.begin();
    vector<int>::iterator j = v1.end() - 1;

    while (i < j)
    {
        int temp = *i;
        *i = *j;
        *j = temp;
        i++;
        j--;
    }

    cout << "reversed using method 1" << endl;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        cout << *it << " ";
    cout << endl;

    i = v2.begin();
    j = v2.end() - 1;

    while (i < j)
    {
        int temp = *i;
        *i = *j;
        *j = temp;
        i++;
        j--;
    }

    cout << "reversed using method 2" << endl;
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}