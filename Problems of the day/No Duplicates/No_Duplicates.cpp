#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    string word;
    map<string, int> wordsCount;
    while (cin >> word)
    {
        if (wordsCount.find(word) == wordsCount.end())
            wordsCount[word] = 1;
        else
            wordsCount[word]++;

        if (wordsCount[word] > 1)
        {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}