#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    string sentence, word;

    cout << "enter a sentence" << endl;
    getline(cin, sentence);

    map<string, int> freq;

    istringstream iss(sentence);

    while (iss >> word)
    {
        freq[word]++;
    }

    cout << "word frequencies" << endl;

    for (map<string, int>::iterator it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "this code is developed by 25ce011" << endl;

    return 0;
}