#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename;

    cout << "enter file name: ";
    cin >> filename;

    ifstream file(filename.c_str());

    if(!file)
    {
        cout << "error opening file";
        return 0;
    }

    string line;
    int lines = 0;
    int words = 0;
    int chars = 0;

    while(getline(file, line))
    {
        lines++;

        for(int i = 0; i < line.length(); i++)
        {
            chars++;

            if(i == 0 && line[i] != ' ')
                words++;
            else if(i > 0 && line[i] != ' ' && line[i - 1] == ' ')
                words++;
        }
    }

    cout << "lines: " << lines << endl;
    cout << "words: " << words << endl;
    cout << "characters: " << chars << endl;

    file.close();
    
    cout<< "program developed by 25CE011";

    return 0;
}