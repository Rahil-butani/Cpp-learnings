#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    map<string, vector<string> > dir;
    int choice;
    string folder, file;

    while (true)
    {
        cout << "1 add folder" << endl;
        cout << "2 add file to folder" << endl;
        cout << "3 display directory" << endl;
        cout << "4 exit" << endl;
        cout << "enter choice" << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "enter folder name" << endl;
            cin >> folder;
            dir[folder];
        }
        else if (choice == 2)
        {
            cout << "enter folder name" << endl;
            cin >> folder;
            if (dir.find(folder) == dir.end())
            {
                cout << "folder not found" << endl;
            }
            else
            {
                cout << "enter file name" << endl;
                cin >> file;
                dir[folder].push_back(file);
            }
        }
        else if (choice == 3)
        {
            cout << "directory contents" << endl;
            for (map<string, vector<string> >::iterator it = dir.begin(); it != dir.end(); it++)
            {
                cout << it->first << endl;
                for (vector<string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
                    cout << *jt << " ";
                cout << endl;
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "invalid choice" << endl;
        }
    }

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}