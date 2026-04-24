#include <iostream>
using namespace std;

int main()
{
    int *arr = nullptr;
    int size = 0;
    int choice;

    do
    {
        cout << "1 insert an element at the end" << endl;
        cout << "2 delete an element from a specified position" << endl;
        cout << "3 display the current array contents" << endl;
        cout << "4 exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            int value;
            cout << "enter element to insert: ";
            cin >> value;

            int *newarr = new int[size + 1];

            for(int i = 0; i < size; i++)
                newarr[i] = arr[i];

            newarr[size] = value;

            delete[] arr;
            arr = newarr;
            size++;
        }
        else if(choice == 2)
        {
            if(size == 0)
            {
                cout << "array is empty" << endl;
                continue;
            }

            int pos;
            cout << "enter position to delete: ";
            cin >> pos;

            if(pos < 1 || pos > size)
            {
                cout << "invalid position" << endl;
                continue;
            }

            int *newarr = new int[size - 1];

            for(int i = 0, j = 0; i < size; i++)
            {
                if(i != pos - 1)
                {
                    newarr[j] = arr[i];
                    j++;
                }
            }

            delete[] arr;
            arr = newarr;
            size--;
        }
        else if(choice == 3)
        {
            if(size == 0)
            {
                cout << "array is empty" << endl;
            }
            else
            {
                cout << "array elements: ";
                for(int i = 0; i < size; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
        }

    } while(choice != 4);

    delete[] arr;
    cout<< "code written by 25CE011";
    return 0;
}