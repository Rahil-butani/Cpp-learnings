#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    string path;
    ifstream file;

    while (true)
    {
        cout << "enter file path or type exit to quit" << endl;
        cin >> path;

        if (path == "exit")
            return 0;

        file.open(path);

        if (!file)
        {
            cout << "file not found or cannot be opened" << endl;
            continue;
        }
        break;
    }

    string line;
    int lineno = 0;

    while (getline(file, line))
    {
        lineno++;
        istringstream iss(line);
        double num, sum = 0;
        int count = 0;
        bool valid = true;
        string token;

        while (iss >> token)
        {
            istringstream check(token);
            if (!(check >> num))
            {
                valid = false;
                break;
            }
            sum += num;
            count++;
        }

        if (!valid || count == 0)
        {
            cout << "invalid data at line " << lineno << endl;
            continue;
        }

        cout << "line " << lineno << " sum = " << sum << " average = " << (sum / count) << endl;
    }

    file.close();

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}