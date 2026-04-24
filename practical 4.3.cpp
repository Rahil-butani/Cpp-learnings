#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cout << "enter size of first sorted array: ";
    cin >> n;

    cout << "enter size of second sorted array: ";
    cin >> m;

    int *a = new int[n];
    int *b = new int[m];

    cout << "enter elements of first sorted array: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "enter elements of second sorted array: ";
    for(int i = 0; i < m; i++)
        cin >> b[i];

    int *c = new int[n + m];

    int i = 0, j = 0, k = 0;

    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while(j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    cout << "merged sorted array: ";
    for(int i = 0; i < n + m; i++)
        cout << c[i] << " ";

    delete[] a;
    delete[] b;
    delete[] c;
cout<< "program developed by 25CE011";
    return 0;
}