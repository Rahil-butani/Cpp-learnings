#include <iostream>
#include <string>
using namespace std;

string tolowercase(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
    return s;
}

int main()
{
    string paragraph;

    cout << "enter a complete paragraph: ";
    getline(cin, paragraph);

    string words[1000];
    int count[1000];

    int n = 0;

    for(int i = 0; i < paragraph.length();)
    {
        while(i < paragraph.length() && paragraph[i] == ' ')
            i++;

        string word = "";

        while(i < paragraph.length() && paragraph[i] != ' ')
        {
            word += paragraph[i];
            i++;
        }

        if(word.length() > 0)
        {
            word = tolowercase(word);

            int found = -1;

            for(int j = 0; j < n; j++)
            {
                if(words[j] == word)
                {
                    found = j;
                    break;
                }
            }

            if(found == -1)
            {
                words[n] = word;
                count[n] = 1;
                n++;
            }
            else
            {
                count[found]++;
            }
        }
    }

    cout << "word frequencies:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << words[i] << " " << count[i] << endl;
    }
    cout<< "program developed by 25CE011";

    return 0;
}